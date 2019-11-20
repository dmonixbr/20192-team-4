#include "../include/funcoes.hpp"
#include <stdexcept>

void CrudUsuario(){

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
            AuxCrud(&aux_acesso);
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

//funcao auxiliar para crud
void AuxCrud(int *aux_acesso){
    if(*aux_acesso != 1 && *aux_acesso !=2 && *aux_acesso !=0){
        throw "Ops, voce digitou um numero errado!";
    }else{
        if(*aux_acesso == 1){
            LoginAdmin();
            delete aux_acesso;
        }
        else if(*aux_acesso == 2){
            LoginGerente();
            delete aux_acesso;
        }
        else if(*aux_acesso == 0){
            std::cout << "Muito Obrigado!!!" << std::endl;
            std::cout << "Tenha um bom dia!!" << std::endl;
            return;
        }
        else{
            throw "Ocorreu um erro inesperado, e para a sua seguranca o programa vai desligar";
        }
    }
    
}


void LoginAdmin(){
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
void LoginGerente(){
    return;
}
void LoginAux(){
    return;
}