#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include <iostream>

class Usuario{
	protected:

		std::string cpf;
		std::string nome;
		std::string	senha;
		
	public:
		virtual std::string get_cpf() = 0;
		virtual void set_cpf(std::string)= 0;
		virtual std::string get_nome() = 0;
		virtual void set_nome(std::string) = 0;
		virtual std::string get_senha() = 0;
		virtual void set_senha(std::string) = 0;

		virtual void login(std::string, std::string) = 0;

};


#endif