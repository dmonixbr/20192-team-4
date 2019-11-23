#ifndef CRECHE_H
#define CRECHE_H
#include <string>
#include <stdio.h>
#include "gerente.hpp"

class Creche {
    private:
        std::string nome;
        std::string telefone;
        std::string endereco;
        std::string validade_convenio;
        int pos_gerente;
    public:

        Creche(std::string,std::string,std::string,std::string,int);

        void set_nome(std::string);
        std::string get_nome();
        void set_telefone(std::string);
        std::string get_telefone();
        void set_endereco(std::string);
        std::string get_endereco();
        void set_validade_convenio(std::string);
};

#endif
