#ifndef GERENTE_H
#define GERENTE_H
#include "usuario.hpp"

class Gerente : public Usuario {
    private:
        std::string periodo_mandato;
        std::string endereco;
        std::string telefone;
    public:

        Gerente();

        void set_periodo_mandato(std::string);
        std::string get_periodo_mandato();
        void set_endereco(std::string);
        std::string get_endereco();
        void set_telefone(std::string);
        std::string get_telefone();
        std::string get_cpf() override;
        void set_cpf(std::string) override;
        std::string get_nome() override;
        void set_nome(std::string) override;
        std::string get_senha() override;
        void set_senha(std::string) override;
        void Login(std::string) override;
};


#endif