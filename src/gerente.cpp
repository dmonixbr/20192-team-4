#include "../include/gerente.hpp"

Gerente::Gerente(){
    this->cpf = "";
    this->nome = "";
    this->senha = "";
    this->periodo_mandato = "";
    this->endereco = "";
    this->telefone = "";
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

void Gerente::set_cpf(std::string){
    
}

void Gerente::set_nome(std::string){
    
}

void Gerente::set_senha(std::string){
    
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

std::string Gerente::get_cpf(){
    return "ola";
}

std::string Gerente::get_nome(){
    return "mundo";
}

std::string Gerente::get_senha(){
    return "!";
}


//Metodos
void Gerente::Login(std::string){

}



