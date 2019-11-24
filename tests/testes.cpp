
#include "doctest.h"

#include "../include/usuario.hpp"
#include "../include/administrador.hpp"
#include "../include/gerente.hpp"
#include "../include/creche.hpp"
#include "../include/lista.hpp"
#include "../include/globais.hpp"

#include <string.h>
#include <iostream>
#include <math.h>

Administrador *SessaoAdmin;
/*Listas vazias para testes*/
ListaGerentes listaG;
ListaAdmins listaA;
ListaCreches listaC;
/*-------------------------*/

/* 
--------------------- Teste funcoes e construtor administrador--------------------------------
*/
TEST_CASE("01 - Teste contrutor administrador"){
    CHECK_NOTHROW(Administrador Admin("Joao","14067737602","1234"));
    CHECK_NOTHROW(Administrador Admin2("Lucas", "14234533221", "mjss12332"));
}

TEST_CASE("02 - Teste getters e setters Administrador"){
    //construindo administradores para os testes
    Administrador *Admin1 = new Administrador("Luis", "123536345", "1234");
    Administrador  Admin2("lucas", "12253452341231", "dkkd123142");
    Administrador *Admin3 = new Administrador("gabriel", "1234542224", "sdsdawddwwa");


    //Getters
    CHECK(Admin1->get_cpf()== "123536345");
    CHECK(Admin1->get_nome()=="Luis");
    CHECK(Admin1->get_senha()=="1234");
    CHECK(Admin2.get_cpf()== "12253452341231");
    CHECK(Admin2.get_nome()=="lucas");
    CHECK(Admin2.get_senha()=="dkkd123142");

    //Setters
    Admin3->set_cpf("12345678");
    Admin3->set_nome("Roberto");
    Admin3->set_senha("jgg1234");

    Admin2.set_cpf("14067737602");
    Admin2.set_nome("Gabriel");
    Admin2.set_senha("14072000");

    CHECK(Admin3->get_cpf()=="12345678");
    CHECK(Admin3->get_nome()=="Roberto");
    CHECK(Admin3->get_senha()=="jgg1234");

    CHECK(Admin2.get_cpf()=="14067737602");
    CHECK(Admin2.get_nome()=="Gabriel");
    CHECK(Admin2.get_senha()=="14072000");  
}

/*--------------- testando lista --------------------*/

TEST_CASE("Teste inserir na lista"){
    Administrador admin1("teste1","1234567","1234567");
    Creche creche1("creche1","1234567","1234567","00000");
    Gerente gerente1("gerente1","1234567","1234567","000","000","000");

    listaA.insere_admin(&admin1);
    listaG.insere_gerente(&gerente1);
    listaC.insere_creche(&creche1);

    CHECK(listaA.get_admin(0)->get_cpf() == "1234567");
    CHECK(listaC.get_creche(0)->get_nome() == "creche1");
    CHECK(listaG.get_gerente(0)->get_senha() == "1234567");

    admin1.set_cpf("0000000");
    gerente1.set_telefone("3199999999");
    creche1.set_validade_convenio("000000");

    CHECK(listaG.get_gerente(0)->get_telefone() == "3199999999");
    CHECK(listaC.get_creche(0)->get_validade_convenio() == "000000");
    CHECK(listaA.get_admin(0)->get_cpf() == "0000000");

    Administrador *admin2 = new Administrador();
    Creche *creche2 = new Creche();
    Gerente *gerente2 = new Gerente();

    creche2->set_nome("teste1");
    admin2->set_senha("123456");
    gerente2->set_periodo_mandato("31");

    listaA.insere_admin(admin2);
    listaC.insere_creche(creche2);
    listaG.insere_gerente(gerente2);

    CHECK(listaG.get_gerente(1)->get_periodo_mandato() == "31");
    CHECK(listaC.get_creche(1)->get_nome() == "teste1");
    CHECK(listaA.get_admin(1)->get_senha() == "123456");

    CHECK(listaG.numero_de_gerentes == 2);
    CHECK(listaA.numero_de_admins == 2);
    CHECK(listaC.numero_de_creches == 2);

    Administrador *admin3 = new Administrador();
    listaA.insere_admin(admin3);
    Creche *creche3 = new Creche();
    listaC.insere_creche(creche3);

    listaG.remover_ultimo();
    listaC.remover_creche(1);

    CHECK(listaG.tamanho() == 1);
    CHECK(listaC.tamanho() == 2);
}



