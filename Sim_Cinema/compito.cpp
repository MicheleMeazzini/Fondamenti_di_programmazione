#include <iostream>
#include <cstring>
#include "compito.h"
using namespace std;

Cinema::Cinema(const int n, const int p, const char s[]){
    filetot = n;
    postitot = p;

    if (n <= 0 || n >= 27)
        filetot = 26;
    if (p <= 0 || p >= 9)
        postitot = 9;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 9; ++j) {
            seduta[i][j] = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            seduta[i][j] = 1;
        }
    }
    strcpy(nome, s);
}

bool Cinema::prenota(const char l, const int j) {       //1 posto libero, 0 posto occupato
    int numfila = int(l) - 65;
    if (seduta[numfila][j-1] == 1){                     //Il posto numero 4 nell'array è rappresentato dal 3
        seduta[numfila][j-1] = 0;                       //dato che negli array si parte da 0
        return true;
    }
    else                                                //posto occupato o esterno ai limiti di posto del cinema
        return false;
}

bool Cinema::cancella(const char l, const int j) {
    int numfila = int(l) - 65;
    if (seduta[numfila][j-1] == 0){
        seduta[numfila][j-1] = 1;
        return true;
    }
    else
        return false;
}

void Cinema::stampa() {
    cout << "Nome del cinema: " << nome << endl;
    cout << " ";
    for (int i = 1; i <= postitot; ++i) {
        cout << i;
    }
    cout<<endl;

    for (int j = 0; j < filetot; j++) {
        cout << char ('A'+j);
        for (int k = 0; k < postitot; k++) {
            if (seduta[j][k] == 0)
                cout << '*';
            else
                cout << ' ';
        }
        cout << endl;
    }
}

int Cinema::quantiLiberi() {
    int liberi = 0;
    for (int j = 0; j < filetot; j++) {
        for (int k = 0; k < postitot; k++) {
            if (seduta[j][k] == 1)
                liberi++;
        }
    }
    return liberi;
}

bool Cinema::prenotaAdiacenti(const int k) {
    int liberi = 0;
    for (int j = 0; j < filetot; j++) {
        for (int p = 0; p <= postitot; p++) {
            if (seduta[j][p] == 1)
                liberi++;
            if (seduta[j][p] == 0)
                liberi = 0;
            if(liberi == k){
                for (int i = 0; i < k; ++i) {
                    seduta[j][p] = 0;
                    p--;
                }
                return true;
            }
        }
        liberi = 0;
    }
    return false;
}