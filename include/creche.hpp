#ifndef CRECHE_H
#define CRECHE_H
#include <string>
#include <stdio.h>
#include "gerente.hpp"

class Creche {
    private:
        std::string nome;
        std::string telefone;
        std::string endereco;
        std::string validade_convenio;
        int pos_gerente;
        int numero_de_turmas;
        int numero_de_professores;
        int numero_de_coordenadores;
        int numero_de_auxiliares_bercario;
        int numero_de_alunos;
        float valor_per_capta_aluno;
        float valor_manuntencao;
        float faixa_etaria_media;
    public:

        Creche(std::string,std::string,std::string,std::string, int);

        //getters
        std::string get_nome();
        std::string get_telefone();
        std::string get_endereco();
        std::string get_validade_convenio();
        int get_pos_gerente();
        int get_numero_turmas();
        int get_numero_professores();
        int get_numero_coordenadores();
        int get_numero_aux_berc();
        int get_numero_alunos();
        float get_valor_per_capta();
        float get_valor_manuntencao();
        float get_faixa_etaria();


        //setters
        void set_nome(std::string);
        void set_telefone(std::string);
        void set_endereco(std::string);
        void set_validade_convenio(std::string);
        void set_pos_gerente(int);
        void set_numero_turmas(int);
        void set_numero_professores(int);
        void set_numero_coordenadores(int);
        void set_numero_aux_berc(int);
        void set_numero_alunos(int);
        void set_valor_per_capta(float);
        void set_valor_manuntencao(float);
        void set_faixa_etaria(float);
};

#endif
