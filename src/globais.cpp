#include "../include/globais.hpp"
#include "../include/lista.hpp"
#include <iostream>

extern ListaGerentes listaG;
extern ListaAdmins listaA;
extern ListaAdmins listaC;

namespace gmu
{
    int MenuFunc::MenuPrincipal(){
        std::cout << "\n\n------Seja Bem Vindo ao Sistema da creche-------"<<std::endl;
                while(1){
                    std::cout << "Digite o numero da funcao que voce quer fazer:" << std::endl;
                    std::cout << std::endl;
                    std::cout << "1 - Login como Administrador"<<std::endl; 
                    std::cout << "2 - Login como Gerente da creche"<<std::endl;
                    std::cout << "0 - Fechar o programa"<<std::endl;

            try{
                    int aux_acesso;
                    std::cin >> aux_acesso;
                if(aux_acesso != 1 && aux_acesso !=2 && aux_acesso !=0){
                    throw "Ops, voce digitou um numero errado!";
                }
                else{
                    if(aux_acesso == 1){
                        system("clear");
                        std::cout << "\n\n---------------------------- Login ----------------------------\n\nDigite seu CPF:" << std::endl;
                        std::string cpf;
                        std::getline(std::cin, cpf);
                        listaA.primeiro->admin->Login(cpf);
                    }
                    else if(aux_acesso == 2){
                        system("clear");
                        std::cout << "\n\n---------------------------- Login ----------------------------\n\nDigite seu CPF:" << std::endl;
                        std::string cpf;
                        std::getline(std::cin, cpf);
                        listaG.primeiro->gerente->Login(cpf);
                    
                    }
                    else if(aux_acesso == 0){
                        std::cout << "Muito Obrigado!!!" << std::endl;
                        std::cout << "Tenha um bom dia!!" << std::endl;
                        return 0;
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
}
