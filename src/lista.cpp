#include "../include/lista.hpp"

ListaAdmins::ListaAdmins(){
    primeiro = nullptr;
    ultimo = nullptr;
    numero_de_admins = 0;
}

ListaCreches::ListaCreches(){
    primeiro = nullptr;
    ultimo = nullptr;
    numero_de_creches = 0;
}

ListaGerentes::ListaGerentes(){
    primeiro = nullptr;
    ultimo = nullptr;
    numero_de_gerentes = 0;
}

ListaAdmins::~ListaAdmins(){
    admins *anterior = nullptr;
    admins *proximo = primeiro;

    while(proximo != nullptr){
        anterior = proximo;
        proximo = proximo->proximo;
        delete anterior;
    }
}

ListaCreches::~ListaCreches(){
    creches *anterior = nullptr;
    creches *proximo = primeiro;

    while(proximo != nullptr){
        anterior = proximo;
        proximo = proximo->proximo;
        delete anterior;
    }
}

ListaGerentes::~ListaGerentes(){
    gerentes *anterior = nullptr;
    gerentes *proximo = primeiro;

    while(proximo != nullptr){
        anterior = proximo;
        proximo = proximo->proximo;
        delete anterior;
    }
}

int ListaAdmins::tamanho(){
    return this->numero_de_admins;
}

int ListaCreches::tamanho(){
    return this->numero_de_creches;
}

int ListaGerentes::tamanho(){
    return this->numero_de_gerentes;
}

void ListaAdmins::insere_primeiro(Administrador _admin){
    admins *novo_no = new admins();
    
    novo_no->admin = _admin;
    novo_no->proximo = nullptr;
    novo_no->anterior = nullptr;

    if(tamanho() == 0){
        primeiro = novo_no;
        ultimo = novo_no;
        numero_de_admins++;
    }
    else{
        admins* atual = primeiro;
        primeiro = novo_no;
        novo_no->proximo = atual;
        atual->anterior = novo_no;
        numero_de_admins++;
    }
}

void ListaCreches::insere_primeiro(Creche _creche){
    creches *novo_no = new creches();
    
    novo_no->creche = _creche;
    novo_no->proximo = nullptr;
    novo_no->anterior = nullptr;

    if(tamanho() == 0){
        primeiro = novo_no;
        ultimo = novo_no;
        numero_de_creches++;
    }
    else{
        creches* atual = primeiro;
        primeiro = novo_no;
        novo_no->proximo = atual;
        atual->anterior = novo_no;
        numero_de_creches++;
    }
}

void ListaGerentes::insere_primeiro(Gerente _gerente){
    gerentes *novo_no = new gerentes();
    
    novo_no->gerente = _gerente;
    novo_no->proximo = nullptr;
    novo_no->anterior = nullptr;

    if(tamanho() == 0){
        primeiro = novo_no;
        ultimo = novo_no;
        numero_de_gerentes++;
    }
    else{
        gerentes* atual = primeiro;
        primeiro = novo_no;
        novo_no->proximo = atual;
        atual->anterior = novo_no;
        numero_de_gerentes++;
    }
}

void ListaAdmins::insere_admin(Administrador _admin){
    if(tamanho() == 0){
        insere_primeiro(_admin);
    }
    else{
        admins *novo_no = new admins();

        novo_no->admin = _admin;
        novo_no->proximo = nullptr;
        novo_no->anterior = nullptr;

        ultimo->proximo = novo_no;
        novo_no->anterior = ultimo;
        ultimo = novo_no;
        numero_de_admins++;
    }
}

void ListaCreches::insere_creche(Creche _creche){
    if(tamanho() == 0){
        insere_primeiro(_creche);
    }
    else{
        creches *novo_no = new creches();

        novo_no->creche = _creche;
        novo_no->proximo = nullptr;
        novo_no->anterior = nullptr;

        ultimo->proximo = novo_no;
        novo_no->anterior = ultimo;
        ultimo = novo_no;
        numero_de_creches++;
    }
}

void ListaGerentes::insere_gerente(Gerente _gerente){
    if(tamanho() == 0){
        insere_primeiro(_gerente);
    }
    else{
        gerentes *novo_no = new gerentes();

        novo_no->gerente = _gerente;
        novo_no->proximo = nullptr;
        novo_no->anterior = nullptr;

        ultimo->proximo = novo_no;
        novo_no->anterior = ultimo;
        ultimo = novo_no;
        numero_de_gerentes++;
    }
}

Administrador ListaAdmins::get_admin(int n){
    admins *atual = primeiro;
    int i=0;
    while(i<n){
        atual = atual->proximo;
        i++;
    }
    return atual->admin;
}

Creche ListaCreches::get_creche(int n){
    creches *atual = primeiro;
    int i=0;
    while(i<n){
        atual = atual->proximo;
        i++;
    }
    return atual->creche;
}

Gerente ListaGerentes::get_gerente(int n){
    gerentes *atual = primeiro;
    int i=0;
    while(i<n){
        atual = atual->proximo;
        i++;
    }
    return atual->gerente;
}