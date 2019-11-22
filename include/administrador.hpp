#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "usuario.hpp"

class Administrador : public Usuario{

    public:
        Administrador();

        std::string get_cpf();
		void set_cpf(std::string);
		std::string get_nome();
		void set_nome(std::string);
		std::string get_senha();
		void set_senha(std::string);
        void Login(std::string) override;
        void Deslogar() override;

    private:

        
        void CadastrarCreche(std::string,std::string,std::string,std::string);
        void VerCreche ();
        void EditarCreche();
        void DeletarCreche ();
        void CadastrarGerente();
        void GerarRelatorioAnual ();
        void GerarRelatorioTrimestral ();


};

#endif