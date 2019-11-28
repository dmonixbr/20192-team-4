#ifndef FUNCOES_GLOBAIS_H
#define FUNCOES_GLOBAIS_H

#include "../include/lista.hpp"

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
    	const char* caminho;
    	DataBase();
    	~DataBase();
    	static void SalvarDB();

    private:
    	sqlite3* banco;
    };
}
#endif