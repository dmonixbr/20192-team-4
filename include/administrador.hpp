#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "usuario.hpp"

class Administrador : public Usuario{

    public:
        Administrador();
        Administrador(std::string,std::string,std::string);

        std::string get_cpf();
		void set_cpf(std::string);
		std::string get_nome();
		void set_nome(std::string);
		std::string get_senha();
		void set_senha(std::string);
        void Login(std::string) override;
        void Deslogar() override;
        void ListarAdmins();
        

    private:

        
        void CadastrarCreche(); //OK
        void VerCreche (); //OK
        void EditarCreche();    
        void DeletarCreche ();  
        void CadastrarGerente();  //OK
        void GerarRelatorioAnual ();  
        void GerarRelatorioTrimestral ();
        int Menu();
        int ListarGerentes();
        void ListarCreches();
        void EditarGerente();
        void EditarDados() override;  //OK
        void CadastrarAdmin();  //OK
        void VerDados() override; //OK

};

#endif