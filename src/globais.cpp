#include "../include/globais.hpp"
#include "../include/lista.hpp"
#include <iostream>


extern ListaGerentes listaG;
extern ListaAdmins listaA;
extern ListaAdmins listaC;




namespace gmu
{

    //! Função que verifica se o que foi digitado na string é um numero.
    bool MenuFunc::isNumero(std::string s) {
	    std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it)) 
            ++it;
        return !s.empty() && it == s.end();
    }


    void MenuFunc::MenuPrincipal(){
        std::cout << "\x1B[2J\x1B[H";
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
                        std::cout << "\x1B[2J\x1B[H";
                        std::cout << "\n\n---------------------------- Login ----------------------------\n\nDigite seu CPF:" << std::endl;
                        std::string cpf;
                        std::cin >> cpf;

                        //! Função que verifica se o CPF contém apenas numero e 11 digitos
                        if((cpf.length() != 11) && (!isNumero(cpf)))  
		                    throw std::invalid_argument("\nCPF Invalido! O CPF é composto de 11 digitos e apenas números!");
                        else if((cpf.length() != 11))  
		                    throw std::invalid_argument("\nCPF Invalido! O CPF é composto de 11 digitos!");
                        else if(!isNumero(cpf))
                            throw std::invalid_argument("\nCPF Invalido! O CPF é composto apenas de números!");

                        listaA.primeiro->admin->Login(cpf);
                    }
                    else if(aux_acesso == 2){
                        std::cout << "\x1B[2J\x1B[H";
                        if (listaG.primeiro == nullptr){                        
                            std::cout << "\n\n\nNão existem gerentes cadastrados. Peça para um administrador cadastrar você!\n\n\n" << std::endl;
                            std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(3));
                            std::cout << "\x1B[2J\x1B[H";
                            gmu::MenuFunc::MenuPrincipal();
                        }else{
                            std::cout << "\n\n---------------------------- Login ----------------------------\n\nDigite seu CPF:" << std::endl;
                            std::string cpf;
                            std::cin >> cpf;

                            //! Função que verifica se o CPF contém apenas numero e 11 digitos
                            if((cpf.length() != 11) && (!isNumero(cpf)))  
		                        throw std::invalid_argument("\nCPF Invalido! O CPF é composto de 11 digitos e apenas números!");
                            else if((cpf.length() != 11))  
		                        throw std::invalid_argument("\nCPF Invalido! O CPF é composto de 11 digitos!");
                            else if(!isNumero(cpf))
                                throw std::invalid_argument("\nCPF Invalido! O CPF é composto apenas de números!");
                            
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
                std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(2));
                gmu::MenuFunc::MenuPrincipal();
                std::cout << "\n\n\n\n" << std::endl;
            }
            catch(...){
                std::cerr << "Erro inesperado" << '\n';
            }
    }



    //! Função que verifica se o CPF que deseja ser cadastrado já está em uso para outro gerente
    bool MenuFunc::ValidaCpfGerente(std::string cpf){

        for(int i = 0; i < listaG.tamanho();i++){
            if(listaG.get_gerente(i)->get_cpf() == cpf){
                return false;
                break;
            }   
        }
        return true;
    }

    //! Função que verifica se o CPF que deseja ser cadastrado já está em uso para outro administrador
    bool MenuFunc::ValidaCpfAdmin(std::string cpf){
        for(int i = 0; i < listaA.tamanho();i++){
            if(listaA.get_admin(i)->get_cpf() == cpf){
                return false;
                break;
            }
        }
        return true;
    }
}



