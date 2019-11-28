#ifndef FUNCOES_GLOBAIS_H
#define FUNCOES_GLOBAIS_H

#include "../include/lista.hpp"
#include <list>

extern "C"{
    #include "../sqlite/sqlite3.h"
}

namespace gmu{

    class MenuFunc{
        public:
            static void MenuPrincipal();
            static bool ValidaCpfGerente(std::string);
            static bool ValidaCpfAdmin(std::string);
            static void Fechar();
    };

    class DataBase{
    public:
        static std::list<std::string> lista; 
        static std::string INFO;
        sqlite3* banco;
    	
        DataBase();
    	~DataBase();
        static int callback(void* data, int argc, char** argv, char** azColName) { 
            int i; 
            //fprintf(stderr, "%s\n", (const char*)data); 
            for (i = 0; i < argc; i++) { 
                //printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL" ); 
               //lista.push_back(argv[i] ? argv[i] : "NULL");
                INFO = INFO + "\n" + (argv[i] ? argv[i] : "NULL");
            } 
            return 0;
        } 
        void AbrirDB();
    	void SalvarDB();

    };
}
#endif