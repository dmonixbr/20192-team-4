#include "../../include/usuario/usuario.hpp"
std::string Usuario::get_cpf(){
	return this->cpf;
}
void Usuario::set_cpf(std::string _cpf){
	this->cpf = _cpf;
}


std::string Usuario::get_nome(){
	return this->nome;
}
void Usuario::set_nome(std::string _nome){
	this->nome = _nome;
}


std::string Usuario::get_senha(){
	return this->senha;
}
void Usuario::set_senha(std::string _senha){
	this->senha = _senha;
}



void Usuario::inserirUsuario(std::string _username, std::string _cpf, std::string _senha, sqlite3* banco){
	std::string sql = "INSERT INTO usuario (username, cpf, senha) VALUES ('" + _username + "', '" + _cpf + "', '" + _senha + "');";
	char* messageError;
	int status = 0;
	status = sqlite3_exec(banco, sql.c_str(), NULL, 0, &messageError);

	if (status != SQLITE_OK){
		std::cerr << "Erro ao criar usuário: " << sqlite3_errmsg(banco) << std::endl;
		sqlite3_free(messageError);
	}
	else{
		std::cout << "Usuário inserido com sucesso!" << std::endl;
	}

}

void Usuario::editarUsuario(std::string _username, std::string _cpf, std::string _senha, sqlite3* banco){
	std::string sql = "UPDATE usuario set username='" + _username + "', senha='" + _senha + "' where cpf='" + _cpf + "';";
	char* messageError;
	int status = 0;
	status = sqlite3_exec(banco, sql.c_str(), NULL, 0, &messageError);

	if (status != SQLITE_OK){
		std::cerr << "Erro ao editar o usuário: " << sqlite3_errmsg(banco) << std::endl;
		sqlite3_free(messageError);
	}else{
		std::cout << "Usuário alterado com sucesso!" << std::endl;
	}
}


std::string Usuario::verUsuario(std::string _cpf, sqlite3* banco){
	std::string sql = "SELECT * FROM usuario WHERE cpf='" + _cpf + "';";
	char* messageError;
	int status = 0;
	std::string data("Usuario:");
	
	status = sqlite3_exec(banco, sql.c_str(), callback, (void*)data.c_str(), NULL); 
  
  if (status != SQLITE_OK) 
        std::cerr << "Erro ao buscar informações do usuário: " << sqlite3_errmsg(banco) << std::endl;
}

void Usuario::deletarUsuario(std::string _cpf, sqlite3* banco){
	std::string sql = "DELETE FROM usuario"; // WHERE cpf='" + _cpf + "';";
	char* messageError;
	int status = 0;

	status = sqlite3_exec(banco, sql.c_str(), NULL, 0, &messageError);

	if (status){
		std::cerr << "Erro ao deletar usuário: " << sqlite3_errmsg(banco) << std::endl;
		sqlite3_free(messageError);
	}else{
		std::cout << "Usuário deletado com sucesso!" << std::endl;
	}
}
