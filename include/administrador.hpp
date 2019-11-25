#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "usuario.hpp"

class Administrador : public Usuario{

    public:
        Administrador();
        Administrador(std::string,std::string,std::string);

        std::string get_cpf(); //OK
		void set_cpf(std::string); //OK
		std::string get_nome(); //OK
		void set_nome(std::string); //OK
		std::string get_senha(); //OK
		void set_senha(std::string); //OK
        void Login(std::string) override; //OK
        void Deslogar() override; //OK
        void ListarAdmins(); //OK
        

    private:

        
        void CadastrarCreche(); //OK
        void VerCreche (int);   //OK
        void EditarCreche();  //OK
        void EditarGerente(); //OK
        void DeletarCreche ();  //Aconselho fazer dentro do editar creche como eu fiz em editar gerente
        void CadastrarGerente(); //OK
        void GerarRelatorioAnual (); 
        int Menu(); //OK
        int ListarGerentes(); //OK
        int ListarCreches(bool); //OK
        void EditarDados() override; //OK
        void CadastrarAdmin();  //OK
        void VerDados() override; //OK

};

#endif