#ifndef ORM_CMS_USERBASEMATA_H
#define ORM_CMS_USERBASEMATA_H
/*
*This file is auto create from cli
*本文件为自动生成 Sun, 11 Dec 2022 08:12:37 GMT
***/
#include <iostream>
#include <cstdio>
#include <sstream>
#include <array>
#include <map> 
#include <string_view> 
#include <string> 
#include <vector>
#include <ctime>
#include <array>
#include <sys/time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <mysqlx/xdevapi.h> 
namespace orm { 
     namespace cms { 

struct userbase
{
    struct meta{
    unsigned  int userid= 0; //
 std::string name; //
 std::string password; //
 char isopen=0; //
 int level= 0; //
 } data;
 std::vector<userbase::meta> record;
std::string _rmstag="cms";//this value must be default or tag value, tag in mysqlconnect config file .
std::vector<unsigned char> _keypos{0x00};
mysqlx::Row _row;
std::vector<userbase::meta>::iterator begin(){     return record.begin(); }
std::vector<userbase::meta>::iterator end(){     return record.end(); }
std::vector<userbase::meta>::const_iterator begin() const{     return record.begin(); }
std::vector<userbase::meta>::const_iterator end() const{     return record.end(); }
const std::array<std::string,5> colnames={"userid","name","password","isopen","level"};
const std::array<unsigned char,5> colnamestype= {1,30,30,1,1};
std::string tablename="user";
std::string modelname="User";

	  unsigned char findcolpos(std::string coln){
		    unsigned char  bi=coln[0];
            char colpospppc;
	         if(bi<91&&bi>64){
				bi+=32;
			}
            switch(coln[0]){


         case 'i':
   	 return 3;
break;
case 'l':
   	 return 4;
break;
case 'n':
   	 return 1;
break;
case 'p':
   	 return 2;
break;
case 'u':
   	 return 0;
break;

             }
             return 255;
           }
         
    int size(){ return record.size(); }   

    std::string getPKname(){ 
       return "userid";
}

      void _setColnamevalue(){
          userbase::meta metatemp;   
         for(unsigned char i=0;i<_keypos.size();i++){
                 switch(_keypos[i]){
        		case 0: 
 
	 if(_row[i].getType()==mysqlx::Value::Type::INT64||_row[i].getType()==mysqlx::Value::Type::UINT64){ 
				 metatemp.userid=_row[i].get<unsigned>();
		 } 
			 break;
		case 1: 
 
	 if(_row[i].getType()==mysqlx::Value::Type::STRING){ 
				 metatemp.name=(std::string)_row[i];
		 } 
			 break;
		case 2: 
 
	 if(_row[i].getType()==mysqlx::Value::Type::STRING){ 
				 metatemp.password=(std::string)_row[i];
		 } 
			 break;
		case 3: 
 
	 if(_row[i].getType()==mysqlx::Value::Type::INT64||_row[i].getType()==mysqlx::Value::Type::UINT64){ 
				 metatemp.isopen=_row[i].get<unsigned>();
		 } 
			 break;
		case 4: 
 
	 if(_row[i].getType()==mysqlx::Value::Type::INT64||_row[i].getType()==mysqlx::Value::Type::UINT64){ 
				 metatemp.level=_row[i].get<unsigned>();
		 } 
			 break;

                 }

                 if(i>210){
                     break;
                 }
          }
          data=metatemp;
          record.emplace_back(metatemp);   
   } 
         void _addnewrowvalue(){
           userbase::meta metatemp;   

          for(unsigned char i=0;i<_keypos.size();i++){
 
                 switch(_keypos[i]){

        		case 0: 
 
	 if(_row[i].getType()==mysqlx::Value::Type::INT64||_row[i].getType()==mysqlx::Value::Type::UINT64){ 
				 metatemp.userid=_row[i].get<unsigned>();
		 } 
			 break;
		case 1: 
 
	 if(_row[i].getType()==mysqlx::Value::Type::STRING){ 
				 metatemp.name=(std::string)_row[i];
		 } 
			 break;
		case 2: 
 
	 if(_row[i].getType()==mysqlx::Value::Type::STRING){ 
				 metatemp.password=(std::string)_row[i];
		 } 
			 break;
		case 3: 
 
	 if(_row[i].getType()==mysqlx::Value::Type::INT64||_row[i].getType()==mysqlx::Value::Type::UINT64){ 
				 metatemp.isopen=_row[i].get<unsigned>();
		 } 
			 break;
		case 4: 
 
	 if(_row[i].getType()==mysqlx::Value::Type::INT64||_row[i].getType()==mysqlx::Value::Type::UINT64){ 
				 metatemp.level=_row[i].get<unsigned>();
		 } 
			 break;

                  }
                 if(i>210){
                     break;
                 }
          }
           record.emplace_back(std::move(metatemp)); 
   } 

  inline  std::string stringaddslash(std::string &content){
        std::string temp;
        for(int i=0;i<content.size();i++){
            if(content[i]=='\''){
                temp.append("\\'");
                continue;
            }else if(content[i]=='"'){
                temp.append("\\\"");
                continue;
            }
            temp.push_back(content[i]);
        }
        return std::move(temp);
   }  
  inline  std::string jsonaddslash(std::string &content){
        std::string temp;
        for(int i=0;i<content.size();i++){
            if(content[i]=='"'){
                temp.append("\\\"");
                continue;
            }
            temp.push_back(content[i]);
        }
        return std::move(temp);
   }  

