#include "../include/administrador.hpp"
#include "../include/creche.hpp"
#include "../include/usuario.hpp"
#include "../include/lista.hpp"
#include "../include/globais.hpp"

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
    extern ListaAdmins listaA;
    admins *atual = listaA.primeiro;
    extern Administrador *SessaoAdmin;
    SessaoAdmin = atual->admin;

    while(1){
        system("clear");
        std::cout << "Digite o numero da funcao que voce quer fazer:" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - Cadastrar uma nova creche"<<std::endl; 
        std::cout << "2 - Ver creches"<<std::endl;
        std::cout << "3 - Cadastrar um novo gerente" << std::endl;
        std::cout << "4 - Listar gerentes cadastrados" << std::endl;
        std::cout << "0 - Sair"<<std::endl;

        try{
            int aux_acesso;
            std::cin >> aux_acesso;
            if(aux_acesso != 1 && aux_acesso !=2 && aux_acesso !=3 && aux_acesso != 4 && aux_acesso !=0){
                throw "Ops, voce digitou um numero errado!";
            }
            else{
                if(aux_acesso == 1){
                    system("clear");
                    SessaoAdmin->CadastrarCreche();

                }

                else if(aux_acesso == 2){
                    system("clear");
                    SessaoAdmin->ListarCreches();
                    return 0;
                }

                else if(aux_acesso == 3){
                    system("clear");
                    SessaoAdmin->CadastrarGerente();
                }

                else if(aux_acesso == 4){
                    SessaoAdmin->ListarGerentes();
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
            else{
                std::cout << "Voce digitou a senha incorretamente" << std::endl;
                gmu::MenuFunc::MenuPrincipal();
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


void Administrador::Deslogar(){
    std::cout << "Tem certeza que deseja deslogar? (Y/N)" << std::endl;
    std::string opt;
    std::cin >> opt;
    extern Administrador *SessaoAdmin;
    if (opt == "y" || opt == "Y"){
        gmu::MenuFunc::MenuPrincipal();
    }else if (opt == "n" || opt == "N"){
        SessaoAdmin->Menu();
    }
    else{
        std::cout << "Você digitou uma opção errada" << std::endl;
    }
}

void  Administrador::CadastrarGerente(){
    extern ListaGerentes listaG;
    extern ListaAdmins listaA;
    admins *atual = listaA.primeiro;
    extern Administrador *SessaoAdmin;
    SessaoAdmin = atual->admin;

    std::string _cpf_gerente;
    std::string _nome_gerente;
    std::string _senha_gerente;
    std::string _endereco_gerente;
    std::string _telefone_gerente;
    system("clear");

    std::cout << "--------------------------------Cadastro de Gerente---------------------------\n\nDigite o CPF do Gerente:" << std::endl;
    std::cin >> _cpf_gerente;
    std::cout << "Digite o nome do Gerente:" << std::endl;
    std::cin >> _nome_gerente;
    std::cout << "Digite a senha do gerente:" << std::endl;
    std::cin >> _senha_gerente;
    std::cout << "Digite o endereco do gerente:" << std::endl;
    std::cin >> _endereco_gerente;
    std::cout << "Digite o telefone do gerente:" << std::endl;
    std::cin >> _telefone_gerente;

    Gerente *novo_gerente = new Gerente();

    novo_gerente->set_cpf(_cpf_gerente);
    novo_gerente->set_nome(_nome_gerente);
    novo_gerente->set_senha(_senha_gerente);
    novo_gerente->set_endereco(_endereco_gerente);
    novo_gerente->set_telefone(_telefone_gerente);

    listaG.insere_gerente(novo_gerente);

    SessaoAdmin->Menu();
}

void Administrador::CadastrarCreche(){
    extern Administrador SessaoAdmin;
    extern ListaCreches listaC;
    std::string nome;
    std::string endereco;
    std::string telefone;
    std::string validade;
    int gerente;

    system("clear");
    std::cout << "---------------------------- Cadastrar Creche ----------------------------\n\n" << std::endl;
    std::cin.ignore();
    std::cout << "Digite o nome da creche: \n" << std::endl;
    std::getline(std::cin, nome);
    std::cout << "Digite o Endereço da Creche: \n" << std::endl;
    std::getline(std::cin, endereco);
    std::cout << "Digite o telefone da Creche: \n" << std::endl;
    std::getline(std::cin, telefone);
    std::cout << "Selecione o Gerente: \n" << std::endl;
   
    std::cin >> gerente;
    std::cout << "Digite a validade do convênio (DDMMAAAA):" << std::endl;
    std::getline(std::cin, validade);


    Creche *creche = new Creche(nome, telefone, endereco, validade, gerente);
    listaC.insere_creche(creche);

    SessaoAdmin.Menu(); 
}

void Administrador::ListarGerentes(){
    system("clear");
    extern ListaAdmins listaA;
    admins *adm_atual = listaA.primeiro;
    extern Administrador *SessaoAdmin;
    SessaoAdmin = adm_atual->admin;
    extern ListaGerentes listaG;
    gerentes *atual;
    atual = listaG.primeiro;
    if(listaG.tamanho() != 0){
        std::cout << "ID\t\tNome do gerente\t\tTelefone\t\tCreche" << std::endl;
        std::cout << "------------------------------------------------------------------------------" << std::endl;
        for(int i=0;i<listaG.tamanho();i++){
            std::cout << i << "\t\t" << atual->gerente->get_nome() << "\t\t" << atual->gerente->get_telefone() << std::endl;
            atual = atual->proximo;
        }
    }
    else{
        std::cout << "Não há nenhum gerente cadastrado" << std::endl;
    }
    std::cout << "Aperte qualquer tecla para continuar" << std::endl;
    getchar();
    SessaoAdmin->Menu();
}

void Administrador::ListarCreches(){
    system("clear");
    extern ListaGerentes listaG;
    extern ListaCreches listaC;
    extern Administrador SessaoAdmin;

    std::cout << "\n\n---------------------------- Lista de creches ----------------------------\n\n" << std::endl;
    creches *atual;
    atual = listaC.primeiro;
    if(listaC.tamanho() !=0){
        std::cout << "Nome \t\t\t Endereco \t\t\t Telefone \t Validade do convênio \t Nome do Gerente" << std::endl;

    }
}