#include "../include/gerente.hpp"
#include "../include/globais.hpp"
#include "../include/lista.hpp"

extern int MenuPrincipal();

Gerente::Gerente(){
    this->cpf = "0";
    this->nome = "0";
    this->senha = "0";
    this->periodo_mandato = "0";
    this->endereco = "0";
    this->telefone = "0";
}
Gerente::Gerente(std::string nome,std::string cpf,std::string senha,std::string periodo_mandato,std::string endereco,std::string telefone){
    this->cpf = cpf;
    this->nome = nome;
    this->senha = senha;
    this->periodo_mandato = periodo_mandato;
    this->endereco = endereco;
    this->telefone = telefone;
}

//setters
void Gerente::set_periodo_mandato(std::string _periodo_mandato){
     this->periodo_mandato = _periodo_mandato;
}
void Gerente::set_endereco(std::string _endereco){
     this->endereco = _endereco;
}
void Gerente::set_telefone(std::string _telefone){
     this->telefone = _telefone;
}

void Gerente::set_cpf(std::string cpf){
    this->cpf = cpf;
}
void Gerente::set_nome(std::string nome){
    this->nome = nome;
}
void Gerente::set_senha(std::string senha){
    this->senha = senha;
}

//getters
std::string Gerente::get_periodo_mandato(){
    return this->periodo_mandato;
}
std::string Gerente::get_endereco(){
    return this->endereco;
}
std::string Gerente::get_telefone(){
    return this->telefone;
}
std::string Gerente::get_cpf(){
    return this->cpf;
}
std::string Gerente::get_nome(){
    return this->nome;
}
std::string Gerente::get_senha(){
    return this->senha;
}


//Metodos
void Gerente::Login(std::string _cpf){
    int i;
    std::string senha;
    extern ListaGerentes listaG;
    extern Gerente *SessaoGerente;
    gerentes *atual = listaG.primeiro;
    for (i=0; i<listaG.tamanho(); i++){
        if (atual->gerente->cpf == _cpf ){
            std::cout << "Digite a senha: \n" << std::endl;
            std::cin.ignore();
            std::getline(std::cin, senha);
            if (atual->gerente->senha == senha){
                std::cout << "\n\nVocê entrou!\n\n" << std::endl;
                SessaoGerente = atual->gerente;
                SessaoGerente->Menu();
            }
            else{
                std::cout << "Voce digitou a senha incorretamente" << std::endl;
                gmu::MenuFunc::MenuPrincipal();
            }

        }
        else if (atual->proximo == nullptr){
            std::cout << "Não existe usuário associado à este CPF." << std::endl;
            gmu::MenuFunc::MenuPrincipal();
        }
        else{
            atual = atual->proximo;
        }

    }
}

