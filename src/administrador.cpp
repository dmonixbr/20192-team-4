#include "../include/administrador.hpp"
#include "../include/usuario.hpp"
#include "../include/lista.hpp"


Administrador::Administrador(){
    this->nome = "";
    this->cpf = "";
    this->senha = "";
}
Administrador::Administrador(std::string nome,std::string cpf,std::string senha){
    this->nome = nome;
    this->cpf = cpf;
    this->senha = senha;
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


//Função de Menu de Administrador
int MenuAdmin(){

    while(1){
        std::cout << "Digite o numero da funcao que voce quer fazer:" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - Cadastrar uma nova creche"<<std::endl; 
        std::cout << "2 - Ver creches"<<std::endl;
        std::cout << "0 - Voltar para o Menu Anterior"<<std::endl;

        try{
            int aux_acesso;
            std::cin >> aux_acesso;
            if(aux_acesso != 1 && aux_acesso !=2 && aux_acesso !=0){
                throw "Ops, voce digitou um numero errado!";
            }
            else{
                if(aux_acesso == 1){
                    std::cout << "\n\n---------------------------- Cadastrar uma nova creche ----------------------------\n\nDigite seu CPF:" << std::endl;
                    return 0;
                }

                else if(aux_acesso == 2){
                    std::cout << "\n\n---------------------------- Lista de creches ----------------------------\n\nDigite seu CPF:" << std::endl;;
                    return 0;
                }


                else if(aux_acesso == 0){
                     
                    
                }
                else{
                    throw "Ocorreu um erro inesperado, e para a sua seguranca o programa vai desligar";
                }
            }
        }
        catch(const char *e)
        {
            std::cerr << e << '\n';
        }
        catch(...){
            std::cerr << "Erro inesperado" << '\n';
        }
       
        return -1;
    }

}



//funcao para logar no sistema
void Administrador::Login(std::string _cpf){
    int i;
    std::string senha;
    extern ListaAdmins listaA;
    admins *atual = listaA.primeiro;
    for (i=0; i<listaA.tamanho(); i++){
        if (atual->admin->cpf == _cpf ){
            std::cout << "Digite a senha: \n";
            std::cin >> senha;
            if (atual->admin->senha == senha){
                std::cout << "\n\nVocê entrou!\n\n" << std::endl;
                MenuAdmin();
            }

        }
        else if (atual->proximo == nullptr){
            std::cout << "Não existe usuário associado à este CPF." << std::endl;
        }
        else{
            atual = atual->proximo;
        }

    }
}


void Administrador::Deslogar(){
    
}

