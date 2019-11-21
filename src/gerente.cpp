#include "../include/gerente.hpp"

Gerente::Gerente(){
    this->cpf = "";
    this->nome = "";
    this->senha = "";
    this->periodo_mandato = "";
    this->endereco = "";
    this->telefone = "";
    this->id = -1;
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



