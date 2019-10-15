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



