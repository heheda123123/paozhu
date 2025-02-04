add_rules("mode.debug", "mode.release")
add_requires("boost", "libgd", "mysql", "asio", "zlib", "brotli", "libqrencode", "libpng", "freetype", "openssl")

set_languages("c++20")
set_encodings("utf-8")

if is_plat("windows") then 
    add_defines("WIN32")
    add_defines("WIN32_LEAN_AND_MEAN")
    add_defines("DEBUG")
end

add_includedirs("common")
add_includedirs("controller")
add_includedirs("vendor/httpcli")
add_includedirs("viewsrc/include")
add_includedirs("websockets/include")
add_includedirs("vendor/httpserver/include")
add_includedirs("vendor/httpserver/include/utility")
add_includedirs("orm")
add_includedirs("models/cms/include")
add_includedirs("models")
add_includedirs("controller/include")
add_includedirs("controller/include/admin")
add_includedirs("libs")
add_includedirs("libs/department")
add_includedirs("libs/img")
add_includedirs("libs/types")

target("paozhu_pre")
    set_kind("binary")
    add_files("vendor/httpcli/autopickmethod.cpp")
    add_files("vendor/httpserver/src/md5.cpp")

target("paozhu")
    set_kind("binary")
    add_deps("paozhu_pre")
    add_packages("boost")
    add_packages("asio")
    add_packages("openssl")
    add_packages("zlib")
    add_packages("libgd")
    add_packages("libqrencode")
    add_packages("libpng")
    add_packages("freetype")
    add_packages("mysql")
    add_packages("brotli")
    add_files("models/**.cpp")
    add_files("vendor/httpserver/**.cpp")
    add_files("common/**.cpp")
    add_files("controller/src/**.cpp")
    add_files("viewsrc/view/**.cpp")
    add_files("libs/**.cpp")
    add_files("test/test.cpp")

    on_load(function (target)
        if is_plat("linux", "macosx") then
            target:add("links", "pthread")
        elseif is_plat("windows") then
            target:add("links", "ws2_32")
        end
    end)

target("paozhu_empty")
    set_kind("binary")
    add_files("vendor/httpcli/autoemptymethod.cpp")
    add_deps("paozhu_pre")

target("paozhu_cli")
    set_kind("binary")
    add_files("vendor/httpcli/http_cli.cpp")
    add_packages("mysql")
