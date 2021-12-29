#include "compito.h"

Nastro::Nastro(){
    conto = 0;
    head = nullptr;
}

void Nastro::aggiungi(char* s, int c) {
    if (strlen(s) > 25) strcpy(s, " ");
    if (c < 0) c = 0;

    for (piatto *l = head; l!= nullptr; l=l->next) {    //controllo che non ci sia un piatto con nome s ma prezzo diverso
        if (strcmp(l->nome, s) == 0 && l->prezzo != c)
            return;
    }

    piatto *r = new piatto;  //alloco un nuovo piatto
    strcpy(r->nome, s);
    r->prezzo = c;

    if (head == nullptr) {  //inserimento in testa se il nastro è vuoto
        head = r;
        r->next = nullptr;
        return;
    }else {
        if (head->prezzo > c) {  //inserimento in testa se il piatto head ha prezzo maggiore del
            r->next = head;                                     //nuovo piatto e il nuovo piatto precede head nell'ordine alfabetico
            head = r;
            return;
        }
    }
    piatto *p, *q;
    for (p = head; p!= nullptr && (p->prezzo < c || (p->prezzo == c && strcmp(s, p->nome) >= 0)); p=p->next)
        q = p;
    q->next = r;
    r->next = p;
}

ostream& operator<<(ostream& os, const Nastro& n){
    os << "Piatti sul nastro:" << endl;
    piatto *p;
    for (p = n.head; p!= nullptr; p=p->next) {
        os << '\t' << p->nome << ' ' << p->prezzo << endl;
    }
    os << "Conto: " << n.conto << endl;
    return os;
}

Nastro& Nastro::consuma(char *s) {
    if (head == nullptr) return *this;
    if (strcmp(head->nome, s) == 0){
        head = head->next;
        return *this;
    }

    piatto *p, *q;
    for (p = head; p!= nullptr && strcmp(s, p->nome) != 0; p=p->next)
        q = p;
    conto += p->prezzo;
    q->next = p->next;
    delete p;

    return *this;
}

Nastro& Nastro::operator+=(Nastro& n){
    if (n.head == nullptr) return *this;

    piatto *p;
    for (p = n.head; p!= nullptr; p=p->next)
        aggiungi(p->nome, p->prezzo);

    return *this;
}

Nastro Nastro::operator|(const Nastro &n1) {
    Nastro nn;
    piatto *p1, *p2;

    for (p1 = head; p1 != nullptr; p1=p1->next) {
        for (p2 = n1.head; p2 != nullptr && strcmp(p1->nome, p2->nome) != 0; p2 = p2->next) {}
        if (p2 == nullptr || p1->prezzo == p2->prezzo)
            nn.aggiungi(p1->nome, p1->prezzo);
        else if (p1->prezzo < p2->prezzo)
            nn.aggiungi(p1->nome, p1->prezzo);
        else
            nn.aggiungi(p2->nome, p2->prezzo);
    }
    for (p2 = n1.head; p2!= nullptr; p2=p2->next) {
        for (p1 = head; p1 != nullptr && strcmp(p2->nome, p1->nome) != 0; p1=p1->next) {}
        if (p1 == nullptr || p2->prezzo == p1->prezzo)
            nn.aggiungi(p2->nome, p2->prezzo);
    }
    return nn;
}

Nastro::~Nastro(){
    head = nullptr;
}
