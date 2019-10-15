#ifndef BANCO_H
#define BANCO_H
#include <iostream>
#include <sqlite3.h>
#include <list>
#include <map> 


class Database{
public:
	std::string caminho;
	sqlite3* banco;

	std::list<std::string> lista; 

static int callback(void* data, int argc, char** argv, char** azColName) { 
    int i; 
    fprintf(stderr, "%s\n", (const char*)data); 
	std::list<std::string> lista;

    for (i = 0; i < argc; i++) { 
    //    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL" ); 
        lista.push_back(argv[i] ? argv[i] : "NULL");
    } 
  
 	return 0;
} 

	Database(const char*);
	~Database();
	sqlite3* getBanco();
	void inserirDados(std::string, std::map<std::string, std::string>);
	std::list<std::string> verDados(std::string, std::string);
	void editarDados(std::string, std::string, std::map<std::string, std::string>);
	void deletarDados(std::string, std::string);	
};

#endif