#ifndef ESAMEMEAZZINI_COMPITO_H
#define ESAMEMEAZZINI_COMPITO_H

//Michele Meazzini 635889

#include <iostream>
using namespace std;

class Memory{
    char **schema;
    int dim;
    int punt;
    int coppie_G;
    int coppie_C;
    int coppie_S;
    int coppie_P;
    int coppie_T;
    bool playing;

public:
    Memory(int N);
    ~Memory();
    Memory(const Memory& m1);
    friend ostream& operator<<(ostream& os, const Memory& m);
    void inserisci(char tipo, int riga1, int colonna1, int riga2, int colonna2);
    void riassumi();
    bool flip(int riga1, int colonna1, int riga2, int colonna2);
    Memory operator+(const Memory& m1);
    Memory& operator>>(int i);
};




#endif //ESAMEMEAZZINI_COMPITO_H

// fine file
