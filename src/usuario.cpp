<<<<<<< HEAD
#include "../include/usuario.hpp"



void Usuario::set_nome(std::string _nome){
    this->nome = _nome;
}

void Usuario::set_cpf(std::string _cpf){
    this->cpf = _cpf;
}

void Usuario::set_senha(std::string _senha){
    this->senha = _senha;

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
>>>>>>> 3f0aa3f03a2dd117e9036565dc84a37f2e0bedff
}