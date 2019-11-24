
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
        std::cout << "5 - Editar meus proprios dados" << std::endl;
        std::cout << "6 - Cadastrar novo administrador ao sistema" << std::endl;
        std::cout << "7 - Listar administradores do sistema" << std::endl;
        std::cout << "0 - Sair"<<std::endl;

        try{
            int aux_acesso;
            std::cin >> aux_acesso;
            if(aux_acesso != 1 && aux_acesso !=2 && aux_acesso !=3 && aux_acesso != 4 && aux_acesso != 5 && aux_acesso != 6 && aux_acesso != 7 && aux_acesso !=0){
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
                    system("clear");
                    SessaoAdmin->ListarGerentes();
                }

                else if(aux_acesso == 5){
                    SessaoAdmin->EditarAdmin("","","");
                }

                else if(aux_acesso == 6){
                    SessaoAdmin->CadastrarAdmin();
                }
                else if(aux_acesso == 7){
                    SessaoAdmin->ListarAdmins();
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
            std::cin.ignore();
            std::getline(std::cin, senha);
            if (atual->admin->senha == senha){
                system("clear");
                SessaoAdmin = atual->admin;
                std::cout << "\n\nVocê entrou!\n\n" << "Seja bem vindo," << SessaoAdmin->nome << "!" << std::endl;
                std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(2));
                SessaoAdmin->Menu();
            }else{
                std::cout << "Você digitou a senha incorreta. Tente novamente." << std::endl;
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
    std::cin.ignore();
    std::string opt;
    std::getline(std::cin, opt);
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
    std::cin.ignore();
    std::getline(std::cin, _cpf_gerente);
    std::cout << "Digite o nome do Gerente:" << std::endl;
    std::getline(std::cin, _nome_gerente);
    std::cout << "Digite a senha do gerente:" << std::endl;
    std::getline(std::cin, _senha_gerente);
    std::cout << "Digite o endereco do gerente:" << std::endl;
    std::getline(std::cin, _endereco_gerente);
    std::cout << "Digite o telefone do gerente:" << std::endl;
    std::getline(std::cin, _telefone_gerente);

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
    std::cout << "Digite o ID do Gerente: \n" << std::endl;
    SessaoAdmin.ListarGerentes();
    std::cin >> gerente;
    std::cin.ignore();
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
        std::cout << "Lista de Gerentes" << std::endl;
        std::cout << "------------------------------------------------------------------------------" << std::endl;
        for(int i=0;i<listaG.tamanho();i++){
            std::cout << "ID: " << i << "\nNome: " << atual->gerente->get_nome() << "\nTelefone: " << atual->gerente->get_telefone() << "Endereco: " << atual->gerente->get_endereco() << std::endl;
            std::cout << "------------------------------------------------------------------------------" << std::endl;
            atual = atual->proximo;
        }
        

    }
    else{
        std::cout << "Não há nenhum gerente cadastrado" << std::endl;
    }
    std::cout << "Tecle 1 para cadastrar novo gerente ou 0 para voltar ao menu." << std::endl;
    int a = 2;
    while (a =2){
        std::cin >> a;
        if (a == 1){
            SessaoAdmin->CadastrarGerente();
        }else if(a == 0){
            SessaoAdmin->Menu();
        }else{
            std::cout << "Você digitou uma opção inválida! Tente Novamente!" << std::endl;
        }
    }
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
        std::cout << std::left << std::setw(20) << "Nome" << std::setw(40) << "Endereço" << std::setw(20) << "Telefone" << std::setw(30) << "Gerente"  << std::setw(30) << "Validade do Convênio" << std::endl;
        std::cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
        for (int i=0; i<listaC.tamanho(); i++){
            std::cout << std::left << std::setw(20) << atual->creche->get_nome() << std::setw(40) << atual->creche->get_endereco() << std::setw(20) << atual->creche->get_telefone() << std::setw(30) 
            << listaG.get_gerente(atual->creche->get_pos_gerente())->get_nome() << std::setw(30) << atual->creche->get_validade_convenio() << std::endl;
            atual = atual->proximo;
        }
    }
}
void Administrador::EditarAdmin(std::string _nome,std::string _cpf, std::string _senha){
    std::string cpf = _cpf,
                nome = _nome,
                senha = _senha;
    std::cout << "\n\n ----------Editar meus dados--------------\n\n";
    //std::cin.ignore();
    extern ListaAdmins listaA;
    admins *atual = listaA.primeiro;
    extern Administrador *SessaoAdmin;
    SessaoAdmin = atual->admin;


    while(1){
        system("clear");
        std::cout <<"Digite o numero do dado que voce deseja editar\n"<<std::endl;
        std::cout << "1 - Editar Nome" << std::endl;
        std::cout << "2 - Editar CPF" << std::endl;
        std::cout << "3 - Editar senha" << std::endl;
        std::cout << std::endl;
        std::cout << "4 - Sair e salvar           0 - Sair sem salvar" << std::endl;

        try{
            int aux_acesso;
            std::cin >> aux_acesso;
            if(aux_acesso != 1 && aux_acesso != 2 && aux_acesso != 3 && aux_acesso != 4 && aux_acesso != 0){
                throw "Ops, voce digitou um numero errado";    
            }
            else{
                //editar nome
                if(aux_acesso == 1){
                    std::cin.ignore();
                    std::cout << "Digite o novo nome:" << std::endl;
                    std::getline(std::cin, nome);
                    SessaoAdmin->EditarAdmin(nome,"","");
                }
                //editar cpf
                else if(aux_acesso == 2){
                    std::cin.ignore();
                    std::cout << "Digite o novo cpf:" << std::endl;
                    std::getline(std::cin, cpf);
                    SessaoAdmin->EditarAdmin("",cpf,"");
                }
                //editar senha
                else if(aux_acesso == 3){
                    std::cin.ignore();
                    std::cout << "Digite a nova senha: " << std::endl;
                    std::getline(std::cin, senha);
                    SessaoAdmin->EditarAdmin("","",senha);
                }
                
                //sair e salvar
                else if(aux_acesso == 4){
                    SessaoAdmin->set_cpf(cpf);
                    SessaoAdmin->set_nome(nome);
                    SessaoAdmin->set_senha(senha);
                    SessaoAdmin->Menu();
                }

                //sair sem salvar
                else if(aux_acesso == 0){
                    SessaoAdmin->Menu();
                }
            }
        }
        catch(const char *e){
            std::cerr << e << '\n';
        }
        catch(...){
        std::cerr << "Erro inesperado" << '\n';
        }
    }
}
   
