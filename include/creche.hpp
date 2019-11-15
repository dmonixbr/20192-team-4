#ifndef CRECHE_H
#define CRECHE_H
#include <streamio>

class Creche {
    private:
        std::string nome;
        std::string telefone;
        std::string endereco;
        std::string validade_convenio;
    public:

        Creche(std::string,std::string,std::string,std::string);

        void set_nome(std::string);
        std::string get_nome();
        void set_telefone(std::string);
        std::string get_telefone();
        void set_endereco(std::string);
        std::string get_endereco();
        void set_validade_convenio(std::string);
};

#endif
