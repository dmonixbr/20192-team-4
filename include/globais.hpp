#include "../include/lista.hpp"

namespace gmu{

    class MenuFunc{
        public:
            static void MenuPrincipal();
            static bool ValidaCpfGerente(std::string);
            static bool ValidaCpfAdmin(std::string);
            static void Fechar();
    };
    class DataBase{
    public:
    	std::string caminho;
    	DataBase();
    	~DataBase();
    	static void SalvarDB();

    private:
    	sqlite3* banco;
    }
}