#include "../include/administrador.hpp"

Administrador::Administrador(std::string _nome, std::string _cpf, std::string _senha): Usuario(_nome, _cpf, _senha){
    this->nome = _nome;
    this->cpf = _cpf;
    this->senha = _senha;
}
    