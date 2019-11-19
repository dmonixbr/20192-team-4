#include "../include/gerente.hpp"

Gerente::Gerente(std::string _cpf, std::string _nome, std::string _senha ,std::string _periodo_mandato, std::string _endereco, std::string _telefone, int id){
    this->cpf = _cpf;
    this->nome = _nome;
    this->senha = _senha;
    this->periodo_mandato = _periodo_mandato;
    this->endereco = _endereco;
    this->telefone = _telefone;
    this->id = id;
}


//setters
void Gerente::set_periodo_mandato(std::string _periodo_mandato){
     this->periodo_mandato = _periodo_mandato;
}

void Gerente::set_endereco(std::string _endereco){
     this->endereco = _endereco;
}

void Gerente::set_telefone(std::string _telefone){
     this->telefone = _telefone;
}

//getters
std::string Gerente::get_periodo_mandato(){
    return this->periodo_mandato;
}

std::string Gerente::get_endereco(){
    return this->endereco;
}

std::string Gerente::get_telefone(){
    return this->telefone;
}
/*int Gerente::get_id(){
    return this->id;
}*/