   std::string _makeinsertsql(){
       int j=0;
                std::ostringstream tempsql;
                tempsql<<"INSERT INTO ";
                    tempsql<<tablename;
                   tempsql<<" (";
                    for(;j<colnames.size();j++){
                            if(j>0){
                                tempsql<<"`,`";
                            }else{
                                tempsql<<"`";
                            }
                            tempsql<<colnames[j];
                    }
                    if(j>0){
                        tempsql<<"`";
                    }
            tempsql<<") VALUES (";

        if(data.userid==0){
tempsql<<"null";
 }else{ 
	tempsql<<std::to_string(data.userid);
}
tempsql<<",'"<<stringaddslash(data.name)<<"'";
tempsql<<",'"<<stringaddslash(data.password)<<"'";
if(data.isopen==0){
	tempsql<<",0";
 }else{ 
	tempsql<<","<<std::to_string(data.isopen);
}
if(data.level==0){
	tempsql<<",0";
 }else{ 
	tempsql<<","<<std::to_string(data.level);
}
tempsql<<")";

     
       return tempsql.str();
   }     
    std::string _makeupdatesql(std::string fileld){
       int j=0;
            std::ostringstream tempsql;
                 tempsql<<"UPDATE ";
                 tempsql<<tablename;
                 tempsql<<" SET ";

            bool isall=false;
            if(fileld.empty()){
                isall=true;
            }
            if(isall){

        if(data.userid==0){
	tempsql<<"`userid`=0";
 }else{ 
	tempsql<<"`userid`="<<std::to_string(data.userid);
}
tempsql<<",`name`='"<<stringaddslash(data.name)<<"'";
tempsql<<",`password`='"<<stringaddslash(data.password)<<"'";
if(data.isopen==0){
	tempsql<<",`isopen`=0";
 }else{ 
	tempsql<<",`isopen`="<<std::to_string(data.isopen);
}
if(data.level==0){
	tempsql<<",`level`=0";
 }else{ 
	tempsql<<",`level`="<<std::to_string(data.level);
}
 }else{ 

     
  int jj=0;
                  std::string keyname;
                  std::vector<unsigned char> keypos;
                  for(;jj<fileld.size();jj++){
                        if(fileld[jj]==','){
                               keypos.emplace_back(findcolpos(keyname)); 
                               keyname.clear();
                             continue;   
                        }
                        if(fileld[jj]==0x20){

                             continue;   
                        }
                        keyname.push_back(fileld[jj]);

                  }  
                 if(keyname.size()>0){
                                keypos.emplace_back(findcolpos(keyname)); 
                                keyname.clear();
                 }
                 for(jj=0;jj<keypos.size();jj++){
                       switch(keypos[jj]){

         case 0:
 if(jj>0){ tempsql<<","; } 
if(data.userid==0){
	tempsql<<"`userid`=0";
 }else{ 
	tempsql<<"`userid`="<<std::to_string(data.userid);
}
 break;
 case 1:
 if(jj>0){ tempsql<<","; } 
tempsql<<"`name`='"<<stringaddslash(data.name)<<"'";
 break;
 case 2:
 if(jj>0){ tempsql<<","; } 
tempsql<<"`password`='"<<stringaddslash(data.password)<<"'";
 break;
 case 3:
 if(jj>0){ tempsql<<","; } 
if(data.isopen==0){
	tempsql<<"`isopen`=0";
 }else{ 
	tempsql<<"`isopen`="<<std::to_string(data.isopen);
}
 break;
 case 4:
 if(jj>0){ tempsql<<","; } 
if(data.level==0){
	tempsql<<"`level`=0";
 }else{ 
	tempsql<<"`level`="<<std::to_string(data.level);
}
 break;

     
                  default:
                                ;
                     }
                 }   

            }        

        return std::move(tempsql.str());
   } 
   std::string datatojson(){
       std::ostringstream tempsql;

        tempsql<<"{";
if(data.userid==0){
	tempsql<<"\"userid\":0";
 }else{ 
	tempsql<<"\"userid\":"<<std::to_string(data.userid);
}
tempsql<<",\"name\":\""<<http::utf8_to_jsonstring(data.name);
tempsql<<"\"";
tempsql<<",\"password\":\""<<http::utf8_to_jsonstring(data.password);
tempsql<<"\"";
if(data.isopen==0){
	tempsql<<",\"isopen\":0";
 }else{ 
	tempsql<<",\"isopen\":"<<std::to_string(data.isopen);
}
if(data.level==0){
	tempsql<<",\"level\":0";
 }else{ 
	tempsql<<",\"level\":"<<std::to_string(data.level);
}
tempsql<<"}";

     
     return std::move(tempsql.str());             
   }   
   
   std::string datatojson(std::string fileld){
       std::ostringstream tempsql;
            std::string keyname;
            unsigned char jj=0;
                  std::vector<unsigned char> keypos;
                  if(fileld.size()>0){
                    for(;jj<fileld.size();jj++){
                            if(fileld[jj]==','){
                                keypos.emplace_back(findcolpos(keyname)); 
                                keyname.clear();
                                continue;   
                            }
                            if(fileld[jj]==0x20){

                                continue;   
                            }
                            keyname.push_back(fileld[jj]);

                    }  
                    if(keyname.size()>0){
                                    keypos.emplace_back(findcolpos(keyname)); 
                                    keyname.clear();
                    }
                 }else{
                     for(jj=0;jj<colnames.size();jj++){
                         keypos.emplace_back(jj); 
                     }
                 }
                 tempsql<<"{";
                 for(jj=0;jj<keypos.size();jj++){
                       switch(keypos[jj]){
         case 0:
 if(jj>0){ tempsql<<","; } 
if(data.userid==0){
	tempsql<<"\"userid\":0";
 }else{ 
	tempsql<<"\"userid\":"<<std::to_string(data.userid);
}
 break;
 case 1:
 if(jj>0){ tempsql<<","; } 
tempsql<<"\"name\":\""<<http::utf8_to_jsonstring(data.name)<<"\"";
 break;
 case 2:
 if(jj>0){ tempsql<<","; } 
tempsql<<"\"password\":\""<<http::utf8_to_jsonstring(data.password)<<"\"";
 break;
 case 3:
 if(jj>0){ tempsql<<","; } 
if(data.isopen==0){
	tempsql<<"\"isopen\":0";
 }else{ 
	tempsql<<"\"isopen\":"<<std::to_string(data.isopen);
}
 break;
 case 4:
 if(jj>0){ tempsql<<","; } 
if(data.level==0){
	tempsql<<"\"level\":0";
 }else{ 
	tempsql<<"\"level\":"<<std::to_string(data.level);
}
 break;

                             default:
                                ;
                     }
                 }   
      tempsql<<"}";  
     return std::move(tempsql.str());             
   }   
   
   std::string tojson(std::string fileld=""){
       std::ostringstream tempsql;
            std::string keyname;
            unsigned char jj=0;
                  std::vector<unsigned char> keypos;
                  if(fileld.size()>0){
                    for(;jj<fileld.size();jj++){
                            if(fileld[jj]==','){
                                keypos.emplace_back(findcolpos(keyname)); 
                                keyname.clear();
                                continue;   
                            }
                            if(fileld[jj]==0x20){

                                continue;   
                            }
                            keyname.push_back(fileld[jj]);

                    }  
                    if(keyname.size()>0){
                                    keypos.emplace_back(findcolpos(keyname)); 
                                    keyname.clear();
                    }
                 }else{
                     for(jj=0;jj<colnames.size();jj++){
                         keypos.emplace_back(jj); 
                     }
                 }
                tempsql<<"[";
              for(int n=0;n<record.size();n++){
                  if(n>0){
                      tempsql<<",{";
                  }else{
                      tempsql<<"{";
                  }  
                 
                 for(jj=0;jj<keypos.size();jj++){
                       switch(keypos[jj]){
         case 0:
 if(jj>0){ tempsql<<","; } 
if(record[n].userid==0){
	tempsql<<"\"userid\":0";
 }else{ 
	tempsql<<"\"userid\":"<<std::to_string(record[n].userid);
}
 break;
 case 1:
 if(jj>0){ tempsql<<","; } 
tempsql<<"\"name\":\""<<http::utf8_to_jsonstring(record[n].name)<<"\"";
 break;
 case 2:
 if(jj>0){ tempsql<<","; } 
tempsql<<"\"password\":\""<<http::utf8_to_jsonstring(record[n].password)<<"\"";
 break;
 case 3:
 if(jj>0){ tempsql<<","; } 
if(record[n].isopen==0){
	tempsql<<"\"isopen\":0";
 }else{ 
	tempsql<<"\"isopen\":"<<std::to_string(record[n].isopen);
}
 break;
 case 4:
 if(jj>0){ tempsql<<","; } 
if(record[n].level==0){
	tempsql<<"\"level\":0";
 }else{ 
	tempsql<<"\"level\":"<<std::to_string(record[n].level);
}
 break;

                             default:
                                ;
                     }
                 }   
      tempsql<<"}";  
            }
      tempsql<<"]";
     return std::move(tempsql.str());             
   }   
   
