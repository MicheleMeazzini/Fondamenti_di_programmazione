#include "compito.h"

Flotta::Flotta(int n) {
    if (n < 0) return;
    maxfile = n;
    flotta = new int[n];
    for (int i = 0; i < n; ++i)
        flotta[i] = -1;     //fila non formata
    fila_aggiunta = false;
}

Flotta::~Flotta() {
    delete flotta;
}

Flotta::Flotta(const Flotta& f){
    maxfile = f.maxfile;
    flotta = new int[maxfile];
    for (int i = 0; i < maxfile; ++i)
        flotta[i] = f.flotta[i];
    fila_aggiunta = f.fila_aggiunta;
}

void Flotta::forma_fila(int i, int n){
    if (n < 0) return;
    if (i >= maxfile || i < 0) return;

    if (flotta[i] == -1) {
        flotta[i] = n;
        fila_aggiunta = true;
    }
}

Flotta::operator int()const {
    int max = flotta[0];
    for (int i = 0; i < maxfile; ++i) {
        if (flotta[i] > max)
            max = flotta[i];
    }
    if (max == -1) return 0;
    return max;
}

ostream& operator<<(ostream& os, const Flotta& f){
    int max = (int)f;

    for (int i = 0; i < f.maxfile; ++i) {
        if (!f.fila_aggiunta)
            os << ' ';
        else {
            if (f.flotta[i] == -1) {
                for (int j = 0; j < max; ++j)
                    os << '?' << ' ';
            } else {
                for (int k = f.flotta[i]; k < max ; ++k) {
                    os << ' ';
                }
                for (int j = 0; j < f.flotta[i]; ++j)
                    os << 'A' << ' ';
            }
        }
        os << endl;
    }
    return os;
}

Flotta Flotta::operator+(const Flotta &f) {
    Flotta ff(maxfile + f.maxfile);
    for (int i = 0; i < maxfile; ++i)
        ff.flotta[i] = flotta[i];
    for (int i = maxfile; i < maxfile + f.maxfile; ++i)
        ff.flotta[i] = f.flotta[i-maxfile];

    ff.fila_aggiunta = fila_aggiunta || f.fila_aggiunta;
    return ff;
}

Flotta Flotta::operator-=(const Flotta& f){
    if (maxfile != f.maxfile) return *this;
    for (int i = 0; i < maxfile; ++i)
        if (flotta[i] == - 1) return *this;
    for (int i = 0; i < f.maxfile; ++i)
        if (f.flotta[i] == -1) return *this;

    for (int i = 0; i < maxfile; ++i) {
        if (flotta[i] < f.flotta[i])
            flotta[i] = 0;
        if (flotta[i] == f.flotta[i])
            flotta[i] = flotta[i]/2;
    }
    return *this;
}

Flotta Flotta::operator+=(const int v[]){
    for (int i = 0; i < maxfile; ++i)
        if (v[i] > 1000) return *this;  //vettore ha troppi pochi elementi

    for (int i = 0; i < maxfile; ++i) {
        if (flotta[i] != -1 && v[i] > 0)
            flotta[i] += v[i];
    }
    return *this;
}

