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
    std::cout << "teste" << std::endl;
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

    if(checa_creche>0){
        Creche *creche = listaC.get_creche(id_creche);
        std::cout << "Informe os dados de sua creche" << std::endl;
        std::cout << "---------------------------------------------------------" << std::endl;
        std::cout << "Informe o numero de turmas de sua instituicao:" << std::endl;
        std::cin >> _numero_turmas;
        std::cout << "Informe o numero de professores da sua instituicao:" << std::endl;
        std::cin >> _numero_professores;
        std::cout << "Informe o numero de coordenadores de sua instituicao:" << std::endl;
        std::cin >> _numero_coord;
        std::cout << "Informe o numero de auxiliares de bercario em sua instituicao:" << std::endl;
        std::cin >> _numero_aux_berc;
        std::cout << "Informe o numero de alunos em sua instituicao:" << std::endl;
        std::cin >> _numero_alunos;
        std::cout << "Informe o valor per capta de alunos:" << std::endl;
        std::cin >> _per_capta;
        std::cout << "Informe o valor de manuntencao de sua instituicao:" << std::endl;
        std::cin >> _manuntencao;
        std::cout << "Informe a faixa etaria media de sua instituicao:" << std::endl;
        std::cin >> _faixa_etaria;

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

void Gerente::EmitirRelatorio(){

}

int Gerente::Menu(){
    extern ListaGerentes listaG;
    gerentes *atual = listaG.primeiro;
    extern Gerente *SessaoGerente;
    SessaoGerente = atual->gerente;

    while(1){
        system("clear");
        std::cout << "Digite o numero da funcao que voce quer fazer:" << std::endl;
        std::cout << std::endl;
        std::cout << "1 - Emitir relatorio de minha creche"<<std::endl; 
        std::cout << "2 - Editar minha creche"<<std::endl;
        std::cout << "0 - Sair"<<std::endl;

        try{
            int aux_acesso;
            std::cin >> aux_acesso;
            if(aux_acesso != 1 && aux_acesso !=2 && aux_acesso !=0){
                throw "Ops, voce digitou um numero errado!";
            }
            else{
                if(aux_acesso == 1){
                    system("clear");
                    SessaoGerente->EmitirRelatorio();
                }
                else if(aux_acesso == 2){
                    SessaoGerente->EditarCreche();
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
    
}

void Gerente::EditarDados(){
    
}
