#include "compito.h"

Prenotazione::Prenotazione() {
    stato = true;
    testa = nullptr;
}

void Prenotazione::prenota(int cli, tipo ti) {
    if (!stato) return;
    if (cli <= 0) return;
    if (ti != GOLD && ti != SILVER) return;

    if (testa == nullptr) { //inserimento in testa se la lista è vuota
        pren *r = new pren;
        r->cliente = cli;
        if (ti == GOLD)
            r->tipo = GOLD;
        if (ti == SILVER)
            r->tipo = SILVER;
        r->next = nullptr;
        testa = r;
        return;
    }
    if (ti == GOLD){
        if (testa->tipo) {  //inserimento in testa se tutte le prenotazioni sono silver e aggiungo una gold
            pren *r = new pren;
            r->cliente = cli;
            r->tipo = GOLD;
            r->next = testa;
            testa = r;
            return;
        }
        pren *p, *q;
        for (p = testa; p!= nullptr && p->tipo == 0; p=p->next)  //inserimento in mezzo o in coda se ci sono altre prenotazioni gold
            q = p;
        pren *k = new pren;
        k->cliente = cli;
        k->tipo = GOLD;
        q->next = k;
        k->next = p;
        return;
    }
    if (ti == SILVER){  //l'if non importerebbe, lo lascio per semplificare la lettura del programma
        pren *p, *q;    //inserimento in coda se prenoto una silver
        for (p = testa; p!= nullptr; p=p->next)
            q = p;
        pren *r = new pren;
        r->cliente = cli;
        r->tipo = SILVER;
        q->next = r;
        r->next = nullptr;
        return;
    }
}

void Prenotazione::cancella(int cli, tipo ti) {
    if (!stato) return;
    if (testa == nullptr) return;   //prenotazioni vuote

    pren *p, *q;
    for (p = testa; p!= nullptr; p=p->next) {
        if (p->cliente == cli && p->tipo == ti)
            break;
        q = p;
    }   //a questo punto p punta alla pren che sto cercando, q punta a quella precedente
    if (p == nullptr) return;  //prenotazione inesistente

    q->next = p->next;
    delete p;
}

ostream& operator<<(ostream& os, Prenotazione& p){
    os << "GOLD" << endl;
    pren *l;
    for (l = p.testa; l != nullptr && !l->tipo ; l=l->next)
        os << l->cliente << endl;

    os << "SILVER" << endl;
    for (; l != nullptr; l=l->next)
        os << l->cliente << endl;

    return os;
}

Prenotazione::operator int() {
    int contaGold = 0;
    pren *p;
    for (p = testa; p!= nullptr ; p=p->next) {
        if (p->tipo == GOLD && contaGold < 5)
            contaGold++;
    }
    return (5-contaGold);
}

Prenotazione::~Prenotazione() {
    testa = nullptr;
}

Ammessi Prenotazione::chiudi() {
    stato = false;
    Ammessi am;

    pren *f;
    int i = 0;
    for (f = testa; f != nullptr && i < 5 ; f=f->next) {
        am.elenco[i].id = f->cliente;
        am.elenco[i].t = f->tipo;
        am.quanti++;
        i++;
    }
    return am;
}

Ammessi::Ammessi() {
    for (int i = 0; i < 5; ++i) {
        elenco[i].id = 0;
        elenco[i].t = -1;
    }
    quanti = 0;
}

