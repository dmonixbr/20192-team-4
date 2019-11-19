#include "../include/administrador.hpp"
#include "../include/usuario.hpp"

Administrador::Administrador(std::string _nome, std::string _cpf, std::string _senha, int _id){
    this->nome = _nome;
    this->cpf = _cpf;
    this->senha = _senha;
    this->id = id;
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
void Administrador::login(std::string _cpf, std::string _senha){
    if(_cpf == this->cpf && _senha == this->senha){
        std::cout << "Logado com sucesso!" << std::endl;
    }
    else
        std::cout << "Senha e ou usuario incorreto" << std::endl;
}

//funcao cadastrar uma creche


