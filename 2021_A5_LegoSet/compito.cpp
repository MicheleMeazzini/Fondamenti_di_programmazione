#include "compito.h"

LegoSet::LegoSet() {
    head = nullptr;
}

ostream& operator<<(ostream& os, LegoSet& ls){
    if (ls.head == nullptr) return os;

    matt* p;
    for (p = ls.head; p!= nullptr; p=p->next)
        os << p->desc << ',' << ' ' << p->colore << endl;
    /*mattCom *q;
    for (q = headCom; q!= nullptr; q=q->next)
        os << q->desc << ',' << ' ' << q->colore << endl;*/
    return os;
}

void LegoSet::aggiungiMattoncino(char* d, char c){
    if (c != 'n' && c != 'b' && c != 'r' && c != 'v' && c != 'l') return;   //c invalido
    if (strlen(d) > 30) return;     //d troppo lungo

    /* for (matt *l = head; l!= nullptr; l=l->next)
        if (strcmp(l->desc, d) == 0) return; */   //mattoncino esiste gia

    matt *r = new matt; //alloco nuovo mattoncino
    strcpy(r->desc, d);
    switch (c) {
        case 'n':
            strcpy(r->colore, "nero");
            break;
        case 'b':
            strcpy(r->colore, "bianco");
            break;
        case 'r':
            strcpy(r->colore, "rosso");
            break;
        case 'v':
            strcpy(r->colore, "verde");
            break;
        case 'l':
            strcpy(r->colore, "blu");
            break;
    }

    matt *p, *q;
    if (head == nullptr){   //lista vuota
        r->next = nullptr;
        head = r;
    } else {    //lista con elementi presenti
        for (p = head; p!= nullptr; p=p->next)
            q = p;
        q->next = r;
        r->next = p;
    }
}

void LegoSet::eliminaMattoncino(char* d){
    if (strlen(d) > 30) return;
    if (head == nullptr) return;

    matt *p, *q;
    for (p = head; p != nullptr; p=p->next) {
        if (strcmp(p->desc, d) == 0){
            if (p == head)
                head = p->next;
            else
                q->next = p->next;
            return;
        }
        q = p;
    }
}

int LegoSet::operator%(char c){
    int conta = 0;
    matt *p;
    for (p = head; p!= nullptr; p=p->next) {
        if (c == 'n' && strcmp(p->colore, "nero") == 0)
            conta++;
        if (c == 'b' && strcmp(p->colore, "bianco") == 0)
            conta++;
        if (c == 'r' && strcmp(p->colore, "rosso") == 0)
            conta++;
        if (c == 'v' && strcmp(p->colore, "verde") == 0)
            conta++;
        if (c == 'l' && strcmp(p->colore, "blu") == 0)
            conta++;
    }
    return conta;
}

void LegoSet::eliminaMattoncino(char c){
    if (c != 'n' && c != 'b' && c != 'r' && c != 'v' && c != 'l') return;

    matt *p, *q;
    for (p = head; p!= nullptr ; p=p->next) {
        bool elimina = false;
        if (c == 'n' && strcmp(p->colore, "nero") == 0) elimina = true;
        if (c == 'b' && strcmp(p->colore, "bianco") == 0) elimina = true;
        if (c == 'r' && strcmp(p->colore, "rosso") == 0) elimina = true;
        if (c == 'v' && strcmp(p->colore, "verde") == 0) elimina = true;
        if (c == 'l' && strcmp(p->colore, "blu") == 0) elimina = true;
        if (elimina){
            if (p == head){
                p = p->next;
                head = p->next;
            } else {
                q->next = p->next;
            }
        }
        elimina = false;
        q = p;
    }
}

void LegoSet::aggiungiMattoncinoComune(int i, char *d, char c) {
    if (i < 1 || i > 100) return;
    if (strlen(d) > 30) return;
    if (c != 'n' && c != 'b' && c != 'r' && c != 'v' && c != 'l') return;
    for (mattCom *l = headCom; l!= nullptr; l=l->next)
        if (l->code == i) return;   //codice gia presente

    mattCom *r = new mattCom;  //alloco mattoncino comune
    r->code = i;
    strcpy(r->desc, d);
    switch (c) {
        case 'n':
            strcpy(r->colore, "nero");
            break;
        case 'b':
            strcpy(r->colore, "bianco");
            break;
        case 'r':
            strcpy(r->colore, "rosso");
            break;
        case 'v':
            strcpy(r->colore, "verde");
            break;
        case 'l':
            strcpy(r->colore, "blu");
            break;
    }

    if (headCom == nullptr){
        headCom = r;
        r->next = nullptr;
    } else{
        mattCom *p, *q;
        for (p = headCom; p!= nullptr ; p=p->next)
            q = p;
        q->next = r;
        r->next = p;
    }
    aggiungiMattoncinoComune(i);
}

void LegoSet::aggiungiMattoncinoComune(int i){
    if (i < 1 || i > 100) return;

    mattCom *l;
    for (l = headCom; l != nullptr && l->code != i; l=l->next);
    if (l == nullptr) return;   //codice non trovato

    matt *r = new matt;
    strcpy(r->desc, l->desc);
    strcpy(r->colore, l->colore);

    if (head == nullptr){
        head = r;
        r->next = nullptr;
    } else{
        matt *p, *q;
        for (p = head; p!= nullptr; p=p->next)
            q = p;
        q->next = r;
        r->next = p;
    }
}

LegoSet::~LegoSet() {
    head = nullptr;
}