   std::string tojson(std::function<bool(std::string&,meta&)> func,std::string fileld=""){
       std::ostringstream tempsql;
            std::string keyname;
            unsigned char jj=0;
                  std::vector<unsigned char> keypos;
                  if(fileld.size()>0){
                    for(;jj<fileld.size();jj++){
                            if(fileld[jj]==','){
                                keypos.emplace_back(findcolpos(keyname)); 
                                keyname.clear();
                                continue;   
                            }
                            if(fileld[jj]==0x20){

                                continue;   
                            }
                            keyname.push_back(fileld[jj]);

                    }  
                    if(keyname.size()>0){
                                    keypos.emplace_back(findcolpos(keyname)); 
                                    keyname.clear();
                    }
                 }else{
                     for(jj=0;jj<colnames.size();jj++){
                         keypos.emplace_back(jj); 
                     }
                 }
                tempsql<<"[";
              for(int n=0;n<record.size();n++){
                 keyname.clear();
                 if(func(keyname,record[n])){ 
                            if(n>0){
                                tempsql<<",{";
                            }else{
                                tempsql<<"{";
                            } 
                            tempsql<<keyname;
                 }else{
                    continue;
                 } 
                  
                 for(jj=0;jj<keypos.size();jj++){
                        
                       switch(keypos[jj]){
         case 0:
 if(jj>0){ tempsql<<","; } 
if(record[n].userid==0){
	tempsql<<"\"userid\":0";
 }else{ 
	tempsql<<"\"userid\":"<<std::to_string(record[n].userid);
}
 break;
 case 1:
 if(jj>0){ tempsql<<","; } 
tempsql<<"\"name\":\""<<http::utf8_to_jsonstring(record[n].name)<<"\"";
 break;
 case 2:
 if(jj>0){ tempsql<<","; } 
tempsql<<"\"password\":\""<<http::utf8_to_jsonstring(record[n].password)<<"\"";
 break;
 case 3:
 if(jj>0){ tempsql<<","; } 
if(record[n].isopen==0){
	tempsql<<"\"isopen\":0";
 }else{ 
	tempsql<<"\"isopen\":"<<std::to_string(record[n].isopen);
}
 break;
 case 4:
 if(jj>0){ tempsql<<","; } 
if(record[n].level==0){
	tempsql<<"\"level\":0";
 }else{ 
	tempsql<<"\"level\":"<<std::to_string(record[n].level);
}
 break;

                             default:
                                ;
                     }
                 }   
      tempsql<<"}";  
            }
      tempsql<<"]";
     return std::move(tempsql.str());             
   }   
   long long getPK(){  return data.userid; } 
 void setPK(long long val){  data.userid=val;} 
unsigned  int  getUserid(){  return data.userid; } 
 void setUserid(unsigned  int  val){  data.userid=val;} 

std::string getName(){  return data.name; } 
std::string& getRefName(){  return std::ref(data.name); } 
 void setName(std::string &val){  data.name=val;} 
 void setName(std::string_view val){  data.name=val;} 

std::string getPassword(){  return data.password; } 
std::string& getRefPassword(){  return std::ref(data.password); } 
 void setPassword(std::string &val){  data.password=val;} 
 void setPassword(std::string_view val){  data.password=val;} 

 int  getIsopen(){  return data.isopen; } 
 void setIsopen( int  val){  data.isopen=val;} 

 int  getLevel(){  return data.level; } 
 void setLevel( int  val){  data.level=val;} 

userbase::meta getnewData(){
 	 struct meta newdata;
	 return std::move(newdata); 
} 
userbase::meta getData(){
 	 return data; 
} 
std::vector<userbase::meta> getRecord(){
 	 return record; 
} 

    template<typename T, typename std::enable_if<std::is_integral_v<T>,bool>::type = true >  
    std::vector<T> getCol(std::string keyname){
         std::vector<T> a;
         unsigned char kpos;
         kpos=findcolpos(keyname);
        for(auto &iter:record){
                switch(kpos){

   case 0: 
 	 a.emplace_back(iter.userid);
	 break;
case 3: 
 	 a.emplace_back(iter.isopen);
	 break;
case 4: 
 	 a.emplace_back(iter.level);
	 break;

          }
        }
        return a;
    }
    
    template<typename T, typename std::enable_if<std::is_floating_point_v<T>,bool>::type = true >    
    std::vector<T> getCol(std::string keyname){
        std::vector<T> a;
         unsigned char kpos;
         kpos=findcolpos(keyname);
        for(auto &iter:record){
                switch(kpos){

   
    }
            }
            return a;
        }  
    
    template<typename T, typename std::enable_if<std::is_integral_v<T>,bool>::type = true >   
    T getVal(std::string keyname){
         
         unsigned char kpos;
         kpos=findcolpos(keyname);
      
                switch(kpos){

   case 0: 
 	 return data.userid;
	 break;
case 3: 
 	 return data.isopen;
	 break;
case 4: 
 	 return data.level;
	 break;

    }
            return 0;
        }  
    
     template<typename T, typename std::enable_if<std::is_integral_v<T>,bool>::type = true > 
    T getVal(userbase::meta & iter,std::string keyname){
         
         unsigned char kpos;
         kpos=findcolpos(keyname);
       
                switch(kpos){

   case 0: 
 	 return iter.userid;
	 break;
case 3: 
 	 return iter.isopen;
	 break;
case 4: 
 	 return iter.level;
	 break;

    }
            return 0;
        }  
    
        template<typename T, typename std::enable_if<std::is_floating_point_v<T>,bool>::type = true > 
        T getVal(std::string keyname){
            
            unsigned char kpos;
            kpos=findcolpos(keyname);
        
            switch(kpos){

    
    }
            return 0.0;
        }  
    
     template<typename T, typename std::enable_if<std::is_floating_point_v<T>,bool>::type = true > 
    T getVal(userbase::meta & iter,std::string keyname){
         
         unsigned char kpos;
        kpos=findcolpos(keyname);
         
                switch(kpos){

   
    }
            return 0.0;
        }  
    
    template<typename T, typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true > 
    std::string getVal(std::string keyname){
         
         unsigned char kpos;
        kpos=findcolpos(keyname);
        
                switch(kpos){

   case 1: 
 	 return data.name;
	 break;
case 2: 
 	 return data.password;
	 break;

  }
        return "";
    }  
   
    template<typename T, typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true > 
    std::string getVal(userbase::meta & iter,std::string keyname){
         
         unsigned char kpos;
        kpos=findcolpos(keyname);
       
                switch(kpos){

   case 1: 
 	 return iter.name;
	 break;
case 2: 
 	 return iter.password;
	 break;

    }
            return "";
        }  
     
    template<typename T, typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true >   
    std::vector<std::string> getCol(std::string keyname){
        std::vector<std::string> a;
         unsigned char kpos;
        kpos=findcolpos(keyname);
 
         for(auto &iter:record){
                switch(kpos){

   case 1: 
 	 a.emplace_back(iter.name);
	 break;
case 2: 
 	 a.emplace_back(iter.password);
	 break;

   }
        }       

        return a;
    }  
    std::string getstrCol(std::string keyname,bool isyinhao=false){
        std::ostringstream a;
             unsigned char kpos;
        kpos=findcolpos(keyname);
  
         int j=0;
         if(isyinhao&&record.size()>0){
             a<<'"';
         }
         for(auto &iter:record){
                if(j>0){
                    if(isyinhao){
                        a<<"\",\"";
                    }else{
                        a<<',';    
                    }
                }
                 switch(kpos){

   case 0: 
 	 a<<std::to_string(iter.userid);
	 break;
case 1: 
 	 if(isyinhao){ a<<jsonaddslash(iter.name); 
	 }else{
	 a<<iter.name;
	 }
	 break;
case 2: 
 	 if(isyinhao){ a<<jsonaddslash(iter.password); 
	 }else{
	 a<<iter.password;
	 }
	 break;
case 3: 
 	 a<<std::to_string(iter.isopen);
	 break;
case 4: 
 	 a<<std::to_string(iter.level);
	 break;

    }
                j++;
        } 
        if(isyinhao&&j>0){
             a<<'"';
        }      
        return a.str();
    }
    
