#include <iostream>
#include "compito.h"
using namespace std;

PuzzleBobble::PuzzleBobble() {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 8; ++j) {
            schema[i][j] = ' ';
        }
    }
    for (int j = 0; j < 8; ++j) {
        schema[0][j] = '=';
    }
    for (int i = 1; i <= 10; ++i) {
        for (int j = 0; j == 0 || j == 7; j += 7) {
            schema[i][j] = '|';
        }
    }
    for (int j = 0; j < 8; ++j) {
        schema[11][j] = '=';
    }
}

void PuzzleBobble::print() {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << schema[i][j];
        }
        cout << endl;
    }
}

PuzzleBobble& PuzzleBobble::fire(const int colonna, const char colore){
    //spara bolla
    int jj = colonna + 1;           //ii,jj coordinate bolla appena sparata
    int ii = 0;
    if (colonna >= 6 || colonna < 0)
        return *this;
    if (colore != 'R' && colore != 'G' && colore != 'B' && colore != 'Y')
        return *this;
    for (int i = 10; i >= 0; --i) {
        if (schema[i][colonna + 1] != ' ' && schema[i + 1][colonna + 1] == ' ') {
            schema[i + 1][colonna + 1] = colore;
            ii = i + 1;              //ii prende il numero della riga in cui si è fermata la bolla
            break;
        }
    }
    //meccanica dello scoppio
    int contadx = 0, contasx = 0, contasu = 0;
    for (int j = jj + 1; j < 7; ++j) {
        if (schema[ii][j] == colore)
            contadx++;
        else break;
    }
    for (int j = jj - 1; j > 0; --j) {
        if (schema[ii][j] == colore)
            contasx++;
        else break;
    }
    for (int i = ii - 1; i > 0; --i) {
        if (schema[i][jj] == colore)
            contasu++;
        else break;
    }
    if (contadx + contasx + contasu >= 2){
        for (int j = jj + 1; j < 7; ++j) {
            if (schema[ii][j] == colore)
                schema[ii][j] = ' ';
            else break;
        }
        for (int j = jj - 1; j > 0; --j) {
            if (schema[ii][j] == colore)
                schema[ii][j] = ' ';
            else break;
        }
        for (int i = ii - 1; i > 0; --i) {
            if (schema[i][jj] == colore)
                schema[i][jj] = ' ';
            else break;
        }
        schema[ii][jj] = ' ';
        return *this;
    }
    return *this;
}

int PuzzleBobble::height() {
    int altezza = 0;
    for (int i = 1; i < 11; ++i) {
        for (int j = 1; j < 7; ++j) {
            if (schema[i][j] != ' ')
                altezza++;
            break;
        }
    }
    return altezza;
}

PuzzleBobble& PuzzleBobble::scroll() {
    for (int j = 1; j < 7; ++j) {       //scroll viene fatto solo se l'ultima riga dello schema è priva di bolle
        if (schema[10][j] != ' ')
            return *this;
    }
    for(int i = 10; i > 0 ; --i) {       //scorre le righe dal basso verso l'alto, escludendo il bordo inferiore
        for (int j = 1; j < 6; ++j) {    //scorre le colonne da sinistra a destra, escludento i bordi destro e sinistro
            schema[i][j] = schema[i - 1][j];
        }
    }
    return *this;
}

void PuzzleBobble::compact() {
    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j < 7; ++j) {
            for (int k = 0; k < 10 - i; ++k) {
                if (schema[i + k][j] == ' ') {
                    schema[i + k][j] = schema[i + k + 1][j];
                    schema[i + k + 1][j] = ' ';
                }
            }
        }
    }
}




