#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "usuario.hpp"

class Administrador : virtual public Usuario{

    private:
        std::string unidade;

    public:

        Administrador(std::string,std::string,std::string);
        
        void CadastrarCreche ();
        void VerCreche ();
        void EditarCreche();
        void DeletarCreche ();
        void CadastrarGerente();
        void GerarRelatorioAnual ();
        void GerarRelatorioTrimestral ();



};


#endif