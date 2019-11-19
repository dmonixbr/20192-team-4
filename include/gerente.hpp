#ifndef GERENTE_H
#define GERENTE_H
#include "usuario.hpp"

class Gerente : public Usuario {
    private:
        std::string periodo_mandato;
        std::string endereco;
        std::string telefone;
    public:

        Gerente(std::string,std::string,std::string,std::string,std::string,std::string,int);

        void set_periodo_mandato(std::string);
        std::string get_periodo_mandato();
        void set_endereco(std::string);
        std::string get_endereco();
        void set_telefone(std::string);
        std::string get_telefone();
    
};


#endif