    template<typename T,typename U,typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true,typename std::enable_if<std::is_same<U,std::string>::value,bool>::type = true>     
    std::map<std::string,std::string> getCols(std::string keyname,std::string valname){
        std::map<std::string,std::string> a;
        unsigned char kpos,vpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
         std::string ktemp,vtemp;
         for(auto &iter:record){
                
                switch(kpos){

   case 1: 
 	 ktemp=iter.name;
	 break;
case 2: 
 	 ktemp=iter.password;
	 break;
	 } 
		 switch(vpos){ 
case 1: 
 	 vtemp=iter.name;
	 break;
case 2: 
 	 vtemp=iter.password;
	 break;

        }
                    a.emplace(ktemp,vtemp);
            }       
            return a;
        } 

  template<typename T,typename U,typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true, typename std::enable_if<std::is_floating_point<U>::value,bool>::type = true>    
  std::map<std::string,U> getCols(std::string keyname,std::string valname){
        std::map<std::string,U> a;
        unsigned char kpos,vpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
         std::string ktemp;
         U vtemp;
         for(auto &iter:record){
                
                switch(kpos){
 
       case 1: 
 	 ktemp=iter.name;
	 break;
case 2: 
 	 ktemp=iter.password;
	 break;
	 } 
        switch(vpos){ 

            }
                a.emplace(ktemp,vtemp);
        }       
        return a;
    } 
  template<typename T,typename U,typename std::enable_if<std::is_integral_v<T>,bool>::type = true, typename std::enable_if<std::is_floating_point<U>::value,bool>::type = true>       
  std::map<T,U> getCols(std::string keyname,std::string valname){
        std::map<T,U> a;
        unsigned char kpos,vpos;
         kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
         T ktemp;
         U vtemp;
         for(auto &iter:record){
                
                switch(kpos){
 
       case 0: 
 	 ktemp=iter.userid;
	 break;
case 3: 
 	 ktemp=iter.isopen;
	 break;
case 4: 
 	 ktemp=iter.level;
	 break;
	 } 
 		   switch(vpos){ 

             }
                a.emplace(ktemp,vtemp);
        }       
        return a;
    }  
    template<typename T,typename U,typename std::enable_if<std::is_integral_v<T>,bool>::type = true, typename std::enable_if<std::is_same<U,std::string>::value,bool>::type = true>      
    std::map<T,std::string> getCols(std::string keyname,std::string valname){
        std::map<T,std::string> a;
                unsigned char kpos,vpos;
         kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
             T ktemp;
             std::string vtemp;
         for(auto &iter:record){
             
                switch(kpos){

   case 0: 
 	 ktemp=iter.userid;
	 break;
case 3: 
 	 ktemp=iter.isopen;
	 break;
case 4: 
 	 ktemp=iter.level;
	 break;
	  }
 switch(vpos){
case 1: 
 	 vtemp=iter.name;
	 break;
case 2: 
 	 vtemp=iter.password;
	 break;

  }
                a.emplace(ktemp,vtemp);
        }       
        return a;
    }     
     template<typename T,typename U, typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true,typename std::enable_if<std::is_integral_v<U>,bool>::type = true>       
    std::map<std::string,U> getCols(std::string keyname,std::string valname){
        std::map<std::string,U> a;
             unsigned char kpos,vpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
             std::string  ktemp;
             U  vtemp;
         for(auto &iter:record){
             
                switch(kpos){

   case 1: 
 	 ktemp=iter.name;
	 break;
case 2: 
 	 ktemp=iter.password;
	 break;
	  }
 switch(vpos){
case 0: 
 	 vtemp=iter.userid;
	 break;
case 3: 
 	 vtemp=iter.isopen;
	 break;
case 4: 
 	 vtemp=iter.level;
	 break;

                 }

             
                a.emplace(ktemp,vtemp);
        }       
        return a;
    }  
    template<typename T,typename U, typename std::enable_if<std::is_integral_v<T>,bool>::type = true,typename std::enable_if<std::is_integral_v<U>,bool>::type = true>   
    std::map<T,U> getCols(std::string keyname,std::string valname){
        std::map<T,U> a;

        unsigned char kpos,vpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
             T ktemp;
             U vtemp;
         for(auto &iter:record){
             
                switch(kpos){

   case 0: 
 	 ktemp=iter.userid;
	 break;
case 3: 
 	 ktemp=iter.isopen;
	 break;
case 4: 
 	 ktemp=iter.level;
	 break;
	  }
 switch(vpos){
case 0: 
 	 vtemp=iter.userid;
	 break;
case 3: 
 	 vtemp=iter.isopen;
	 break;
case 4: 
 	 vtemp=iter.level;
	 break;

                   }

                    a.emplace(ktemp,vtemp);
            }       

            return a;
        }   
    template<typename T, typename std::enable_if<std::is_integral_v<T>,bool>::type = true >         
    std::map<T,meta> getmapRows(std::string keyname){
        std::map<T,meta> a;

            unsigned char kpos;
         kpos=findcolpos(keyname);
 
          //   long long ktemp;
        
         for(auto &iter:record){
                switch(kpos){

   case 0: 
 	 a.emplace(iter.userid,iter);
	 break;
case 3: 
 	 a.emplace(iter.isopen,iter);
	 break;
case 4: 
 	 a.emplace(iter.level,iter);
	 break;

                }
        }       
        return a;
    }     
   template<typename T, typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true >    
   std::map<std::string,meta> getmapRows(std::string keyname){
        std::map<std::string,meta> a;

         unsigned char kpos;
 
        kpos=findcolpos(keyname);
    

        //std::string ktemp;
        
         for(auto &iter:record){
             
                   switch(kpos){

   case 1: 
 	 a.emplace(iter.name,iter);
	 break;
case 2: 
 	 a.emplace(iter.password,iter);
	 break;

                }

                //a.emplace(ktemp,iter);
        }       

        return a;
    }
    template<typename T,typename U,typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true, typename std::enable_if<std::is_floating_point<U>::value,bool>::type = true>  
    std::vector<std::pair<std::string,U>> getvecCols(std::string keyname,std::string valname){
        std::vector<std::pair<std::string,U>> a;

        unsigned char kpos,vpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
             std::string ktemp;
             U vtemp;
         for(auto &iter:record){
             
                switch(kpos){

   case 1: 
 	 ktemp=iter.name;
	 break;
case 2: 
 	 ktemp=iter.password;
	 break;
	  }
 switch(vpos){

                   }

                    a.emplace_back(ktemp,vtemp);
            }       

            return a;
        }   
  template<typename T,typename U,typename std::enable_if<std::is_integral_v<T>,bool>::type = true, typename std::enable_if<std::is_floating_point<U>::value,bool>::type = true>    
  std::vector<std::pair<T,U>> getvecCols(std::string keyname,std::string valname){
        std::vector<std::pair<T,U>> a;

        unsigned char kpos,vpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
             T ktemp;
             U vtemp;
         for(auto &iter:record){
             
                switch(kpos){

   case 0: 
 	 ktemp=iter.userid;
	 break;
case 3: 
 	 ktemp=iter.isopen;
	 break;
case 4: 
 	 ktemp=iter.level;
	 break;
	  }
 switch(vpos){

                   }

                    a.emplace_back(ktemp,vtemp);
            }       

            return a;
        }   
  template<typename T,typename U,typename std::enable_if<std::is_integral_v<T>,bool>::type = true, typename std::enable_if<std::is_same<U,std::string>::value,bool>::type = true>    
  std::vector<std::pair<T,U>> getvecCols(std::string keyname,std::string valname){
        std::vector<std::pair<T,U>> a;

        unsigned char kpos,vpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
             T ktemp;
             U vtemp;
         for(auto &iter:record){
             
                switch(kpos){

   case 0: 
 	 ktemp=iter.userid;
	 break;
case 3: 
 	 ktemp=iter.isopen;
	 break;
case 4: 
 	 ktemp=iter.level;
	 break;
	  }
 switch(vpos){
case 1: 
 	 vtemp=iter.name;
	 break;
case 2: 
 	 vtemp=iter.password;
	 break;

                   }

                    a.emplace_back(ktemp,vtemp);
            }       

            return a;
        }   
  template<typename T,typename U, typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true,typename std::enable_if<std::is_integral_v<U>,bool>::type = true>     
  std::vector<std::pair<T,U>> getvecCols(std::string keyname,std::string valname){
        std::vector<std::pair<T,U>> a;

        unsigned char kpos,vpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
             T ktemp;
             U vtemp;
         for(auto &iter:record){
             
                switch(kpos){

   case 1: 
 	 ktemp=iter.name;
	 break;
case 2: 
 	 ktemp=iter.password;
	 break;
	  }
 switch(vpos){
case 0: 
 	 vtemp=iter.userid;
	 break;
case 3: 
 	 vtemp=iter.isopen;
	 break;
case 4: 
 	 vtemp=iter.level;
	 break;

                   }

                    a.emplace_back(ktemp,vtemp);
            }       

            return a;
        }   
  template<typename T,typename U, typename std::enable_if<std::is_integral_v<T>,bool>::type = true,typename std::enable_if<std::is_integral_v<U>,bool>::type = true>    
  std::vector<std::pair<T,U>> getvecCols(std::string keyname,std::string valname){
        std::vector<std::pair<T,U>> a;

        unsigned char kpos,vpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
             T ktemp;
             U vtemp;
         for(auto &iter:record){
             
                switch(kpos){

   case 0: 
 	 ktemp=iter.userid;
	 break;
case 3: 
 	 ktemp=iter.isopen;
	 break;
case 4: 
 	 ktemp=iter.level;
	 break;
	  }
 switch(vpos){
case 0: 
 	 vtemp=iter.userid;
	 break;
case 3: 
 	 vtemp=iter.isopen;
	 break;
case 4: 
 	 vtemp=iter.level;
	 break;

                   }

                    a.emplace_back(ktemp,vtemp);
            }       

            return a;
        }   
  template<typename T,typename U, typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true,typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true>     
  std::vector<std::pair<T,U>> getvecCols(std::string keyname,std::string valname){
        std::vector<std::pair<T,U>> a;

        unsigned char kpos,vpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
             T ktemp;
             U vtemp;
         for(auto &iter:record){
             
                switch(kpos){

   case 1: 
 	 ktemp=iter.name;
	 break;
case 2: 
 	 ktemp=iter.password;
	 break;
	  }
 switch(vpos){
case 1: 
 	 vtemp=iter.name;
	 break;
case 2: 
 	 vtemp=iter.password;
	 break;

                   }

                    a.emplace_back(ktemp,vtemp);
            }       

            return a;
        }   
    template<typename T, typename std::enable_if<std::is_integral_v<T>,bool>::type = true >   
    std::vector<std::pair<T,meta>> getvecRows(std::string keyname){
        std::vector<std::pair<T,meta>> a;

         unsigned char kpos;
 
        kpos=findcolpos(keyname);
    

       // T ktemp;
        
         for(auto &iter:record){
             
                   switch(kpos){

   case 0: 
 	 a.emplace_back(iter.userid,iter);
	 break;
case 3: 
 	 a.emplace_back(iter.isopen,iter);
	 break;
case 4: 
 	 a.emplace_back(iter.level,iter);
	 break;

                }

                
        }       

        return a;
    }
    template<typename T, typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true >  
    std::vector<std::pair<std::string,meta>> getvecRows(std::string keyname){
        std::vector<std::pair<std::string,meta>> a;

         unsigned char kpos;
        kpos=findcolpos(keyname);
        //std::string ktemp;
        
         for(auto &iter:record){
             
                   switch(kpos){

   case 1: 
 	 a.emplace_back(iter.name,iter);
	 break;
case 2: 
 	 a.emplace_back(iter.password,iter);
	 break;

                }

                
        }       

        return a;
    }
    template<typename T,typename U,typename D,typename std::enable_if<std::is_integral_v<T>,bool>::type = true,typename std::enable_if<std::is_integral_v<U>,bool>::type = true, typename std::enable_if<std::is_floating_point<D>::value,bool>::type = true>    
  std::map<T,std::map<U,std::vector<D>>> getgroupCols(std::string keyname,std::string valname,std::string dataname){
        std::map<T,std::map<U,std::vector<D>>> a;

        unsigned char kpos,vpos,dpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
        dpos=findcolpos(dataname);
        
        T ktemp;
        U vtemp;
        //D vtemp;
         for(auto &iter:record){
             
                   switch(kpos){

   case 0: 
 	 ktemp=iter.userid;
	 break;
case 3: 
 	 ktemp=iter.isopen;
	 break;
case 4: 
 	 ktemp=iter.level;
	 break;
	  }

 switch(vpos){
case 0: 
 	 vtemp=iter.userid;
	 break;
case 3: 
 	 vtemp=iter.isopen;
	 break;
case 4: 
 	 vtemp=iter.level;
	 break;
	  }

 switch(dpos){

                   }
                //a[ktemp][vtemp].emplace_back(dtemp);
        }       

        return a;
    }
    template<typename T,typename U,typename D,typename std::enable_if<std::is_integral_v<T>,bool>::type = true,typename std::enable_if<std::is_integral_v<U>,bool>::type = true, typename std::enable_if<std::is_integral_v<D>,bool>::type = true>    
  std::map<T,std::map<U,std::vector<D>>> getgroupCols(std::string keyname,std::string valname,std::string dataname){
        std::map<T,std::map<U,std::vector<D>>> a;

        unsigned char kpos,vpos,dpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
        dpos=findcolpos(dataname);
        T ktemp;
        U vtemp;
        //D vtemp;

         for(auto &iter:record){
             
                   switch(kpos){

   case 0: 
 	 ktemp=iter.userid;
	 break;
case 3: 
 	 ktemp=iter.isopen;
	 break;
case 4: 
 	 ktemp=iter.level;
	 break;
	  }

 switch(vpos){
case 0: 
 	 vtemp=iter.userid;
	 break;
case 3: 
 	 vtemp=iter.isopen;
	 break;
case 4: 
 	 vtemp=iter.level;
	 break;
	  }

 switch(dpos){
case 0: 
 	 a[ktemp][vtemp].emplace_back(iter.userid);
	 break;
case 3: 
 	 a[ktemp][vtemp].emplace_back(iter.isopen);
	 break;
case 4: 
 	 a[ktemp][vtemp].emplace_back(iter.level);
	 break;

                   }
                //a[ktemp][vtemp].emplace_back(dtemp);
        }       

        return a;
    }
    template<typename T,typename U,typename D,typename std::enable_if<std::is_integral_v<T>,bool>::type = true,typename std::enable_if<std::is_integral_v<U>,bool>::type = true, typename std::enable_if<std::is_same<D,std::string>::value,bool>::type = true>    
  std::map<T,std::map<U,std::vector<D>>> getgroupCols(std::string keyname,std::string valname,std::string dataname){
        std::map<T,std::map<U,std::vector<D>>> a;

        unsigned char kpos,vpos,dpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
        dpos=findcolpos(dataname);
        T ktemp;
        U vtemp;
       // D dtemp;

         for(auto &iter:record){
             
                   switch(kpos){

   case 0: 
 	 ktemp=iter.userid;
	 break;
case 3: 
 	 ktemp=iter.isopen;
	 break;
case 4: 
 	 ktemp=iter.level;
	 break;
	  }

 switch(vpos){
case 0: 
 	 vtemp=iter.userid;
	 break;
case 3: 
 	 vtemp=iter.isopen;
	 break;
case 4: 
 	 vtemp=iter.level;
	 break;
	  }

 switch(dpos){
case 1: 
 	 a[ktemp][vtemp].emplace_back(iter.name);
	 break;
case 2: 
 	 a[ktemp][vtemp].emplace_back(iter.password);
	 break;

                   }
                //a[ktemp][vtemp].emplace_back(dtemp);
        }       

        return a;
    }
    template<typename T,typename U,typename D,typename std::enable_if<std::is_integral_v<T>,bool>::type = true, typename std::enable_if<std::is_same<U,std::string>::value,bool>::type = true, typename std::enable_if<std::is_floating_point<D>::value,bool>::type = true>    
  std::map<T,std::map<U,std::vector<D>>> getgroupCols(std::string keyname,std::string valname,std::string dataname){
        std::map<T,std::map<U,std::vector<D>>> a;

        unsigned char kpos,vpos,dpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
        dpos=findcolpos(dataname);
        T ktemp;
        U vtemp;
       // D dtemp;

         for(auto &iter:record){
             
                   switch(kpos){

   case 0: 
 	 ktemp=iter.userid;
	 break;
case 3: 
 	 ktemp=iter.isopen;
	 break;
case 4: 
 	 ktemp=iter.level;
	 break;
	  }

 switch(vpos){
case 1: 
 	 vtemp=iter.name;
	 break;
case 2: 
 	 vtemp=iter.password;
	 break;
	  }

 switch(dpos){

                   }
                //a[ktemp][vtemp].emplace_back(dtemp);
        }       

        return a;
    }
    template<typename T,typename U,typename D,typename std::enable_if<std::is_integral_v<T>,bool>::type = true, typename std::enable_if<std::is_same<U,std::string>::value,bool>::type = true, typename std::enable_if<std::is_integral_v<D>,bool>::type = true>    
  std::map<T,std::map<U,std::vector<D>>> getgroupCols(std::string keyname,std::string valname,std::string dataname){
        std::map<T,std::map<U,std::vector<D>>> a;

        unsigned char kpos,vpos,dpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
        dpos=findcolpos(dataname);
        T ktemp;
        U vtemp;
       // D dtemp;

         for(auto &iter:record){
             
                   switch(kpos){

   case 0: 
 	 ktemp=iter.userid;
	 break;
case 3: 
 	 ktemp=iter.isopen;
	 break;
case 4: 
 	 ktemp=iter.level;
	 break;
	  }

 switch(vpos){
case 1: 
 	 vtemp=iter.name;
	 break;
case 2: 
 	 vtemp=iter.password;
	 break;
	  }

 switch(dpos){
case 0: 
 	 a[ktemp][vtemp].emplace_back(iter.userid);
	 break;
case 3: 
 	 a[ktemp][vtemp].emplace_back(iter.isopen);
	 break;
case 4: 
 	 a[ktemp][vtemp].emplace_back(iter.level);
	 break;

                   }
                //a[ktemp][vtemp].emplace_back(dtemp);
        }       

        return a;
    }
    template<typename T,typename U,typename D,typename std::enable_if<std::is_integral_v<T>,bool>::type = true, typename std::enable_if<std::is_same<U,std::string>::value,bool>::type = true, typename std::enable_if<std::is_same<D,std::string>::value,bool>::type = true>    
  std::map<T,std::map<U,std::vector<D>>> getgroupCols(std::string keyname,std::string valname,std::string dataname){
        std::map<T,std::map<U,std::vector<D>>> a;

        unsigned char kpos,vpos,dpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
        dpos=findcolpos(dataname);
        T ktemp;
        U vtemp;
       // D dtemp;

         for(auto &iter:record){
             
                   switch(kpos){

   case 0: 
 	 ktemp=iter.userid;
	 break;
case 3: 
 	 ktemp=iter.isopen;
	 break;
case 4: 
 	 ktemp=iter.level;
	 break;
	  }

 switch(vpos){
case 1: 
 	 vtemp=iter.name;
	 break;
case 2: 
 	 vtemp=iter.password;
	 break;
	  }

 switch(dpos){
case 1: 
 	 a[ktemp][vtemp].emplace_back(iter.name);
	 break;
case 2: 
 	 a[ktemp][vtemp].emplace_back(iter.password);
	 break;

                   }
                //a[ktemp][vtemp].emplace_back(dtemp);
        }       

        return a;
    }
    template<typename T,typename U,typename D,typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true,typename std::enable_if<std::is_integral_v<U>,bool>::type = true, typename std::enable_if<std::is_floating_point<D>::value,bool>::type = true>    
  std::map<T,std::map<U,std::vector<D>>> getgroupCols(std::string keyname,std::string valname,std::string dataname){
        std::map<T,std::map<U,std::vector<D>>> a;

        unsigned char kpos,vpos,dpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
        dpos=findcolpos(dataname);
        
        T ktemp;
        U vtemp;
        //D vtemp;
         for(auto &iter:record){
             
                   switch(kpos){

   case 1: 
 	 ktemp=iter.name;
	 break;
case 2: 
 	 ktemp=iter.password;
	 break;
	  }

 switch(vpos){
case 0: 
 	 vtemp=iter.userid;
	 break;
case 3: 
 	 vtemp=iter.isopen;
	 break;
case 4: 
 	 vtemp=iter.level;
	 break;
	  }

 switch(dpos){

                   }
                //a[ktemp][vtemp].emplace_back(dtemp);
        }       

        return a;
    }
    template<typename T,typename U,typename D,typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true,typename std::enable_if<std::is_integral_v<U>,bool>::type = true, typename std::enable_if<std::is_integral_v<D>,bool>::type = true>    
  std::map<T,std::map<U,std::vector<D>>> getgroupCols(std::string keyname,std::string valname,std::string dataname){
        std::map<T,std::map<U,std::vector<D>>> a;

        unsigned char kpos,vpos,dpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
        dpos=findcolpos(dataname);
        T ktemp;
        U vtemp;
        //D vtemp;

         for(auto &iter:record){
             
                   switch(kpos){

   case 1: 
 	 ktemp=iter.name;
	 break;
case 2: 
 	 ktemp=iter.password;
	 break;
	  }

 switch(vpos){
case 0: 
 	 vtemp=iter.userid;
	 break;
case 3: 
 	 vtemp=iter.isopen;
	 break;
case 4: 
 	 vtemp=iter.level;
	 break;
	  }

 switch(dpos){
case 0: 
 	 a[ktemp][vtemp].emplace_back(iter.userid);
	 break;
case 3: 
 	 a[ktemp][vtemp].emplace_back(iter.isopen);
	 break;
case 4: 
 	 a[ktemp][vtemp].emplace_back(iter.level);
	 break;

                   }
                //a[ktemp][vtemp].emplace_back(dtemp);
        }       

        return a;
    }
    template<typename T,typename U,typename D,typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true,typename std::enable_if<std::is_integral_v<U>,bool>::type = true, typename std::enable_if<std::is_same<D,std::string>::value,bool>::type = true>    
  std::map<T,std::map<U,std::vector<D>>> getgroupCols(std::string keyname,std::string valname,std::string dataname){
        std::map<T,std::map<U,std::vector<D>>> a;

        unsigned char kpos,vpos,dpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
        dpos=findcolpos(dataname);
        T ktemp;
        U vtemp;
       // D dtemp;

         for(auto &iter:record){
             
                   switch(kpos){

   case 1: 
 	 ktemp=iter.name;
	 break;
case 2: 
 	 ktemp=iter.password;
	 break;
	  }

 switch(vpos){
case 0: 
 	 vtemp=iter.userid;
	 break;
case 3: 
 	 vtemp=iter.isopen;
	 break;
case 4: 
 	 vtemp=iter.level;
	 break;
	  }

 switch(dpos){
case 1: 
 	 a[ktemp][vtemp].emplace_back(iter.name);
	 break;
case 2: 
 	 a[ktemp][vtemp].emplace_back(iter.password);
	 break;

                   }
                //a[ktemp][vtemp].emplace_back(dtemp);
        }       

        return a;
    }
    template<typename T,typename U,typename D,typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true, typename std::enable_if<std::is_same<U,std::string>::value,bool>::type = true, typename std::enable_if<std::is_floating_point<D>::value,bool>::type = true>    
  std::map<T,std::map<U,std::vector<D>>> getgroupCols(std::string keyname,std::string valname,std::string dataname){
        std::map<T,std::map<U,std::vector<D>>> a;

        unsigned char kpos,vpos,dpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
        dpos=findcolpos(dataname);
        T ktemp;
        U vtemp;
       // D dtemp;

         for(auto &iter:record){
             
                   switch(kpos){

   case 1: 
 	 ktemp=iter.name;
	 break;
case 2: 
 	 ktemp=iter.password;
	 break;
	  }

 switch(vpos){
case 1: 
 	 vtemp=iter.name;
	 break;
case 2: 
 	 vtemp=iter.password;
	 break;
	  }

 switch(dpos){

                   }
                //a[ktemp][vtemp].emplace_back(dtemp);
        }       

        return a;
    }
    template<typename T,typename U,typename D,typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true, typename std::enable_if<std::is_same<U,std::string>::value,bool>::type = true, typename std::enable_if<std::is_integral_v<D>,bool>::type = true>    
  std::map<T,std::map<U,std::vector<D>>> getgroupCols(std::string keyname,std::string valname,std::string dataname){
        std::map<T,std::map<U,std::vector<D>>> a;

        unsigned char kpos,vpos,dpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
        dpos=findcolpos(dataname);
        T ktemp;
        U vtemp;
       // D dtemp;

         for(auto &iter:record){
             
                   switch(kpos){

   case 1: 
 	 ktemp=iter.name;
	 break;
case 2: 
 	 ktemp=iter.password;
	 break;
	  }

 switch(vpos){
case 1: 
 	 vtemp=iter.name;
	 break;
case 2: 
 	 vtemp=iter.password;
	 break;
	  }

 switch(dpos){
case 0: 
 	 a[ktemp][vtemp].emplace_back(iter.userid);
	 break;
case 3: 
 	 a[ktemp][vtemp].emplace_back(iter.isopen);
	 break;
case 4: 
 	 a[ktemp][vtemp].emplace_back(iter.level);
	 break;

                   }
                //a[ktemp][vtemp].emplace_back(dtemp);
        }       

        return a;
    }
    template<typename T,typename U,typename D,typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true, typename std::enable_if<std::is_same<U,std::string>::value,bool>::type = true, typename std::enable_if<std::is_same<D,std::string>::value,bool>::type = true>    
  std::map<T,std::map<U,std::vector<D>>> getgroupCols(std::string keyname,std::string valname,std::string dataname){
        std::map<T,std::map<U,std::vector<D>>> a;

        unsigned char kpos,vpos,dpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
        dpos=findcolpos(dataname);
        T ktemp;
        U vtemp;
       // D dtemp;

         for(auto &iter:record){
             
                   switch(kpos){

   case 1: 
 	 ktemp=iter.name;
	 break;
case 2: 
 	 ktemp=iter.password;
	 break;
	  }

 switch(vpos){
case 1: 
 	 vtemp=iter.name;
	 break;
case 2: 
 	 vtemp=iter.password;
	 break;
	  }

 switch(dpos){
case 1: 
 	 a[ktemp][vtemp].emplace_back(iter.name);
	 break;
case 2: 
 	 a[ktemp][vtemp].emplace_back(iter.password);
	 break;

                   }
                //a[ktemp][vtemp].emplace_back(dtemp);
        }       

        return a;
    }
    template<typename T,typename U,typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true, typename std::enable_if<std::is_same<U,std::string>::value,bool>::type = true>    
  std::map<T,std::vector<U>> getgroupCols(std::string keyname,std::string valname){
        std::map<T,std::vector<U>> a;

        unsigned char kpos,vpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);

