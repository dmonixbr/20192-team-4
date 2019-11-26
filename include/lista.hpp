#ifndef LISTA_H
#define LISTA_H

#include<iostream>
#include "administrador.hpp"
#include "creche.hpp"
#include "gerente.hpp"

struct admins {
	Administrador *admin;
    admins();
    ~admins();
    
	admins *proximo;
	admins *anterior;
};

struct creches {
    Creche *creche;
    creches();
    ~creches();


    creches *proximo;
    creches *anterior;
};

struct gerentes {
    Gerente *gerente;
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

    void insere_admin(Administrador *_admin);
    Administrador *get_admin(int);
    int tamanho();
    void insere_primeiro(Administrador *_admin);
};

struct ListaCreches{
    creches *primeiro;
    creches *ultimo;
    int numero_de_creches;

    ListaCreches();
    ~ListaCreches();

    void insere_creche(Creche *_creche);
    Creche *get_creche(int);
    void remover_creche(int);
    void remover_primeiro();
    void remover_ultimo();
    int tamanho();
    void insere_primeiro(Creche *_creche);
};

struct ListaGerentes{
    gerentes *primeiro;
    gerentes *ultimo;
    int numero_de_gerentes;

    ListaGerentes();
    ~ListaGerentes();

    void insere_gerente(Gerente *_ger);
    Gerente *get_gerente(int);
    void remover_gerente(int);
    void remover_primeiro();
    void remover_ultimo();
    int  tamanho();
    void insere_primeiro(Gerente *_ger);
};
#endif