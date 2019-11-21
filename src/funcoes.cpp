#include "../include/funcoes.hpp"
#include <stdexcept>
#include <iostream>

//retorna 1 ou 2 dependendo de quem estiver logado
int CrudUsuario(){

    //criando o auxiliar de acesso
    int aux_acesso = -1;
    bool aux_permanencia = true;

    std::cout << "------Seja Bem Vindo ao Sistema da creche-------"<<std::endl;
    

    while(aux_permanencia){
        std::cout << "Digite o numero da funcao que voce quer fazer:" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - Login como Administrador"<<std::endl; 
        std::cout << "2 - Login como Gerente da creche"<<std::endl;
        std::cout << "0 - Fechar o programa"<<std::endl;

        std::cin >> aux_acesso;
        try
        {
            return AuxCrud(aux_acesso);
        }
        catch(const char *e)
        {
            std::cerr << e << '\n';
            CrudUsuario();
        }
        catch(...){
            std::cerr << "Erro inesperado" << '\n';
        }
        

        return;
    }
}

//return 2 ou 1 dependendo de quem vai logar
int AuxCrud(int aux_acesso){
    if(aux_acesso != 1 && aux_acesso !=2 && aux_acesso !=0){
        throw "Ops, voce digitou um numero errado!";
    }else{
        if(aux_acesso == 1){
            return LoginAdmin();
        }
        else if(aux_acesso == 2){
            return LoginGerente();
        }
        else if(aux_acesso == 0){
            std::cout << "Muito Obrigado!!!" << std::endl;
            std::cout << "Tenha um bom dia!!" << std::endl;
            return 0;
        }
        else{
            throw "Ocorreu um erro inesperado, e para a sua seguranca o programa vai desligar";
        }
    }
    
}

//Retorna 1 se o gerente logou
int LoginAdmin(){
    std::cout << "Ola admin, seja bem vindo!" << std::endl;
    try
    {
        LoginAux();
    }
    catch(const char *e)
    {
        std::cerr <<e<< '\n';
    }
    
}
// Retorna 2 se o gerente logou
int LoginGerente(){
    return;
}

int LoginAux(){
    return;
}