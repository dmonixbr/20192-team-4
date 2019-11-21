#include <iostream>
#include "../include/gerente.hpp"
#include "../include/administrador.hpp"
#include "../include/creche.hpp"
#include "../include/usuario.hpp"
#include "../include/funcoes.hpp"

Administrador A1("Gabriel","12345678","1234",1);

int main(){
    /*-------------Testes do programa----------------*/
    
    
    std::cout << A1.get_nome() << std::endl;
    


    std::cout << "Bem vindo cornos" << std::endl;
    /*---------------Crud Usuarios------------------*/

    int autenticacao = CrudUsuario();

    MenuPrincipal(autenticacao);


}