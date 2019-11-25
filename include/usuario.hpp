#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <iostream>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <iomanip>

class Usuario{
	protected:

		std::string cpf;
		std::string nome;
		std::string	senha;

		virtual void VerDados() = 0;
		virtual void EditarDados() = 0;
		
	public:

		virtual std::string get_cpf() = 0;
		virtual void set_cpf(std::string)= 0;
		virtual std::string get_nome() = 0;
		virtual void set_nome(std::string) = 0;
		virtual std::string get_senha() = 0;
		virtual void set_senha(std::string) = 0;

		virtual void Login(std::string) = 0;
		virtual void Deslogar() = 0;
		virtual void GerarRelatorio() = 0;
	
};


#endif