        T ktemp;
        //U vtemp;

         for(auto &iter:record){
             
                   switch(kpos){

   case 1: 
 	 ktemp=iter.name;
	 break;
case 2: 
 	 ktemp=iter.password;
	 break;
	  }

 switch(vpos){
case 1: 
 	 a[ktemp].emplace_back(iter.name);
	 break;
case 2: 
 	 a[ktemp].emplace_back(iter.password);
	 break;

                   }
                //a[ktemp].emplace_back(vtemp);
        }       

        return a;
    }
    template<typename T,typename U,typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true,typename std::enable_if<std::is_floating_point<U>::value,bool>::type = true>    
  std::map<T,std::vector<U>> getgroupCols(std::string keyname,std::string valname){
        std::map<T,std::vector<U>> a;

        unsigned char kpos,vpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);

        T ktemp;
        //U vtemp;

         for(auto &iter:record){
             
                   switch(kpos){

   case 1: 
 	 ktemp=iter.name;
	 break;
case 2: 
 	 ktemp=iter.password;
	 break;
	  }

 switch(vpos){

                   }
                //a[ktemp].emplace_back(vtemp);
        }       

        return a;
    }
    template<typename T,typename U,typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true,typename std::enable_if<std::is_integral_v<U>,bool>::type = true>    
  std::map<T,std::vector<U>> getgroupCols(std::string keyname,std::string valname){
        std::map<T,std::vector<U>> a;

        unsigned char kpos,vpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);

