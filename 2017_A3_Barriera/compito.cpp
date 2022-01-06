#include "compito.h"

Barriera::Barriera() {
    for (int i = 0; i < 3; ++i){
        barr[i].stato = true;
        barr[i].numVeicoli = 0;
        barr[i].head = nullptr;
    }
    for (int i = 3; i < 5; ++i){
        barr[i].stato = false;
        barr[i].numVeicoli = 0;
        barr[i].head = nullptr;
    }
}

Barriera Barriera::nuovoVeicolo(char *s){
    if (strlen(s) != 6) return *this;
    for (int i = 0; i < 6; ++i) {
        if (s[i] < 65 || s[i] > 91)
            return *this;
    }

    int minVeicoli;
    int barrMinVeicoli;
    for (int i = 0; i < 5; ++i){
        if (barr[i].stato) {
            barrMinVeicoli = i;
            break;
        }
    }
    for (int i = 0; i < 5; ++i) {
        if (barr[i].stato && barr[i].numVeicoli < minVeicoli) {
            minVeicoli = barr[i].numVeicoli;
            barrMinVeicoli = i;
        }
    }

    veicolo* r = new veicolo;
    strcpy(r->targa, s);
    if (barr[barrMinVeicoli].head == nullptr){
        barr[barrMinVeicoli].head = r;
        r->next = nullptr;
        barr[barrMinVeicoli].numVeicoli++;
    } else {
        veicolo *p, *q;
        for (p = barr[barrMinVeicoli].head; p != nullptr; p = p->next)
            q = p;
        q->next = r;
        r->next = p;
        barr[barrMinVeicoli].numVeicoli++;
    }
    return *this;
}

bool Barriera::serviVeicolo(int i){
    if (!barr[i-1].stato) return false;
    if (barr[i-1].numVeicoli == 0) return false;
    veicolo *p = barr[i-1].head;
    barr[i-1].head = barr[i-1].head->next;
    delete p;
    barr[i-1].numVeicoli--;
    return true;
}

ostream& operator<<(ostream& os, Barriera& b) {
    for (int i = 0; i < 5; ++i) {
        os << '[' << i + 1 << ']' << ' ';
        if (!b.barr[i].stato) {
            os << "(chiuso)" << endl;
        } else {
            if (b.barr[i].stato && b.barr[i].head == nullptr)
                os << "(libero)" << endl;
            else {
                for (veicolo *p = b.barr[i].head; p != nullptr; p = p->next) {
                    os << p->targa;
                    if (p->next != nullptr)
                        os << "=>";
                }
                os << endl;
            }
        }
    }
}

int Barriera::apriOppureChiudi(double mediaIdeale){
    int somma = 0, media = 0, casAperti = 0;
    for (int i = 0; i < 5; ++i) {
        if (barr[i].stato) {
            somma += barr[i].numVeicoli;
            casAperti++;
        }
    }
    if (casAperti == 0) return 0;
    media = somma/casAperti;

    if (media <= mediaIdeale){
        for (int i = 0; i < 5; ++i) {
            if (barr[i].stato && barr[i].numVeicoli == 0){
                barr[i].stato = false;
                return -1;
            }
        }
        return 0;
    }
    if (media > mediaIdeale){
        for (int i = 4; i >= 0; --i){
            if (!barr[i].stato) {
                barr[i].stato = true;
                return 1;
            }
        }
        return 0;
    }
}

Barriera::operator int() {
    int somma = 0;
    for (int i = 0; i < 5; ++i)
        if (barr[i].stato)
            somma += barr[i].numVeicoli;

    return somma;
}

Barriera::~Barriera(){
    for (int i = 0; i < 5; ++i) {
        barr[i].stato = false;
        barr[i].numVeicoli = 0;
        barr[i].head = nullptr;
    }
}
