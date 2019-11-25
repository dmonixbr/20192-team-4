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

        Creche(std::string,std::string,std::string,std::string, int); //OK

        //getters
        std::string get_nome(); //OK
        std::string get_telefone(); //OK
        std::string get_endereco(); //OK
        std::string get_validade_convenio(); //OK
        int get_pos_gerente(); //OK
        int get_numero_turmas(); //OK
        int get_numero_professores(); //OK
        int get_numero_coordenadores(); //OK
        int get_numero_aux_berc(); //OK
        int get_numero_alunos(); //OK
        float get_valor_per_capta(); //OK
        float get_valor_manuntencao(); //OK
        float get_faixa_etaria(); //OK


        //setters
        void set_nome(std::string); //OK
        void set_telefone(std::string); //OK
        void set_endereco(std::string); //OK
        void set_validade_convenio(std::string); //OK
        void set_pos_gerente(int); //OK
        void set_numero_turmas(int); //OK
        void set_numero_professores(int); //OK
        void set_numero_coordenadores(int); //OK
        void set_numero_aux_berc(int); //OK
        void set_numero_alunos(int); //OK
        void set_valor_per_capta(float); //OK
        void set_valor_manuntencao(float); //OK
        void set_faixa_etaria(float); //OK
};

#endif
