#include <iostream>
#include "compito.h"

VettoreSparso::VettoreSparso(int dim){
    dimensione = (dim <= 0) ? 10: dim;
    testa = nullptr;
}

void VettoreSparso::set(int val, int ind){
    if (val == 0 || ind < 0 || ind >= dimensione)
        return;

    elem *p, *q;
    for (p = testa; p != nullptr && p->indice <= ind; p=p->next)    //q è sempre un blocco indetro a p
        q = p;

    if(p == testa){ //inserimento in testa
        testa = new elem;
        testa->valore = val;
        testa->indice = ind;
        testa->next = p;
    }else{
        if (q->indice == ind) {
            q->valore = val;
        }else
            if (q->indice < ind) { //inserimento in coda o in mezzo
                elem *r = new elem;
                r->indice = ind;
                r->valore = val;
                r->next = p;
                q->next = r;
            }
    }
}

ostream& operator<<(ostream& os, const VettoreSparso& vett){
    os << '[' << vett.dimensione << ']' << '{';

    for (elem* scorri = vett.testa; scorri != 0; scorri = scorri->next)
        os << '(' << scorri->valore << ',' << scorri->indice << ')';

    os << '}';
    return os;
}

void VettoreSparso::visualizzaComeDenso() {
    cout << "< ";
    int vettDenso[dimensione];
    for (int i = 0; i < dimensione; ++i)
        vettDenso[i] = 0;

    for (elem* scorri = testa; scorri != 0; scorri = scorri->next)
        vettDenso[scorri->indice] = scorri->valore;

    for (int i = 0; i < dimensione; ++i)
        cout << vettDenso[i] << ' ';
    cout << '>';
}

void VettoreSparso::reset(int ind) {
    if(ind < 0 || ind >= dimensione)
        return;
    elem *p, *q;
    for (p = testa; p != nullptr && p->indice != ind; p = p->next)
        q = p;

    if (p->indice == ind) {
        if (p != testa){
            q->next = p->next;
            delete p;
        }
        if (p == testa){
            testa = p->next;
            delete p;
        }
    }
}

VettoreSparso& VettoreSparso::operator*=(int k) {
    if (k == 0)
        distruggi();

    if (k != 0) {
        elem *scorri;
        for (scorri = testa; scorri != 0; scorri = scorri->next)
            scorri->valore *= k;
    }
}

void VettoreSparso::distruggi(){
    elem *q;
    for (elem *p = testa; p!= nullptr; p = q) {
        q = p->next;
        delete p;
    }
    testa = nullptr;
}