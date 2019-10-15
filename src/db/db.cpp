#include "../../include/db/db.hpp"


Database::Database(const char* _caminho){
	int status = 0; 
    status = sqlite3_open(_caminho, &banco); 
  
    if (status) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(banco) << std::endl; 
    } 
}

Database::~Database(){
	sqlite3_close(banco);
}

sqlite3* Database::getBanco(){
	return banco;
}

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

void Database::verDados(std::string tabela, std::string condicao){
	std::string sql = "SELECT * FROM " + tabela + " WHERE " + condicao + " ;";
	
	char* messageError;
	int status = 0;
	status = sqlite3_exec(banco, sql.c_str(), callback, NULL, NULL); 
  
  	if (status != SQLITE_OK) 
        std::cerr << "Erro ao buscar informações do usuário: " << sqlite3_errmsg(banco) << std::endl;

}