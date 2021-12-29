#include <iostream>
#include <cstring>
#include "compito.h"
using namespace std;

Timeline::Timeline() {
    headpost = nullptr;
}

Timeline::~Timeline(){
    elem *p, *q;
    for (p = headpost; p != nullptr; p = p->next) {
        q = p;
        delete q;
    }
    headpost = nullptr;
}

void Timeline::pubblica(const char* n, const int evid){
    if (evid != 1 && evid != 0)
        return;
    if (strlen(n) < 1)
        return;

    elem* post = new elem;
    post->nome = new char[strlen(n) + 1];
    strcpy(post->nome, n);

    if (evid == 1) {        //inserimento in testa se il contenuto va in evidenza
        post->evidenza = 1;
        post->next = headpost;
        headpost = post;
    }
    if (evid == 0){         //inserimento in testa se non ci sono altri post oppure se il post in testa non è in evidenza
        post->evidenza = 0;
        elem *p, *q;

        for (p = headpost; p != nullptr && p->evidenza != 0; p = p->next)
            q = p;
        if (p == headpost){
            post->next = headpost;
            headpost = post;
        }else{
            post->next = p;
            q->next = post;
        }
    }
}

void Timeline::cancella(const char* n) {
    elem *p, *q;
    for (p = headpost; p != nullptr; p = p->next) {
        if (strcmp(p->nome, n) == 0) {
            q->next = p->next;
            delete p;
            return;
        }
        q = p;
    }
}

ostream& operator<<(ostream& out, const Timeline& timel){
    out << "-----" << endl;
    for (elem* p = timel.headpost;  p != nullptr ; p = p->next) {
        if (p->evidenza)
            out << "(*) ";
        out << p->nome;
        out << endl;
    }
    out << "-----" << endl;
    return out;
}

bool Timeline::operator!() {
    bool canc = false;
    elem *p, *q;
    for (p = headpost; p != nullptr && p->evidenza != 0; p = p->next){
        q = p;
        delete q;
        canc = true;
    }
    headpost = p;
    return canc;
}

void Timeline::mettiInEvidenza(const char *n) {
    elem *p, *q;

    for (p = headpost; p != nullptr; p= p->next){
        if (!strcmp(p->nome, n) && p->evidenza == 1)
            return;
        if (!strcmp(p->nome, n)) {
            elem* r = new elem;             //inserimento in testa
            r->nome = new char [strlen(n)+1];
            strcpy(r->nome, n);
            r->evidenza = 1;
            r->next = headpost;
            headpost = r;
            q->next = p->next;              //elimino elemento trovato
            delete p;
            return;
        }
        q = p;
    }
}


