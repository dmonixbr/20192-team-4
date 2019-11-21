#ifndef LISTA_H
#define LISTA_H

#include<iostream>
#include "administrador.hpp"
#include "creche.hpp"
#include "gerente.hpp"

struct admins {
	Administrador admin;
    admins();
    ~admins();
    
	admins *proximo;
	admins *anterior;
};

struct creches {
    Creche creche;
    creches();
    ~creches();


    creches *proximo;
    creches *anterior;
};

struct gerentes {
    Gerente gerente;
    gerentes();
    ~gerentes();

    gerentes *proximo;
    gerentes *anterior;
};


struct ListaAdmins{
    admins *primeiro;
    admins *ultimo;
    int numero_de_admins;

    ListaAdmins();
    ~ListaAdmins();

    void insere_admin(Administrador);
    Administrador get_admin(int);
    int tamanho();
    void insere_primeiro(Administrador);
};

struct ListaCreches{
    creches *primeiro;
    creches *ultimo;
    int numero_de_creches;

    ListaCreches();
    ~ListaCreches();

    void insere_creche(Creche);
    Creche get_creche(int);
    void remover_creche(int);
    void remover_primeiro();
    void remover_ultimo();
    int tamanho();
    void insere_primeiro(Creche);
};

struct ListaGerentes{
    gerentes *primeiro;
    gerentes *ultimo;
    int numero_de_gerentes;

    ListaGerentes();
    ~ListaGerentes();

    void insere_gerente(Gerente);
    Gerente get_gerente(int);
    void remover_gerente(int);
    void remover_primeiro();
    void remover_ultimo();
    int tamanho();
    void insere_primeiro(Gerente);
};
#endif