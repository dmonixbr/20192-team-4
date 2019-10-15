#include "../../include/db/db.hpp"

// Abre a conexão com o banco de dados
Database::Database(const char* _caminho){
	int status = 0; 
    status = sqlite3_open(_caminho, &banco); 
  
    if (status) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(banco) << std::endl; 
    } 
}

//Fecha a Conexão com o banco de dados
Database::~Database(){
	sqlite3_close(banco);
}

//Retorna o objeto do banco de dados
sqlite3* Database::getBanco(){
	return banco;
}

/* Recebe o nome da tabela(string) e um mapa com a coluna(string) e o dado(strin), respectivamente e 
insere esses dados nas colunas da tabela passada.
Os elementos do mapa devem ser coluna e dado, necessáriamente.
*/
void Database::inserirDados(std::string tabela, std::map<std::string, std::string> insert){
	std::map<std::string, std::string>::iterator itr;

	std::string sql1 = "INSERT INTO " + tabela + " (", sql2 = ") VALUES (";
	for (itr = insert.begin(); itr != insert.end(); ++itr){
		sql1 += itr->first + ",";
		sql2 += "'" + itr->second + "'" + ",";
	}
	sql1.pop_back();
	sql2.pop_back();

	std::string sqlstr = sql1 + sql2 + ");";

	char* messageError;
	int status = 0;
	status = sqlite3_exec(banco, sqlstr.c_str(), NULL, 0, &messageError);

	if (status != SQLITE_OK){
		std::cerr << "Erro ao inserir dados no banco: " << sqlite3_errmsg(banco) << std::endl;
		sqlite3_free(messageError);
	}
	else{
		std::cout << "Dado inserido com sucesso!" << std::endl;
	}
}

/* Recebe o nome de uma tabela(string), uma condição(string) e um mapa
com os dados a serem adicionados.
O mapa, assim como na função de inserir, deve ter coluna e dado, necessáriamente nessa ordem
*/
void Database::editarDados(std::string tabela, std::string condicao, std::map<std::string, std::string> insert){
	std::map<std::string, std::string>::iterator itr;

	std::string sql = "UPDATE " + tabela + " SET ";

	for (itr = insert.begin(); itr != insert.end(); ++itr){
		sql += itr->first + "='" + itr->second + "',";
	}

	sql.pop_back();

	sql += " WHERE " + condicao + ";";

	char* messageError;
	int status = 0;
	status = sqlite3_exec(banco, sql.c_str(), NULL, 0, &messageError);

	if (status != SQLITE_OK){
		std::cerr << "Erro ao editar dados no banco: " << sqlite3_errmsg(banco) << std::endl;
		sqlite3_free(messageError);
	}
	else{
		std::cout << "Dados atualizados com sucesso!" << std::endl;
	}

}

/*
Recebe uma tabela(string) e uma condição (string) e deleta os dados da tabela que
correspondem aquela condição
*/
void Database::deletarDados(std::string tabela, std::string condicao){
	std::string sql = "DELETE FROM " + tabela + " WHERE " + condicao + ";";

	char* messageError;
	int status = 0;
	status = sqlite3_exec(banco, sql.c_str(), NULL, 0, &messageError);

	if (status != SQLITE_OK){
		std::cerr << "Erro ao deletar dados no banco: " << sqlite3_errmsg(banco) << std::endl;
		sqlite3_free(messageError);
	}
	else{
		std::cout << "Dados apagados com sucesso!" << std::endl;
	}
}

/* Recebe uma tabela(string) e uma condição (string). Executa uma query na tabela passada
e procura por dados que atendam a condição. É chamada a função callback, que vai modificar a lista
estática da classe Database, sendo cada posição da lista um dado, seguindo a ordem da tabela.
*/
void Database::verDados(std::string tabela, std::string condicao){
	std::string sql = "SELECT * FROM " + tabela + " WHERE " + condicao + " ;";
	
	char* messageError;
	int status = 0;
	status = sqlite3_exec(banco, sql.c_str(), callback, NULL, NULL); 
  
  	if (status != SQLITE_OK) 
        std::cerr << "Erro ao buscar informações do usuário: " << sqlite3_errmsg(banco) << std::endl;

}