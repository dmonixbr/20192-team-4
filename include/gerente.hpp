#ifndef GERENTE_H
#define GERENTE_H
#include "usuario.hpp"

class Gerente : public Usuario {
    private:
        std::string periodo_mandato;
        std::string endereco;
        std::string telefone;
        

        //funcoes creche
        
        void Deslogar() override; //OK
        void EmitirRelatorio(); ///OK
        void EditarCreche(); //OK
        int Menu();  //OK

        void VerDados() override;  //OK
        void EditarDados() override;  //OK
        
    public:

        Gerente();
        Gerente(std::string,std::string,std::string,std::string,std::string,std::string);

        //getters
        std::string get_telefone(); //OK
        std::string get_cpf() override; //OK
        std::string get_periodo_mandato(); //OK
        std::string get_nome() override; //OK
        std::string get_endereco(); //OK
        std::string get_senha() override; //OK
        

        //setters
        void set_periodo_mandato(std::string); //OK
        void set_endereco(std::string); //OK
        void set_telefone(std::string); //OK
        void set_cpf(std::string) override; //OK
        void set_nome(std::string) override; //OK
        void set_senha(std::string) override; //OK

        void Login(std::string) override;  //OK
};


#endif