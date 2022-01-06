#include "compito.h"

GestoreApp::GestoreApp() {
    head = nullptr;
}

void GestoreApp::operator+=(char* str){
    if (strlen(str) > 20) return;

    for (app *l = head; l!= nullptr; l=l->next)
        if (strcmp(l->nome, str) == 0) return;

    app *r = new app;
    strcpy(r->nome, str);
    r->foreg = true;

    if (head == nullptr){
        r->next = nullptr;
        head = r;
    } else {
        head->foreg = false;
        r->next = head;
        head = r;
    }
}

ostream& operator<<(ostream& os, GestoreApp& g){
    if (g.head == nullptr) {
        os << '[' << ']';
        return os;
    }
    app *p;
    for (p = g.head; p != nullptr; p = p->next)
        if (p->foreg)
            os << '[' << p->nome << ']';
        else
            os <<  ',' << ' ' << p->nome;

    return os;
}

void GestoreApp::foreground(char* str){
    if (strlen(str) > 20) return;
    if (head == nullptr) return;

    app *p, *q;
    for (p = head; p != nullptr; p = p->next) {
        if (strcmp(p->nome, str) == 0 && !p->foreg)
            break;
        q = p;
    }

    if (p == nullptr) return; //app str non è in esecuzione

    q->next = p->next;
    *this += p->nome;
    delete p;
}

void GestoreApp::operator-=(char* str){
    if (strlen(str) > 20) return;
    if (head == nullptr) return;

    if (strcmp(head->nome, str) == 0){  //app cercata è in esecuzione (è in testa)
        head = head->next;
        head->foreg = true;
        return;
    }

    app *p, *q;
    for (p = head; p != nullptr; p = p->next) {
        if (strcmp(p->nome, str) == 0) {
            q->next = p->next;
            delete p;
            break;
        }
        q = p;
    }
}

void GestoreApp::chiudi_tutte(){
    app *p, *q;
    for (p = head; p != nullptr; p = p->next) {
        q = p;
        delete q;
    }
    head = nullptr;
}

GestoreApp::~GestoreApp() {
    chiudi_tutte();
}

