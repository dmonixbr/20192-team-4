#include <iostream>
#include "../include/gerente.hpp"
#include "../include/administrador.hpp"
#include "../include/creche.hpp"
#include "../include/usuario.hpp"
#include "../include/lista.hpp"

ListaGerentes listaG;
ListaAdmins listaA;


int main(){
    /*---------------------Criando Administrador super--------------*/
    Administrador Super = Administrador();
    Administrador *S = & Super;
    Super.set_nome("super");
    Super.set_cpf("00000000000");
    Super.set_senha("super");
    listaA.insere_admin(S);
    
    //Administrador Super2("super2","123456789","1234567");
    //listaA.insere_admin(&Super2);
    /*-------------Testes do programa----------------*/

   //criando o auxiliar de acesso

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
                    std::cout << "\n\n---------------------------- Login ----------------------------\n\nDigite seu CPF:" << std::endl;
                    std::string cpf;
                    std::cin >> cpf;
                    listaA.primeiro->admin->Login(cpf);
                }
                else if(aux_acesso == 2){
                    return 0;
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