        T ktemp;
        //U vtemp;

         for(auto &iter:record){
             
                   switch(kpos){

   case 1: 
 	 ktemp=iter.name;
	 break;
case 2: 
 	 ktemp=iter.password;
	 break;
	  }

 switch(vpos){
case 0: 
 	 a[ktemp].emplace_back(iter.userid);
	 break;
case 3: 
 	 a[ktemp].emplace_back(iter.isopen);
	 break;
case 4: 
 	 a[ktemp].emplace_back(iter.level);
	 break;

                   }
                //a[ktemp].emplace_back(vtemp);
        }       

        return a;
    }
    template<typename T,typename U,typename std::enable_if<std::is_integral_v<T>,bool>::type = true, typename std::enable_if<std::is_same<U,std::string>::value,bool>::type = true>    
  std::map<T,std::vector<U>> getgroupCols(std::string keyname,std::string valname){
        std::map<T,std::vector<U>> a;

        unsigned char kpos,vpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);

        T ktemp;
        //U vtemp;

         for(auto &iter:record){
             
                   switch(kpos){

   case 0: 
 	 ktemp=iter.userid;
	 break;
case 3: 
 	 ktemp=iter.isopen;
	 break;
case 4: 
 	 ktemp=iter.level;
	 break;
	  }

 switch(vpos){
case 1: 
 	 a[ktemp].emplace_back(iter.name);
	 break;
case 2: 
 	 a[ktemp].emplace_back(iter.password);
	 break;

                   }
                //a[ktemp].emplace_back(vtemp);
        }       

        return a;
    }
    template<typename T,typename U,typename std::enable_if<std::is_integral_v<T>,bool>::type = true,typename std::enable_if<std::is_floating_point<U>::value,bool>::type = true>    
  std::map<T,std::vector<U>> getgroupCols(std::string keyname,std::string valname){
        std::map<T,std::vector<U>> a;

        unsigned char kpos,vpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);

        T ktemp;
        //U vtemp;

         for(auto &iter:record){
             
                   switch(kpos){

   case 0: 
 	 ktemp=iter.userid;
	 break;
case 3: 
 	 ktemp=iter.isopen;
	 break;
case 4: 
 	 ktemp=iter.level;
	 break;
	  }

 switch(vpos){

                   }
                //a[ktemp].emplace_back(vtemp);
        }       

        return a;
    }
    template<typename T,typename U,typename std::enable_if<std::is_integral_v<T>,bool>::type = true,typename std::enable_if<std::is_integral_v<U>,bool>::type = true>    
  std::map<T,std::vector<U>> getgroupCols(std::string keyname,std::string valname){
        std::map<T,std::vector<U>> a;

        unsigned char kpos,vpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);

        T ktemp;
        //U vtemp;

         for(auto &iter:record){
             
                   switch(kpos){

   case 0: 
 	 ktemp=iter.userid;
	 break;
case 3: 
 	 ktemp=iter.isopen;
	 break;
case 4: 
 	 ktemp=iter.level;
	 break;
	  }

 switch(vpos){
case 0: 
 	 a[ktemp].emplace_back(iter.userid);
	 break;
case 3: 
 	 a[ktemp].emplace_back(iter.isopen);
	 break;
case 4: 
 	 a[ktemp].emplace_back(iter.level);
	 break;

                   }
                //a[ktemp].emplace_back(vtemp);
        }       

        return a;
    }
    template<typename T,typename std::enable_if<std::is_integral_v<T>,bool>::type = true>    
  std::map<T,std::vector<meta>> getgroupRows(std::string keyname){
        std::map<T,std::vector<meta>> a;

        unsigned char kpos;
        kpos=findcolpos(keyname);

        //T ktemp;
        //U vtemp;

         for(auto &iter:record){
             
                   switch(kpos){

   case 0: 
 	 a[iter.userid].emplace_back(iter);
	 break;
case 3: 
 	 a[iter.isopen].emplace_back(iter);
	 break;
case 4: 
 	 a[iter.level].emplace_back(iter);
	 break;

                   }
                //a[ktemp].emplace_back(vtemp);
        }       

        return a;
    }
    template<typename T,typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true>    
  std::map<T,std::vector<meta>> getgroupRows(std::string keyname){
        std::map<T,std::vector<meta>> a;

        unsigned char kpos;
        kpos=findcolpos(keyname);

        //T ktemp;
        //U vtemp;

         for(auto &iter:record){
             
                   switch(kpos){

   case 1: 
 	 a[iter.name].emplace_back(iter);
	 break;
case 2: 
 	 a[iter.password].emplace_back(iter);
	 break;

                   }
                //a[ktemp].emplace_back(vtemp);
        }       

        return a;
    }
    template<typename T,typename U,typename D,typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true, typename std::enable_if<std::is_same<U,std::string>::value,bool>::type = true>    
  std::map<T,std::map<U,std::vector<meta>>> getgroupRows(std::string keyname,std::string valname){
        std::map<T,std::map<U,std::vector<meta>>> a;

        unsigned char kpos,vpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
        T ktemp;

         for(auto &iter:record){
             
                   switch(kpos){

   case 1: 
 	 ktemp=iter.name;
	 break;
case 2: 
 	 ktemp=iter.password;
	 break;
	  }

 switch(vpos){
case 1: 
 	 a[ktemp][iter.name].emplace_back(iter);
	 break;
case 2: 
 	 a[ktemp][iter.password].emplace_back(iter);
	 break;

                   }
                //a[ktemp][vtemp].emplace_back(dtemp);
        }       

        return a;
    }
    template<typename T,typename U,typename std::enable_if<std::is_same<T,std::string>::value,bool>::type = true,typename std::enable_if<std::is_integral_v<U>,bool>::type = true>    
  std::map<T,std::map<U,std::vector<meta>>> getgroupRows(std::string keyname,std::string valname){
        std::map<T,std::map<U,std::vector<meta>>> a;

        unsigned char kpos,vpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
        T ktemp;
        
         for(auto &iter:record){
             
                   switch(kpos){

   case 1: 
 	 ktemp=iter.name;
	 break;
case 2: 
 	 ktemp=iter.password;
	 break;
	  }

 switch(vpos){
case 0: 
 	 a[ktemp][iter.userid].emplace_back(iter);
	 break;
case 3: 
 	 a[ktemp][iter.isopen].emplace_back(iter);
	 break;
case 4: 
 	 a[ktemp][iter.level].emplace_back(iter);
	 break;

                   }
                //a[ktemp][vtemp].emplace_back(dtemp);
        }       

        return a;
    }
    template<typename T,typename U,typename std::enable_if<std::is_integral_v<U>,bool>::type = true,typename std::enable_if<std::is_integral_v<U>,bool>::type = true>    
  std::map<T,std::map<U,std::vector<meta>>> getgroupRows(std::string keyname,std::string valname){
        std::map<T,std::map<U,std::vector<meta>>> a;

        unsigned char kpos,vpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
        T ktemp;
        
         for(auto &iter:record){
             
                   switch(kpos){

   case 0: 
 	 ktemp=iter.userid;
	 break;
case 3: 
 	 ktemp=iter.isopen;
	 break;
case 4: 
 	 ktemp=iter.level;
	 break;
	  }

 switch(vpos){
case 0: 
 	 a[ktemp][iter.userid].emplace_back(iter);
	 break;
case 3: 
 	 a[ktemp][iter.isopen].emplace_back(iter);
	 break;
case 4: 
 	 a[ktemp][iter.level].emplace_back(iter);
	 break;

                   }
                //a[ktemp][vtemp].emplace_back(dtemp);
        }       

        return a;
    }
    template<typename T,typename U,typename std::enable_if<std::is_integral_v<T>,bool>::type = true,typename std::enable_if<std::is_same<U,std::string>::value,bool>::type = true>    
  std::map<T,std::map<U,std::vector<meta>>> getgroupRows(std::string keyname,std::string valname){
        std::map<T,std::map<U,std::vector<meta>>> a;

        unsigned char kpos,vpos;
        kpos=findcolpos(keyname);
        vpos=findcolpos(valname);
        T ktemp;
        
         for(auto &iter:record){
             
                   switch(kpos){

   case 0: 
 	 ktemp=iter.userid;
	 break;
case 3: 
 	 ktemp=iter.isopen;
	 break;
case 4: 
 	 ktemp=iter.level;
	 break;
	  }

 switch(vpos){
case 1: 
 	 a[ktemp][iter.name].emplace_back(iter);
	 break;
case 2: 
 	 a[ktemp][iter.password].emplace_back(iter);
	 break;

                   }
                //a[ktemp][vtemp].emplace_back(dtemp);
        }       

        return a;
    }
};
 } 
}
#endif
   