<<<<<<< HEAD
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



};


=======
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


>>>>>>> 18853c9a9748ebe69ea7fca11f757c3584c5cac7
#endif