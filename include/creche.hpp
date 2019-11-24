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

        Creche(std::string,std::string,std::string,std::string, int);

        //getters
        std::string get_nome();
        std::string get_telefone();
        std::string get_endereco();
        std::string get_validade_convenio();
        int get_pos_gerente();


        //setters
        void set_nome(std::string);
        void set_telefone(std::string);
        void set_endereco(std::string);
        void set_validade_convenio(std::string);
};

#endif
