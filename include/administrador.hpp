
#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "usuario.hpp"

class Administrador : public Usuario{

    private:

    public:

        Administrador(std::string,std::string,std::string);
    
        void CadastrarCreche ();
        void VerCreche ();
        void EditarCreche();
        void DeletarCreche ();
        void CadastrarGerente();
        void GerarRelatorioAnual ();
        void GerarRelatorioTrimestral ();

        std::string get_cpf();
		void set_cpf(std::string);
		std::string get_nome();
		void set_nome(std::string);
		std::string get_senha();
		void set_senha(std::string);
        void login(std::string, std::string);




};

#endif