void Administrador::CadastrarAdmin(){
    extern ListaAdmins listaA;
    extern Administrador SessaoAdmin;
    admins *atual = listaA.primeiro;
    std::string _cpf_admin;
    std::string _nome_admin;
    std::string _senha_admin;
    int checa_cpf = 0;

    system("clear");
    std::cout << "-------------------------- Cadastro de novo administrador do sistema -------------\n" << std::endl;
    std::cout << "Digite o CPF do administrador:" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, _cpf_admin);
    for(int i=0;i<listaA.tamanho();i++){
        if(_cpf_admin == atual->admin->get_cpf()){
            checa_cpf++;
            atual = atual->proximo;
        }
    }
    if(checa_cpf > 0){
        std::cout << "CPF ja cadastrado!" << std::endl;
        SessaoAdmin.Menu();
    }
    else{
        std::cout << "Digite o nome do administrador: " << std::endl;
        std::cin.ignore();
        std::getline(std::cin, _nome_admin);
        std::cout << "Digite a senha do administrador: " << std::endl;
        std::getline(std::cin, _senha_admin);

        Administrador *novo_admin = new Administrador();
        novo_admin->set_cpf(_cpf_admin);
        novo_admin->set_nome(_nome_admin);
        novo_admin->set_senha(_senha_admin);

        listaA.insere_admin(novo_admin);

        SessaoAdmin.Menu();
    }
}

void Administrador::ListarAdmins(){
    extern Administrador SessaoAdmin;
    extern ListaAdmins listaA;
    admins *atual = listaA.primeiro;

    system("clear");

    std::cout << "Lista de administradores" << std::endl;
    std::cout << "-------------------------------------------------------------------------------" << std::endl;
    for(int i=0;i<listaA.tamanho();i++){
        std::cout << "Nome: " << atual->admin->get_nome() << std::endl;
        std::cout << "Cpf: " << atual->admin->get_cpf() << std::endl;
        std::cout << "-------------------------------------------------------------------------------" << std::endl;
        atual = atual->proximo;
    }
    int a;
    std::cout << "Tecle 0 para voltar ao menu" << std::endl;
    do{
        std::cin >> a;
    }while(a!=0);
    SessaoAdmin.Menu();
}