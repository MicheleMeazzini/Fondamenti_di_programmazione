#include "compito.h"

Boardgame::Boardgame() {
    for (int i = 1; i < 7; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (j==0 || j==7)
                schema[i][j] = '|';
            else
                schema[i][j] = ' ';
        }
    }
    schema[6][1] = 'X';
    schema[6][3] = 'X';
    schema[6][5] = 'X';
    schema[5][2] = 'X';
    schema[5][4] = 'X';
    schema[5][6] = 'X';
    schema[2][1] = 'O';
    schema[2][3] = 'O';
    schema[2][5] = 'O';
    schema[1][2] = 'O';
    schema[1][4] = 'O';
    schema[1][6] = 'O';
}

Boardgame::Boardgame(Boardgame& b) {
    for (int i = 1; i < 7; ++i) {
        for (int j = 0; j < 8; ++j) {
            schema[i][j] = b.schema[i][j];
        }
    }
}

ostream& operator<<(ostream& os, const Boardgame& b){
    os << "  ";
    for (int i = 1; i < 7; ++i)
        os << i << ' ';

    os << endl;
    for (int i = 6, k = 0; i > 0; --i, k++) {
        os << char('F' - k);
        for (int j = 0; j < 8; ++j) {
            os << b.schema[i][j];
            if (j != 0 && j != 6)
                os << ' ';
        }
        os << endl;
    }
    return os;
}

void Boardgame::muovi(char id, int jd, char is, int js){
    if (schema[is-64][js] == ' ') return;  //nella casella sorgente non ci sono soldati
    if (schema[id-64][jd] != ' ') return;  //la casella destinazione è occupata
    if (id == is && jd == js) return; // spostamento nullo
    if(id < 64 || id > 70 || is < 64 || is > 70 || jd < 1 || jd > 7 || js < 0 || js > 7) return;

    bool movCons = false;  //movimento consentito
    //spostamenti orizz e vert di 2 caselle non devono attraversare caselle occupate
    if (id == is && jd - js == 2 && schema[id][(jd-js)/2] == ' ') movCons = true; //mov dx 2 caselle
    if (id == is && jd - js == -2 && schema[id][(jd-js)/2] == ' ') movCons = true; //mov sx 2 caselle
    if (jd == js && id - is == 2 && schema[(id-is)/2][jd] == ' ') movCons = true; //mov su 2 caselle
    if (jd == js && id - is == -2 && schema[(id-is)/2][jd] == ' ') movCons = true; //mov giu 2 caselle
    //spostamenti orizz o vert di 1 casella sono consentiti
    if (id == is && (jd - js == 1 || jd - js == -1)) movCons = true; //mov dx o sx 1 casella
    if (jd == js && (id - is == 1 || id - is == -1)) movCons = true; //mov su o giu 1 casella
    //spostamento diag dev essere di sola una casella
    if ((id - is == 1 || id - is == -1) && (jd - js == 1 || jd - js == -1))
        movCons = true;

    if (!movCons) return;

    if (schema[is-64][js] == 'X')  //spostamento
        schema[id-64][jd] = 'X';
    if (schema[is-64][js] == 'O')
        schema[id-64][jd] = 'O';
    schema[is-64][js] = ' ';
}

void Boardgame::attacca(char id, int jd, char is, int js){
    if (schema[is-64][js] == ' ') return;  //casella sorgente vuota
    if (schema[id-64][jd] == ' ') return;  //casella bersaglio vuota
    if (schema[is-64][js] == schema[id-64][jd]) return;  //soldato attacca membro del suo stesso esercito
    if(id < 64 || id > 70 || is < 64 || is > 70 || jd < 1 || jd > 7 || js < 0 || js > 7) return;

    bool attCons = false;   //attacco consentito
    if (id == is && (jd - js == 1 || jd - js == -1)) attCons = true;
    if (jd == js && (id - is == 1 || id - is == -1)) attCons = true;
    if ((id - is == 1 || id - is == -1) && (jd - js == 1 || jd - js == -1)) attCons = true;

    if (!attCons) return;

    schema[id-64][jd] = schema[is-64][js];
    schema[is-64][js] = ' ';
}

