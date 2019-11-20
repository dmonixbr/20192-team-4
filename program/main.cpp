#include <iostream>
#include "../include/gerente.hpp"
#include "../include/administrador.hpp"
#include "../include/creche.hpp"
#include "../include/usuario.hpp"
#include "../include/funcoes.hpp"


int main(){
    /*-------------Testes do programa----------------*/
    int aux_id = 1;
    Administrador A1("Gabroel","12345678","1234",aux_id);
    aux_id++;

    std::cout << A1.get_nome() << std::endl;
    


    std::cout << "Bem vindo cornos" << std::endl;
    /*---------------Crud Usuarios------------------*/

    CrudUsuario();


}