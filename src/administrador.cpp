#include "../include/administrador.hpp"
#include "../include/usuario.hpp"
#include "../include/lista.hpp"

extern int MenuPrincipal();

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
int Administrador::Menu(){

    extern Administrador *SessaoAdmin;

    while(1){
        system("clear");
        std::cout << "Digite o numero da funcao que voce quer fazer:" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - Cadastrar uma nova creche"<<std::endl; 
        std::cout << "2 - Ver creches"<<std::endl;
        std::cout << "0 - Sair"<<std::endl;

        try{
            int aux_acesso;
            std::cin >> aux_acesso;
            if(aux_acesso != 1 && aux_acesso !=2 && aux_acesso !=0){
                throw "Ops, voce digitou um numero errado!";
            }
            else{
                if(aux_acesso == 1){
                    std::string nome, telefone, endereco, validate_convenio;
                    int id_gerente;
                    system("clear");
                    SessaoAdmin->CadastrarCreche();

                }

                else if(aux_acesso == 2){
                    system("clear");
                    std::cout << "\n\n---------------------------- Lista de creches ----------------------------\n\nDigite seu CPF:" << std::endl;;
                    return 0;
                }


                else if(aux_acesso == 0){
                     SessaoAdmin->Deslogar();
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
    extern Administrador *SessaoAdmin;
    admins *atual = listaA.primeiro;
    for (i=0; i<listaA.tamanho(); i++){
        if (atual->admin->cpf == _cpf ){
            std::cout << "Digite a senha: \n";
            std::cin >> senha;
            if (atual->admin->senha == senha){
                std::cout << "\n\nVocê entrou!\n\n" << std::endl;
                SessaoAdmin = atual->admin;
                SessaoAdmin->Menu();
            }

        }
        else if (atual->proximo == nullptr){
            std::cout << "Não existe usuário associado à este CPF." << std::endl;
            MenuPrincipal();
        }
        else{
            atual = atual->proximo;
        }

    }
}


void Administrador::Deslogar(){
    std::cout << "Tem certeza que deseja deslogar? (Y/N)" << std::endl;
    std::string opt;
    std::cin >> opt;
    extern Administrador *SessaoAdmin;
    if (opt == "y" || opt == "Y"){
        MenuPrincipal();
    }else if (opt == "n" || opt == "N"){
        SessaoAdmin->Menu();
    }
    else{
        std::cout << "Você digitou uma opção errada" << std::endl;
    }
}



void Administrador::CadastrarCreche(){
    extern Administrador SessaoAdmin;
    std::string nome, endereco, telefone, validade;
    int gerente;

    system("clear");
    std::cout << "---------------------------- Cadastrar Creche ----------------------------\n\n" << std::endl;
    std::cout << "Digite o nome da creche: \n" << std::endl;
    std::cin >> nome;
    std::cout << "Digite o Endereço da Creche: \n" << std::endl;
    std::cin >> endereco;
    std::cout << "Digite o telefone da Creche: \n" << std::endl;
    std::cin >> telefone;
    std::cout << "Selecione o Gerente: \n" << std::endl;
   
    std::cin >> gerente;
    std::cout << "Digite a validade do convênio (DDMMAAAA):" << std::endl;
    std::cin >> validade;
    Creche creche = Creche(nome, endereco, telefone, validade, gerente);

    SessaoAdmin.Menu(); 
}

void Administrador::ListarGerentes(){

}