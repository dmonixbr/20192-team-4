#include "../include/administrador.hpp"
#include "../include/usuario.hpp"
#include "../include/lista.hpp"


Administrador::Administrador(){
    this->nome = "";
    this->cpf = "";
    this->senha = "";
}
Administrador::Administrador(std::string nome,std::string cpf,std::string senha){
    this->nome = nome;
    this->cpf = cpf;
    this->senha = senha;
}

//setters
void Administrador::set_nome(std::string _nome){
    this->nome = _nome;
}
void Administrador::set_cpf(std::string _cpf){
    this->cpf = _cpf;
}

void Administrador::set_senha(std::string _senha){
    this->senha = _senha;
}

//getters
std::string Administrador::get_nome(){
    return this->nome;
}
std::string Administrador::get_cpf(){
    return this->cpf;
}
std::string Administrador::get_senha(){
    return this->senha;
}

//funcao para logar no sistema
void Administrador::Login(std::string _cpf){
    int i;
    std::string senha;
    extern ListaAdmins listaA;
    admins *atual = listaA.primeiro;
    for (i=0; i<listaA.tamanho(); i++){
        if (atual->admin->cpf == _cpf ){
            std::cout << "Digite a senha: \n";
            std::cin >> senha;
            if (atual->admin->senha == senha){
                std::cout << "\n\nVocê entrou!\n\n" << std::endl;
            }

        }
        else if (atual->proximo == nullptr){
            std::cout << "Não existe usuário associado à este CPF." << std::endl;
        }
        else{
            atual = atual->proximo;
        }

    }
}

void Administrador::Deslogar(){
    
}






