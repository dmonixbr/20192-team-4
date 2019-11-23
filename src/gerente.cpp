#include "../include/gerente.hpp"
#include "../include/globais.hpp"

extern int MenuPrincipal();

Gerente::Gerente(){
    this->cpf = "0";
    this->nome = "0";
    this->senha = "0";
    this->periodo_mandato = "0";
    this->endereco = "0";
    this->telefone = "0";
}
Gerente::Gerente(std::string cpf,std::string nome,std::string senha,std::string periodo_mandato,std::string endereco,std::string telefone){
    this->cpf = cpf;
    this->nome = nome;
    this->senha = senha;
    this->periodo_mandato = periodo_mandato;
    this->endereco = endereco;
    this->telefone = telefone;
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

void Gerente::set_cpf(std::string cpf){
    this->cpf = cpf;
}

void Gerente::set_nome(std::string nome){
    this->nome = nome;
}

void Gerente::set_senha(std::string senha){
    this->senha = senha;
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
    return this->cpf;
}

std::string Gerente::get_nome(){
    return this->nome;
}

std::string Gerente::get_senha(){
    return this->senha;
}


//Metodos
void Gerente::Login(std::string){

}

int Gerente::Menu(){

}

void Gerente::Deslogar(){
    std::cout << "Tem certeza que deseja deslogar? (Y/N)" << std::endl;
    std::string opt;
    std::cin >> opt;
    extern Gerente *SessaoGerente;
    if (opt == "y" || opt == "Y"){
        gmu::MenuFunc::MenuPrincipal();
    }else if (opt == "n" || opt == "N"){
        SessaoGerente->Menu();
    }
    else{
        std::cout << "Você digitou uma opção errada" << std::endl;
    }
}



