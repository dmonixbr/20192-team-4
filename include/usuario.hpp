#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>

class Usuario{
	public:

		std::string cpf;
		std::string nome;
		std::string	senha;


		Usuario(std::string _nome,std::string _cpf,std::string _senha);

		virtual std::string get_cpf() = 0;
		virtual void set_cpf(std::string)= 0;
		virtual std::string get_nome() = 0;
		virtual void set_nome(std::string) = 0;
		virtual std::string get_senha() = 0;
		virtual void set_senha(std::string) = 0;

		virtual void login() = 0;

};


#endif