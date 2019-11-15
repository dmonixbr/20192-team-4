#ifndef ADMIN_H
#define ADMIN_H
#include 'usuario.hpp'

class Admin :: public Usuario{

    private:

    public:
    
    void CadastrarCreche (string, int, int);
    void VerCreche ();
    void EditarCreche();
    void DeletarCreche ();
    void CadastrarGerente();
    void GerarRelatorioAnual ();
    void GerarRelatorioTrimestral ();


};



#endif