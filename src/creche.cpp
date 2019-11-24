#include "../include/creche.hpp"
#include <iostream>

Creche::Creche(std::string _nome, std::string _telefone, std::string _endereco, std::string _validate_convenio, int _gerente){
    this->nome = _nome;
    this->telefone = _telefone;
    this->endereco = _endereco;
    this->validade_convenio = _validate_convenio;
    this->pos_gerente = _gerente;
}



//setters
void Creche::set_nome(std::string _nome){
    this->nome = _nome;
}
void Creche::set_telefone(std::string _telefone){
    this->telefone = _telefone;
}
void Creche::set_endereco(std::string _endereco){
    this->endereco = _endereco;
}
void Creche::set_validade_convenio(std::string validade_convenio){
    this->validade_convenio = validade_convenio;
}
void Creche::set_pos_gerente(int pos_gerente){
    this->pos_gerente = pos_gerente;
}
void Creche::set_numero_turmas(int _turmas){
    this->numero_de_turmas = _turmas;
}
void Creche::set_numero_professores(int _professores){
    this->numero_de_professores = _professores;
}
void Creche::set_numero_coordenadores(int _coordenadores){
    this->numero_de_coordenadores = _coordenadores;
}
void Creche::set_numero_aux_berc(int _aux_berc){
    this->numero_de_auxiliares_bercario = _aux_berc;
}
void Creche::set_numero_alunos(int _alunos){
    this->numero_de_alunos = _alunos;
}
void Creche::set_valor_per_capta(float _per_capta){
    this->valor_per_capta_aluno = _per_capta;
}
void Creche::set_valor_manuntencao(float _manuntencao){
    this->valor_manuntencao = _manuntencao;
}
void Creche::set_faixa_etaria(float _faixa){
    this->faixa_etaria_media = _faixa;
}



//getters
std::string Creche::get_nome(){
    return this->nome;
}
std::string Creche::get_endereco(){
    return this->endereco;
}
std::string Creche::get_telefone(){
    return this->telefone;
}
std::string Creche::get_validade_convenio(){
    return this->validade_convenio;
}
int Creche::get_pos_gerente(){
    return this->pos_gerente;
}
int Creche::get_numero_turmas(){
    return this->numero_de_turmas;
}
int Creche::get_numero_professores(){
    return this->numero_de_professores;
}
int Creche::get_numero_coordenadores(){
    return this->numero_de_coordenadores;
}
int Creche::get_numero_aux_berc(){
    return this->numero_de_auxiliares_bercario;
}
int Creche::get_numero_alunos(){
    return this->numero_de_alunos;
}
float Creche::get_valor_per_capta(){
    return this->valor_per_capta_aluno;
}
float Creche::get_valor_manuntencao(){
    return this->valor_manuntencao;
}
float Creche::get_faixa_etaria(){
    return this->faixa_etaria_media;
}