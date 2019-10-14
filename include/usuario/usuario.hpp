#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>
#include "../../src/db/db.cpp"

class Usuario{
private:
	std::string cpf;
	std::string nome;
	std::string	senha;

public:
	std::string get_cpf();
	void set_cpf(std::string _cpf);
	std::string get_nome();
	void set_nome(std::string _nome);
	std::string get_senha();
	void set_senha(std::string _senha);


	void inserirUsuario(std::string, std::string, std::string, sqlite3*);
	void editarUsuario(std::string, std::string, std::string, sqlite3*);
	std::string verUsuario(std::string, sqlite3*);
	void deletarUsuario(std::string, sqlite3*);
};


#endif