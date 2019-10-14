#ifndef BANCO_H
#define BANCO_H
#include <iostream>
#include <sqlite3.h>

static int callback(void* data, int argc, char** argv, char** azColName) { 
    int i; 
    fprintf(stderr, "%s\n", (const char*)data); 
  
    for (i = 0; i < argc; i++) { 
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
    } 
  
    printf("\n"); 
    return 0; 
} 

class Database{
public:
	std::string caminho;
	sqlite3* banco; 


	Database(const char* _caminho){
	    int status = 0; 
	    status = sqlite3_open(_caminho, &banco); 
	  
	    if (status) { 
	        std::cerr << "Error open DB " << sqlite3_errmsg(banco) << std::endl; 
	    } 
	};

	~Database(){
		sqlite3_close(banco);
	}

	sqlite3* getBanco(){
		return banco;
	}
	
};

#endif