void Gerente::EditarCreche(){
    extern Gerente SessaoGerente;
    extern ListaGerentes listaG;
    extern ListaCreches listaC;
    gerentes *gerente_atual = listaG.primeiro;
    creches *creche_atual = listaC.primeiro;
    int checa_creche = 0;
    int id_gerente = 0;
    int id_creche;
    int _numero_professores, _numero_coord, _numero_aux_berc, _numero_turmas, _numero_alunos;
    float _per_capta, _manuntencao, _faixa_etaria;

    for(int i = 0; i < listaG.tamanho(); i++){
        if(SessaoGerente.get_cpf()==gerente_atual->gerente->get_cpf()){
            id_gerente = i;
        }
        gerente_atual = gerente_atual->proximo;
    }

    for(int i = 0; i < listaC.tamanho(); i++){
        if(creche_atual->creche->get_pos_gerente() == id_gerente){
            checa_creche++;
            id_creche = i;
        }
        creche_atual = creche_atual->proximo;
    }
    creche_atual = listaC.primeiro;
    ler_creche:
    try {
    if(checa_creche>0){
        Creche *creche = listaC.get_creche(id_creche);
        std::cout << "Informe os dados de sua creche" << std::endl;
        std::cout << "---------------------------------------------------------" << std::endl;
        std::cout << "Informe o numero de turmas de sua instituicao:" << std::endl;
        std::cin >> _numero_turmas;
        if (std::cin.fail()){
            throw std::invalid_argument("\nVocê digitou algo errado!");
        }
        std::cout << "Informe o numero de professores da sua instituicao:" << std::endl;
        std::cin >> _numero_professores;
        if (std::cin.fail()){
            throw std::invalid_argument("\nVocê digitou algo errado!");
        }
        std::cout << "Informe o numero de coordenadores de sua instituicao:" << std::endl;
        std::cin >> _numero_coord;
        if (std::cin.fail()){
            throw std::invalid_argument("\nVocê digitou algo errado!");
        }
        std::cout << "Informe o numero de auxiliares de bercario em sua instituicao:" << std::endl;
        std::cin >> _numero_aux_berc;
        if (std::cin.fail()){
            throw std::invalid_argument("\nVocê digitou algo errado!");
        }
        std::cout << "Informe o numero de alunos em sua instituicao:" << std::endl;
        std::cin >> _numero_alunos;
        if (std::cin.fail()){
            throw std::invalid_argument("\nVocê digitou algo errado!");
        }
        std::cout << "Informe o valor per capta de alunos:" << std::endl;
        std::cin >> _per_capta;
        if (std::cin.fail()){
            throw std::invalid_argument("\nVocê digitou algo errado!");
        }
        std::cout << "Informe o valor de manuntencao de sua instituicao:" << std::endl;
        std::cin >> _manuntencao;
        if (std::cin.fail()){
            throw std::invalid_argument("\nVocê digitou algo errado!");
        }
        std::cout << "Informe a faixa etaria media de sua instituicao:" << std::endl;
        std::cin >> _faixa_etaria;
        if (std::cin.fail()){
            throw std::invalid_argument("\nVocê digitou algo errado!");
        }

        creche->set_numero_turmas(_numero_turmas);
        creche->set_numero_professores(_numero_professores);
        creche->set_numero_coordenadores(_numero_coord);
        creche->set_numero_aux_berc(_numero_aux_berc);
        creche->set_numero_alunos(_numero_alunos);
        creche->set_valor_per_capta(_per_capta);
        creche->set_valor_manuntencao(_manuntencao);
        creche->set_faixa_etaria(_faixa_etaria);

        std::cout << "Dados registrados com sucesso!" << std::endl;
        std::this_thread::sleep_until(std::chrono::system_clock::now()+std::chrono::seconds(3));
        SessaoGerente.Menu();
    }
    else{
        std::cout << "Voce nao foi definido como gerente de nenhuma creche" << std::endl;
        std::this_thread::sleep_until(std::chrono::system_clock::now()+std::chrono::seconds(3));
        SessaoGerente.Menu();
    }
    }
    catch(std::invalid_argument &e){
        std::cout << e.what();
        std::cin.clear();
        std::cin.ignore();
        goto ler_creche;

    }
    catch(const char *e)
    {
        std::cerr << e << '\n';
    }
}

void Gerente::GerarRelatorio(){
    extern Gerente SessaoGerente;
    extern ListaGerentes listaG;
    extern ListaCreches listaC;
    gerentes *gerente_atual = listaG.primeiro;
    creches *creche_atual = listaC.primeiro;
    int checa_creche = 0;
    int id_gerente = 0;
    int id_creche;

    for(int i = 0; i < listaG.tamanho(); i++){
        if(SessaoGerente.get_cpf()==gerente_atual->gerente->get_cpf()){
            id_gerente = i;
        }
        gerente_atual = gerente_atual->proximo;
    }

    for(int i = 0; i < listaC.tamanho(); i++){
        if(creche_atual->creche->get_pos_gerente() == id_gerente){
            checa_creche++;
            id_creche = i;
        }
        creche_atual = creche_atual->proximo;
    }
    creche_atual = listaC.primeiro;
    if(checa_creche>0){
        Creche *creche = listaC.get_creche(id_creche);
        std::cout << "RELATORIO DE SUA INSTITUIÇÃO" << std::endl;
        std::cout << "--------------------------------------------------------------" << std::endl;
        std::cout << "Numero de alunos: " << creche->get_numero_alunos() << std::endl;
        std::cout << "Numero de turmas: " << creche->get_numero_turmas() << std::endl;
        std::cout << "Numero de professores: " << creche->get_numero_professores() << std::endl;
        std::cout << "Numero de coordenadores: " << creche->get_numero_coordenadores() << std::endl;
        std::cout << "Numero de auxiliares de bercario: " << creche->get_numero_aux_berc() << std::endl;
        std::cout << "--------------------------------------------------------------" << std::endl;
        std::cout << "\t\t\t ORÇAMENTO DISPONIBILIZADO \t\t\t" << std::endl;
        std::cout << std::setprecision(2) << std::fixed;
        std::cout << "--------------------------------------------------------------" << std::endl;
        std::cout << "Orcamento de Manuntencao: R$" << creche->get_valor_manuntencao() << std::endl;
        std::cout << "Orcamento de Professores: R$" << (creche->get_numero_professores() * 1039.00) << std::endl;
        std::cout << "Orcamento de Gerencia: R$" << ((creche->get_numero_coordenadores() * 2078.00) + 2565.40) << std::endl;
        std::cout << "Orcamento para alunos: R$" << ((creche->get_numero_alunos()*creche->get_faixa_etaria()) * creche->get_valor_per_capta()) << std::endl;
        std::cout << "\n";
        std::cout << "Orcamento Geral: R$" << (creche->get_valor_manuntencao()) + (creche->get_numero_professores() * 1039.00) + ((creche->get_numero_coordenadores() * 2078.00) + 2565.40) + ((creche->get_numero_alunos()*creche->get_faixa_etaria()) * creche->get_valor_per_capta()) << std::endl;
        std::cout << "--------------------------------------------------------------" << std::endl;
        std::cout << "\n";
        std::cout << "Tecle qualquer caractere para continuar" << std::endl;
        std::string aux_acesso;
        std::cin.ignore();
        std::getline(std::cin, aux_acesso);
        SessaoGerente.Menu();
    }
    else{
        std::cout << "Voce nao foi definido como gerente de nenhuma creche" << std::endl;
        std::this_thread::sleep_until(std::chrono::system_clock::now()+std::chrono::seconds(3));
        SessaoGerente.Menu();
    }

}

