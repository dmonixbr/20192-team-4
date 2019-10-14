#include <iostream> 
#include "db/db.cpp"
#include "usuario/usuario.cpp"
  
int main(int argc, char** argv){

	const std::string resetText("\033[0m"), redText("\033[0;31m"), greenText("\033[0;32m"), blueText("\033[0;34m"), cyanText("\033[0;36m"), byellowText("\033[0;93m");
	const char* dbPath = "creche.db" ;

	Database db(dbPath);
	Usuario user;
	std::string nome, cpf, senha;

	int a = 314159265;


	while (a != 0){
	std::cout << byellowText << "\nSelecione uma opção:" << cyanText << " \n1- Deletar usuários\n2- Ver Usuários\n3- Adicionar Usuários\n4- Atualizar Usuários\n0- Sair" << resetText << std::endl;
	std::cin >> a;

		switch (a){
			case 1:
				std::cout << resetText << "Digite o CPF do usuário que deseja deletar: " << cyanText;
				std::cin >> cpf;
				user.set_cpf(cpf);
				user.deletarUsuario(user.get_cpf(), db.getBanco());
				break;
			case 2:
				std::cout << resetText << "Digite o CPF do usuário que deseja ver: " << cyanText;
				std::cin >> cpf;
				user.set_cpf(cpf);
				user.verUsuario(user.get_cpf(), db.getBanco());
				break;
			case 3:
				std::cout << "Dê as informações do usuário\n\n" << std::endl;
				std::cout << resetText << "Digite o NOME do usuário: " << cyanText;
				std::cin >> nome;
				std::cout << resetText << "Digite o CPF do usuário: " << cyanText;
				std::cin >> cpf;
				std::cout << resetText << "Digite a SENHA do usuário: " << cyanText;
				std::cin >> senha;


				user.set_nome(nome);
				user.set_cpf(cpf);
				user.set_senha(senha);

				user.inserirUsuario(user.get_nome(), user.get_cpf(), user.get_senha(), db.getBanco());
				break;
			case 4:
				std::cout << "Dê as informações do usuário\n\n" << std::endl;
				std::cout << resetText << "Digite o CPF do usuário que deseja editar: " << cyanText;
				std::cin >> cpf;
				std::cout << resetText << "Digite o novo NOME do usuário: " << cyanText;
				std::cin >> nome;
				std::cout << resetText << "Digite a nova SENHA do usuário: " << cyanText;
				std::cin >> senha;

				user.set_nome(nome);
				user.set_cpf(cpf);
				user.set_senha(senha);
				user.editarUsuario(user.get_nome(), user.get_cpf(), user.get_senha(), db.getBanco());
				break;
			case 0:
				std::cout << greenText << "Obrigado por usar nosso programa! :)" << resetText << std::endl;
				break;
			default:
				std::cout << "Opção errada, tente de novo" << std::endl;
		}
	}


	return 0;
} 
