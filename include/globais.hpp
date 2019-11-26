#include "../include/lista.hpp"

namespace gmu{

    class MenuFunc{
        public:
            static void MenuPrincipal();
            static bool ValidaCpfGerente(std::string);
            static bool ValidaCpfAdmin(std::string);
    };
}