Boardgame Boardgame::operator<<(int n){
    if (n < 0) return *this;

    Boardgame ret(*this);
    for (int j = 6; j > n ; j--) {
        for (int i = 1; i < 7; ++i) {
           schema[i][j-n] =  ret.schema[i][j];
        }
    }
    for (int j = n; j > 0; j--) {
        for (int i = 1; i < 7; ++i) {
            schema[i][j+6-n] = ret.schema[i][j];
        }
    }
    return *this;
}
Boardgame Boardgame::operator!(){
    compatta(*this);
    return *this;
}

Boardgame Boardgame::compatta(Boardgame &b) {
    int rigaVuota = 0;
    for (int i = 1; i < 7; ++i) {
        for (int j = 1; j < 7; ++j) {
            if (schema[i][j] == ' ')
                rigaVuota = i;
            if (schema[i][j] != ' ') {
                rigaVuota = 0;
                j = 7;
            }
        }
        if (rigaVuota > 0 && rigaVuota < 6){
            for (int k = rigaVuota + 1, l = 0; k < 7; ++k, ++l) {
                for (int j = 1; j < 7; ++j)
                    schema[rigaVuota+l][j] = schema[k][j];
            }
            for (int p = 1; p < 7; ++p)
                schema[6][p] = ' ';
        }
    }
    int colVuota = 0;
    for (int j = 1; j < 7; ++j) {
        for (int i = 1; i < 7; ++i) {
            if (schema[i][j] == ' ')
                colVuota = j;
            if (schema[i][j] != ' ') {
                colVuota = 0;
                i = 7;
            }
        }
        if (colVuota > 0 && colVuota < 6){
            for (int k = colVuota-1, l = colVuota; k > 0; --k, --l) {
                for (int i = 1; i < 7; ++i)
                    schema[i][l] = schema[k][l];
            }
            for (int o = 0; o < 7; ++o)
                schema[o][6] = ' ';
        }
    }
    return *this;
}

int operator~(const Boardgame &b){
    int presBianco = 0; //pressione esercitata dal bianco
    int presNero = 0;

    for (int i = 1; i < 7; ++i) {
        for (int j = 1; j < 7; ++j) {
            if (b.schema[i][j] == 'X'){
                int minacce = 0;
                if (b.schema[i+1][j] == 'O') minacce++;
                if (b.schema[i-1][j] == 'O') minacce++;
                if (b.schema[i][j+1] == 'O') minacce++;
                if (b.schema[i][j-1] == 'O') minacce++;
                if (b.schema[i+1][j+1] == 'O') minacce++;
                if (b.schema[i+1][j-1] == 'O') minacce++;
                if (b.schema[i-1][j+1] == 'O') minacce++;
                if (b.schema[i-1][j-1] == 'O') minacce++;
                if (minacce >= 2) presBianco++;
            }
        }
    }
    for (int i = 1; i < 7; ++i) {
        for (int j = 1; j < 7; ++j) {
            if (b.schema[i][j] == 'O'){
                int minacce = 0;
                if (b.schema[i+1][j] == 'X') minacce++;
                if (b.schema[i-1][j] == 'X') minacce++;
                if (b.schema[i][j+1] == 'X') minacce++;
                if (b.schema[i][j-1] == 'X') minacce++;
                if (b.schema[i+1][j+1] == 'X') minacce++;
                if (b.schema[i+1][j-1] == 'X') minacce++;
                if (b.schema[i-1][j+1] == 'X') minacce++;
                if (b.schema[i-1][j-1] == 'X') minacce++;
                if (minacce >= 2) presBianco++;
            }
        }
    }
    return (presBianco - presNero);
}