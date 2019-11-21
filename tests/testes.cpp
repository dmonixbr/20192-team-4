
#include "doctest.h"

#include "../include/usuario.hpp"
#include "../include/administrador.hpp"
#include "../include/gerente.hpp"
#include "../include/creche.hpp"

#include <string.h>
#include <iostream>
#include <math.h>

/* 
--------------------- Teste funcoes e construtor administrador--------------------------------
*/
TEST_CASE("01 - Teste contrutor administrador"){
    CHECK_NOTHROW(Administrador Admin("Joao","14067737602","1234",4));
    CHECK_NOTHROW(Administrador Admin2("Lucas", "14234533221", "mjss12332",6));
}

TEST_CASE("02 - Teste getters e setters Administrador"){
    //construindo administradores para os testes
    Administrador *Admin1 = new Administrador("Luis", "123536345", "1234",1);
    Administrador Admin2("lucas", "12253452341231", "dkkd123142",2);
    Administrador *Admin3 = new Administrador("gabriel", "1234542224", "sdsdawddwwa",3);


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

