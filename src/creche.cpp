#include "../include/creche.hpp"
#include <iostream>

Creche::Creche(std::string _nome, std::string _telefone, std::string _endereco, std::string _validate_convenio, int id_gerente){
    this->nome = _nome;
    this->telefone = _telefone;
    this->endereco = _endereco;
    this->validade_convenio = _validate_convenio;
    this->pos_gerente = id_gerente;
}


//setters
void Creche::set_nome(std::string _nome){
    this->nome = _nome;
}
void Creche::set_telefone(std::string _telefone){
    this->telefone = _telefone;
}
void Creche::set_endereco(std::string _endereco){
    this->endereco = _endereco;
}

//getters
std::string Creche::get_nome(){
    return this->nome;
}
std::string Creche::get_endereco(){
    return this->endereco;
}
std::string Creche::get_telefone(){
    return this->telefone;
}