int Gerente::Menu(){
    extern ListaGerentes listaG;
    extern Gerente *SessaoGerente;

    while(1){
        system("clear");
        std::cout << "Digite o numero da funcao que voce quer fazer:" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - Emitir relatorio de minha creche"<<std::endl; 
        std::cout << "2 - Editar minha creche"<<std::endl;
        std::cout << "3 - Editar meus dados" << std:: endl;
        std::cout << "4 - Ver meus dados" << std::endl;
        std::cout << "0 - Sair"<<std::endl;

        try{
            int aux_acesso;
            std::cin >> aux_acesso;
            if(aux_acesso != 1 && aux_acesso !=2 && aux_acesso !=3 && aux_acesso !=4 && aux_acesso !=0){
                throw "Ops, voce digitou um numero errado!";
            }
            else{
                if(aux_acesso == 1){
                    system("clear");
                    SessaoGerente->GerarRelatorio();
                }
                else if(aux_acesso == 2){
                    SessaoGerente->EditarCreche();
                }
                else if(aux_acesso == 3){
                    system("clear");
                    SessaoGerente->EditarDados();
                }

                else if(aux_acesso == 4){
                    system("clear");
                    SessaoGerente->VerDados();
                }

                else if(aux_acesso == 0){
                    SessaoGerente->Deslogar();
                }
                else{
                    throw "Ocorreu um erro inesperado, e para a sua seguranca o programa vai desligar";
                }
            }
        }
        catch(const char *e)
        {
            std::cerr << e << '\n';
        }
        catch(...){
            std::cerr << "Erro inesperado" << '\n';
        }
       
        return -1;
    }
}

void Gerente::Deslogar(){
    std::cout << "Tem certeza que deseja deslogar? (Y/N)" << std::endl;
    std::string opt;
    std::cin >> opt;
    extern Gerente *SessaoGerente;
    if (opt == "y" || opt == "Y"){
        gmu::MenuFunc::MenuPrincipal();
    }else if (opt == "n" || opt == "N"){
        system("clear");
        SessaoGerente->Menu();
    }
    else{
        std::cout << "Você digitou uma opção errada" << std::endl;
    }
}

