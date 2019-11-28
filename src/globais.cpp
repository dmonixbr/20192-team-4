#include "../include/globais.hpp"
#include "../include/lista.hpp"
#include <iostream>

extern ListaGerentes listaG;
extern ListaAdmins listaA;
extern ListaAdmins listaC;

namespace gmu
{
    void MenuFunc::MenuPrincipal(){
        std::cout << "\n\n------Seja Bem Vindo ao Sistema da creche-------"<<std::endl;
                    std::cout << "Digite o numero da funcao que voce quer fazer:" << std::endl;
                    std::cout << std::endl;
                    std::cout << "1 - Login como Administrador"<<std::endl; 
                    std::cout << "2 - Login como Gerente da creche"<<std::endl;
                    std::cout << "0 - Fechar o programa"<<std::endl;

            try{
                    int aux_acesso;
                    std::cin >> aux_acesso;
                    if (std::cin.fail()){
                        throw std::invalid_argument("\nVocê digitou algo INVÁLIDO!!!\n\n");
                        
                    }
                if(aux_acesso != 1 && aux_acesso !=2 && aux_acesso !=0){
                    throw "Ops, voce digitou um numero errado!\n";
                }
                else{
                    if(aux_acesso == 1){
                        system("clear");
                        std::cout << "\n\n---------------------------- Login ----------------------------\n\nDigite seu CPF:" << std::endl;
                        std::string cpf;
                        std::cin >> cpf;
                        listaA.primeiro->admin->Login(cpf);
                    }
                    else if(aux_acesso == 2){
                        system("clear");
                        if (listaG.primeiro == nullptr){                        
                            std::cout << "\n\n\nNão existem gerentes cadastrados. Peça para um administrador cadastrar você!\n\n\n" << std::endl;
                            std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(3));
                            system("clear");
                            gmu::MenuFunc::MenuPrincipal();
                        }else{
                            std::cout << "\n\n---------------------------- Login ----------------------------\n\nDigite seu CPF:" << std::endl;
                            std::string cpf;
                            std::cin >> cpf;
                            listaG.primeiro->gerente->Login(cpf);
                        }
                    }
                    else if(aux_acesso == 0){
                        std::cout << "Muito Obrigado!!!" << std::endl;
                        std::cout << "Tenha um bom dia!!" << std::endl;
                        std::exit(0);
                    }   
                    else{
                        std::cerr << "Ocorreu um erro inesperado, e para a sua seguranca o programa vai desligar";
                    //    continue;
                    }
                }
            }
            catch(const char *e)
            {
                std::cerr << e << '\n';
                gmu::MenuFunc::MenuPrincipal();
            }
            catch(std::invalid_argument &e)
            {
                std::cout << e.what();
                std::cin.clear();
                std::cin.ignore();
                gmu::MenuFunc::MenuPrincipal();
                std::cout << "\n\n\n\n" << std::endl;
            }
            catch(...){
                std::cerr << "Erro inesperado" << '\n';
            }
    }

    bool MenuFunc::ValidaCpfGerente(std::string cpf){

        for(int i = 0; i < listaG.tamanho();i++){
            if(listaG.get_gerente(i)->get_cpf() == cpf){
                return false;
                break;
            }   
        }
        return true;
    }

    bool MenuFunc::ValidaCpfAdmin(std::string cpf){
        for(int i = 0; i < listaA.tamanho();i++){
            if(listaA.get_admin(i)->get_cpf() == cpf){
                return false;
                break;
            }
        }
        return true;
    }

    std::string DataBase::INFO ="";

    DataBase::DataBase(){
        
        int status = 0; 
        status = sqlite3_open("creche.db", &banco); 
  
        if (status) { 
            std::cerr << "Erro ao abrir o Banco de Dados: " << sqlite3_errmsg(banco) << std::endl; 
        } 
    }

    DataBase::~DataBase(){
        sqlite3_close(banco);
    }

    void DataBase::AbrirDB(){
        std::string sqlA = "SELECT * FROM admin";
        char* messageError;
        int status = 0;
        status = sqlite3_exec(banco, sqlA.c_str(), callback, NULL, NULL); 
       // std::list<std::string>::iterator it;
        std::cout << INFO;
        if (status != SQLITE_OK) 
        std::cerr << "Erro ao buscar informações do usuário: " << sqlite3_errmsg(banco) << std::endl;

    }

    void DataBase::SalvarDB(){
        int i;
        for (i = 0; i<listaA.tamanho(); i++){
            std::string sqlA = "INSERT INTO admin (id,cpf, nome, senha) VALUES ('" +  std::to_string(i+1) +"', '" + listaA.primeiro->admin->get_cpf() + "', '" + listaA.primeiro->admin->get_nome() + "', '" +listaA.primeiro->admin->get_senha() + "')";
            std::cout << sqlA;
            char* messageError;
            int status = 0;
            status = sqlite3_exec(banco, sqlA.c_str(), NULL, 0, &messageError);

            if (status != SQLITE_OK){
                std::cerr << "Erro ao inserir dados no banco: " << sqlite3_errmsg(banco) << std::endl;
                sqlite3_free(messageError);
            }
        }
    } 
}


