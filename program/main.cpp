#include <iostream>
#include "../include/gerente.hpp"
#include "../include/administrador.hpp"
#include "../include/creche.hpp"
#include "../include/usuario.hpp"
#include "../include/lista.hpp"
#include "../include/globais.hpp"

ListaGerentes listaG;
ListaAdmins listaA;
Administrador *SessaoAdmin;
Gerente *SessaoGerente;


int main(){
    system("clear");
    /*---------------------Criando Administrador super--------------*/
    Administrador *Super = new Administrador();
    Super->set_nome("super");
    Super->set_cpf("00000000000");
    Super->set_senha("super");
    listaA.insere_admin(Super);
    

    
    gmu::MenuFunc::MenuPrincipal();
}