void Gerente::VerDados(){
    extern ListaGerentes listaG;
    extern Gerente *SessaoGerente;
    system("clear");
    std::cout << "Seja Bem Vindo! \n" << std::endl;
    std::cout << "Ola " << SessaoGerente->get_nome() << "," << std::endl;

    std::cout << "CPF: " << SessaoGerente->get_cpf() << ";" << std::endl;
    std::cout << "Senha: " << SessaoGerente->get_senha() << ";" << std::endl;
    std::cout << "Periodo mandato: " << SessaoGerente->get_periodo_mandato() << ";" << std::endl;
    std::cout << "Endereco:" << SessaoGerente->get_endereco() << ";" << std::endl;
    std::cout << "Telefone: " << SessaoGerente->get_telefone() << ";\n\n" << std::endl;

    std::cout << "Digite 0 para sair" << std::endl; 
    int aux_acesso;
    std::cin.ignore();
    std::cin >> aux_acesso;

    try{
        if(aux_acesso != 0){
            throw "ops, voce digitou um numero errado";
        }
        else if(aux_acesso == 0){
            SessaoGerente->Menu();
        }
    }
    catch(const char *e){
        std::cerr << e << '\n';
    }
    catch(...){
    std::cerr << "Erro inesperado" << '\n';
    }
}

void Gerente::EditarDados(){
    extern ListaGerentes listaG;
    gerentes *atual = listaG.primeiro;
    extern Gerente *SessaoGerente;
    SessaoGerente = atual->gerente;

    std::string cpf = SessaoGerente->get_cpf(),
                nome = SessaoGerente->get_nome(),
                senha = SessaoGerente->get_senha(),
                endereco = SessaoGerente->get_endereco(),
                telefone = SessaoGerente->get_telefone();

    std::cout << "\n\n ----------Editar meus dados--------------\n\n";


    while(1){
      //0  system("clear");
        std::cout <<"Digite o numero do dado que voce deseja editar\n"<<std::endl;
        std::cout << "1 - Editar Nome" << std::endl;
        std::cout << "2 - Editar CPF" << std::endl;
        std::cout << "3 - Editar senha" << std::endl;
        std::cout << "4 - Editar endereco" << std::endl;
        std::cout << "5 - Editar telefone" << std::endl;
        std::cout << std::endl;
        std::cout << "6 - Sair e salvar           0 - Sair sem salvar" << std::endl;

        try{
            int aux_acesso;
            std::cin >> aux_acesso;
            if(aux_acesso != 1 && aux_acesso != 2 && aux_acesso != 3 && aux_acesso != 4 && aux_acesso !=5 && aux_acesso !=6 && aux_acesso != 0){
                throw "Ops, voce digitou um numero errado";    
            }
            else{
                //editar nome
                if(aux_acesso == 1){
                    system("clear");
                    std::cin.ignore();
                    std::cout << "Digite o novo nome:" << std::endl;
                    std::getline(std::cin, nome);
                }
                //editar cpf
                else if(aux_acesso == 2){
                    //cpf auxiliar
                    std::string _cpf;

                    system("clear");
                    std::cin.ignore();
                    std::cout << "Digite o novo cpf:" << std::endl;
                    std::getline(std::cin, _cpf);
                    bool validacpf = gmu::MenuFunc::ValidaCpfGerente(_cpf);
                    //validando cpf
                    if(validacpf){
                        cpf = _cpf;
                        std::cout << "Novo cpf definido com sucesso" << std::endl;
                        std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(3));
                    }
                    else{
                        std::cout << "Existe um gerente com esse cpf, digite outro!" <<std::endl;
                        std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(3));
                    }
                }
                //editar senha
                else if(aux_acesso == 3){
                    system("clear");
                    std::cin.ignore();
                    std::cout << "Digite a nova senha: " << std::endl;
                    std::getline(std::cin, senha);
                }

                //editar endereco
                else if(aux_acesso == 4){
                    system("clear");
                    std::cin.ignore();
                    std::cout << "Digite o novo endereco: " << std::endl;
                    std::getline(std::cin, endereco);
                }

                //editar telefone
                else if(aux_acesso == 5){
                    system("clear");
                    std::cin.ignore();
                    std::cout << "Digite o novo telefone: " << std::endl;
                    std::getline(std::cin, telefone);
                }
                
                //sair e salvar
                else if(aux_acesso == 6){
                    system("clear");
                    SessaoGerente->set_cpf(cpf);
                    SessaoGerente->set_nome(nome);
                    SessaoGerente->set_senha(senha);
                    SessaoGerente->set_endereco(endereco);
                    SessaoGerente->set_telefone(telefone);
                    SessaoGerente->Menu();
                    return;
                    
                }

                //sair sem salvar
                else if(aux_acesso == 0){
                    system("clear");
                    SessaoGerente->Menu();
                    return;
                }
            }
        }
        catch(const char *e){
            std::cerr << e << '\n';
        }
        catch(...){
        std::cerr << "Erro inesperado" << '\n';
        }
    }
}
