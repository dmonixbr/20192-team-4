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
Gerente::Gerente(std::string nome,std::string cpf,std::string senha,std::string periodo_mandato,std::string endereco,std::string telefone){
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
            std::cout << "Digite a senha: \n" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, senha);
            if (atual->gerente->senha == senha){
                std::cout << "\n\nVocê entrou!\n\n" << std::endl;
                SessaoGerente = atual->gerente;
                SessaoGerente->Menu();
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

void Gerente::EditarCreche(){

}

void Gerente::EmitirRelatorio(){

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
        std::cout << "3 - Editar meus dados" << std:: endl;
        std::cout << "4 - Ver meus dados" << std::endl;
        std::cout << "0 - Sair"<<std::endl;

        try{
            int aux_acesso;
            std::cin >> aux_acesso;
            if(aux_acesso != 1 && aux_acesso !=2 && aux_acesso !=3 && aux_acesso !=4 && aux_acesso !=0){
                throw "Ops, voce digitou um numero errado!";
            }
            else{
                if(aux_acesso == 1){
                    system("clear");
                    SessaoGerente->EmitirRelatorio();
                }
                else if(aux_acesso == 2){
                    system("clear");
                    SessaoGerente->EditarCreche();
                }
                else if(aux_acesso == 3){
                    system("clear");
                    SessaoGerente->EditarDados();
                }

                else if(aux_acesso == 4){
                    system("clear");
                    SessaoGerente->VerDados();
                }

                else if(aux_acesso == 0){
                    SessaoGerente->Deslogar();
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

void Gerente::Deslogar(){
    std::cout << "Tem certeza que deseja deslogar? (Y/N)" << std::endl;
    std::string opt;
    std::cin >> opt;
    extern Gerente *SessaoGerente;
    if (opt == "y" || opt == "Y"){
        gmu::MenuFunc::MenuPrincipal();
    }else if (opt == "n" || opt == "N"){
        system("clear");
        SessaoGerente->Menu();
    }
    else{
        std::cout << "Você digitou uma opção errada" << std::endl;
    }
}

void Gerente::VerDados(){
        extern ListaGerentes listaG;
    gerentes *atual = listaG.primeiro;
    extern Gerente *SessaoGerente;
    SessaoGerente = atual->gerente;

    system("clear");
    std::cout << "Seja Bem Vindo! \n" << std::endl;
    std::cout << "Ola " << SessaoGerente->get_nome() << "," << std::endl;

    std::cout << "CPF: " << SessaoGerente->get_cpf() << ";" << std::endl;
    std::cout << "Senha: " << SessaoGerente->get_senha() << ";" << std::endl;
    std::cout << "Periodo mandato: " << SessaoGerente->get_periodo_mandato() << ";" << std::endl;
    std::cout << "Endereco:" << SessaoGerente->get_endereco() << ";" << std::endl;
    std::cout << "Telefone: " << SessaoGerente->get_telefone() << ";\n\n" << std::endl;

    std::cout << "Digite 0 para sair" << std::endl; 
    int aux_acesso;
    std::cin.ignore();
    std::cin >> aux_acesso;

    try{
        if(aux_acesso != 0){
            throw "ops, voce digitou um numero errado";
        }
        else if(aux_acesso == 0){
            SessaoGerente->Menu();
        }
    }
    catch(const char *e){
        std::cerr << e << '\n';
    }
    catch(...){
    std::cerr << "Erro inesperado" << '\n';
    }
}

void Gerente::EditarDados(){
    extern ListaGerentes listaG;
    gerentes *atual = listaG.primeiro;
    extern Gerente *SessaoGerente;
    SessaoGerente = atual->gerente;

    std::string cpf = SessaoGerente->get_cpf(),
                nome = SessaoGerente->get_nome(),
                senha = SessaoGerente->get_senha(),
                endereco = SessaoGerente->get_endereco(),
                telefone = SessaoGerente->get_telefone();

    std::cout << "\n\n ----------Editar meus dados--------------\n\n";


    while(1){
      //0  system("clear");
        std::cout <<"Digite o numero do dado que voce deseja editar\n"<<std::endl;
        std::cout << "1 - Editar Nome" << std::endl;
        std::cout << "2 - Editar CPF" << std::endl;
        std::cout << "3 - Editar senha" << std::endl;
        std::cout << "4 - Editar endereco" << std::endl;
        std::cout << "5 - Editar telefone" << std::endl;
        std::cout << std::endl;
        std::cout << "6 - Sair e salvar           0 - Sair sem salvar" << std::endl;

        try{
            int aux_acesso;
            std::cin >> aux_acesso;
            if(aux_acesso != 1 && aux_acesso != 2 && aux_acesso != 3 && aux_acesso != 4 && aux_acesso !=5 && aux_acesso !=6 && aux_acesso != 0){
                throw "Ops, voce digitou um numero errado";    
            }
            else{
                //editar nome
                if(aux_acesso == 1){
                    system("clear");
                    std::cin.ignore();
                    std::cout << "Digite o novo nome:" << std::endl;
                    std::getline(std::cin, nome);
                }
                //editar cpf
                else if(aux_acesso == 2){
                    system("clear");
                    std::cin.ignore();
                    std::cout << "Digite o novo cpf:" << std::endl;
                    std::getline(std::cin, cpf);
                }
                //editar senha
                else if(aux_acesso == 3){
                    system("clear");
                    std::cin.ignore();
                    std::cout << "Digite a nova senha: " << std::endl;
                    std::getline(std::cin, senha);
                }

                //editar endereco
                else if(aux_acesso == 4){
                    system("clear");
                    std::cin.ignore();
                    std::cout << "Digite o novo endereco: " << std::endl;
                    std::getline(std::cin, endereco);
                }

                //editar telefone
                else if(aux_acesso == 5){
                    system("clear");
                    std::cin.ignore();
                    std::cout << "Digite o novo telefone: " << std::endl;
                    std::getline(std::cin, telefone);
                }
                
                //sair e salvar
                else if(aux_acesso == 6){
                    system("clear");
                    SessaoGerente->set_cpf(cpf);
                    SessaoGerente->set_nome(nome);
                    SessaoGerente->set_senha(senha);
                    SessaoGerente->set_endereco(endereco);
                    SessaoGerente->set_telefone(telefone);
                    SessaoGerente->Menu();
                    return;
                    
                }

                //sair sem salvar
                else if(aux_acesso == 0){
                    system("clear");
                    SessaoGerente->Menu();
                    return;
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



