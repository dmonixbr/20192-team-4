#include "../include/usuario.hpp"

Usuario::Usuario(std::string _nome, std::string _cpf, std::string _senha){
    this->nome = _nome;
    this->cpf = _cpf;
    this->senha = _senha;
}

void Usuario::set_nome(std::string _nome){
    this->nome = _nome;
}

void Usuario::set_cpf(std::string _cpf){
    this->cpf = _cpf;
}

void Usuario::set_senha(std::string _senha){
    this->senha = _senha;
}