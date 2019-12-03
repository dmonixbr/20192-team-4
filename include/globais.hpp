#ifndef FUNCOES_GLOBAIS_H
#define FUNCOES_GLOBAIS_H

#include "../include/lista.hpp"
#include <list>

extern "C"{
    #include "../sqlite/sqlite3.h"
}


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
        static int callback(void*, int, char**, char**); 
        void AbrirDB();
    	void SalvarDB();

    };
#endif