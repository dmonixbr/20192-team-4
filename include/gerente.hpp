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
        void EmitirRelatorio(); 
        void EditarCreche();    
        int Menu();  //OK

        void VerDados() override;  //OK
        void EditarDados() override;  //OK
        
    public:

        Gerente();
        Gerente(std::string,std::string,std::string,std::string,std::string,std::string);

        //getters
        std::string get_telefone();
        std::string get_cpf() override;
        std::string get_periodo_mandato();
        std::string get_nome() override;
        std::string get_endereco();
        std::string get_senha() override;
        

        //setters
        void set_periodo_mandato(std::string);
        void set_endereco(std::string);
        void set_telefone(std::string);
        void set_cpf(std::string) override;
        void set_nome(std::string) override;
        void set_senha(std::string) override;
        void Login(std::string) override;  //OK
};


#endif