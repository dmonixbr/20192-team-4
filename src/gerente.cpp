#include "../include/gerente.hpp"
#include "../include/globais.hpp"
#include "../include/lista.hpp"

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
void Gerente::Login(std::string _cpf){
    int i;
    std::string senha;
    extern ListaGerentes listaG;
    extern Gerente *SessaoGerente;
    gerentes *atual = listaG.primeiro;
    for (i=0; i<listaG.tamanho(); i++){
        if (atual->gerente->cpf == _cpf ){
            std::cout << "Digite a senha: \n";
            std::cin >> senha;
            if (atual->gerente->senha == senha){
                std::cout << "\n\nVocê entrou!\n\n" << std::endl;
                SessaoGerente = atual->gerente;
                SessaoGerente->Menu();
            }

        }
        else if (atual->proximo == nullptr){
            std::cout << "Não existe usuário associado à este CPF." << std::endl;
            gmu::MenuFunc::MenuPrincipal();
        }
        else{
            atual = atual->proximo;
        }

    }
}

int Gerente::Menu(){
    extern ListaGerentes listaG;
    gerentes *atual = listaG.primeiro;
    extern Gerente *SessaoGerente;
    SessaoGerente = atual->gerente;

    while(1){
        system("clear");
        std::cout << "Digite o numero da funcao que voce quer fazer:" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - Emitir relatorio de minha creche"<<std::endl; 
        std::cout << "2 - Editar minha creche"<<std::endl;
        std::cout << "0 - Sair"<<std::endl;

        try{
            int aux_acesso;
            std::cin >> aux_acesso;
            if(aux_acesso != 1 && aux_acesso !=2 && aux_acesso !=0){
                throw "Ops, voce digitou um numero errado!";
            }
            else{
                if(aux_acesso == 1){
                    system("clear");
                }
            }
        }
    }
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



