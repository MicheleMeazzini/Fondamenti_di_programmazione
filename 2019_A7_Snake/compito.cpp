#include "compito.h"

Snake::Snake(int r, int c) {
    if (r<4)    //sanitizzo l'input
        righe = 4;
    if (c<4)
        colonne = 4;
    righe = r;
    colonne = c;

    schema = new int*[r];   //alloco una matrice dinamica
    for (int i = 0; i < righe; ++i) {
        schema[i] = new int[c];
        for (int j = 0; j < colonne; ++j) {
            schema[i][j] = 0;
        }
    }

    lunghezza = 4;
    direzione = 'n';
    schema[righe-1][0] = 4;
    schema[righe-2][0] = 3;
    schema[righe-3][0] = 2;
    schema[righe-4][0] = 1;
    rigaTesta = righe-4;
    colTesta = 0;
}

ostream& operator<<(ostream& os, Snake& s){
    for (int i = 0; i <= s.colonne+1; ++i) {    //prima riga
        if (i == 0 || i == s.colonne+1)
            os << '|';
        else
            os << '-';
    }
    os << endl;

    for (int i = 0; i < s.righe; ++i) {
        for (int j = 0; j <= s.colonne+1 ; ++j) {
            if (j == 0 || j == s.colonne+1)
                os << '|';
            else{
                if (s.schema[i][j-1] > 0)
                    os << s.schema[i][j-1];
                else if (s.schema[i][j-1] == -1)
                    os << '*';
                else
                    os << ' ';
            }
        }
        os << endl;
    }
    for (int i = 0; i <= s.colonne+1; ++i) {    //prima riga
        if (i == 0 || i == s.colonne+1)
            os << '|';
        else
            os << '-';
    }
    return os;
}

Snake& Snake::muovi(char dir) {
    if (dir == 'n' && (rigaTesta-1 < 0 || direzione == 's' || schema[rigaTesta-1][colTesta] > 0)) return *this;
    if (dir == 's' && (rigaTesta+1 >= righe || direzione == 'n' || schema[rigaTesta+1][colTesta] > 0)) return *this;
    if (dir == 'o' && (colTesta-1 < 0 || direzione == 'e' || schema[rigaTesta][colTesta-1] > 0)) return *this;
    if (dir == 'e' && (colTesta+1 >= colonne || direzione == 'o' || schema[rigaTesta][colTesta+1] > 0)) return *this;

    bool mangiata = false;
    if (lunghezza < 9) {
        if (dir == 'n' && schema[rigaTesta - 1][colTesta] == -1) {lunghezza++; mangiata = true;}
        if (dir == 's' && schema[rigaTesta + 1][colTesta] == -1) {lunghezza++; mangiata = true;}
        if (dir == 'o' && schema[rigaTesta][colTesta - 1] == -1) {lunghezza++; mangiata = true;}
        if (dir == 'e' && schema[rigaTesta][colTesta + 1] == -1) {lunghezza++; mangiata = true;}
    }
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            if (schema[i][j] == lunghezza && !mangiata)
                schema[i][j] = 0;
            else{
                if (schema[i][j] > 0)
                    schema[i][j]++;
            }
        }
    }
    if (dir == 'n' )
        schema[--rigaTesta][colTesta] = 1;

    if (dir == 's' )
        schema[++rigaTesta][colTesta] = 1;

    if (dir == 'o' )
        schema[rigaTesta][--colTesta] = 1;

    if (dir == 'e' )
        schema[rigaTesta][++colTesta] = 1;

    direzione = dir;
    mangiata = false;

    return *this;
}

Snake& Snake::mela(int r, int c) {
    if (r < 0 || c < 0)
        return *this;
    if (r >= righe || c >= colonne)
        return *this;

    if (schema[r][c] == 0)
        schema[r][c] = -1;
    return *this;
}

Snake& Snake::inverti() {
    for (int k = 0; k < lunghezza ; ++k) {
        for (int i = 0; i < righe; ++i) {
            for (int j = 0; j < colonne; ++j) {
                if (schema[i][j] == k + 1)
                    schema[i][j] = lunghezza - k + 10;  //faccio +10 per non rischiare di avere due caselle con lo stesso numero nello stesso ciclo di scansione
            }
        }
    }
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            if (schema[i][j]>10)
                schema[i][j] -= 10;
        }
    }
    return *this;
}

Snake& operator--(Snake& s){
    if (s.lunghezza <= 4)
        return s;

    for (int i = 0; i < s.righe; ++i) {
        for (int j = 0; j < s.colonne; ++j) {
            if (s.schema[i][j] == s.lunghezza) {
                s.schema[i][j] = 0;
                s.lunghezza--;
            }
        }
    }
    return s;
}

Snake::~Snake(){
    for (int i = 0; i < righe; ++i)
        delete schema[i];

    delete schema;
}

