#ifndef GERENTE_H
#define GERENTE_H
#include "usuario.hpp"

class Gerente : public Usuario {
    private:
        std::string periodo_mandato;
        std::string endereco;
        std::string telefone;
        int numero_de_turmas;
        int numero_de_professores;
        int numero_de_coordenadores;
        int numero_de_auxiliares_bercario;
        float valor_per_capta_aluno;
        float valor_manuntencao;
        float faixa_etaria_media;

        //funcoes creche
        
        void Deslogar() override;
        void EmitirRelatorio();
        void EditarCreche();
        int Menu();

        void VerDados() override;
        void EditarDados() override;
        
    public:

        Gerente();
        Gerente(std::string,std::string,std::string,std::string,std::string,std::string);

        //getters
        std::string get_telefone();
        std::string get_cpf() override;
        std::string get_periodo_mandato();
        std::string get_nome() override;
        std::string get_endereco();
        std::string get_senha() override;
        int get_numero_turmas();
        int get_numero_professores();
        int get_numero_coordenadores();
        int get_numero_aux_berc();
        float get_valor_per_capta();
        float get_valor_manuntencao();
        float get_faixa_etaria();

        //setters
        void set_periodo_mandato(std::string);
        void set_endereco(std::string);
        void set_telefone(std::string);
        void set_cpf(std::string) override;
        void set_nome(std::string) override;
        void set_senha(std::string) override;
        void Login(std::string) override;
        void set_numero_turmas(int);
        void set_numero_professores(int);
        void set_numero_coordenadores(int);
        void set_numero_aux_berc(int);
        void set_valor_per_capta(float);
        void set_valor_manuntencao(float);
        void set_faixa_etaria(float);
};


#endif