#include "compito.h"

//Michele Meazzini 635889

Memory::Memory(int N) {
    if (N <= 0) return;
    dim = N;
    punt = 0;

    schema = new char*[dim];
    for (int i = 0; i < dim; ++i) {
        schema[i] = new char[dim];
    }
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            schema[i][j] = '-';
        }
    }

    coppie_G = 0;
    coppie_C = 0;
    coppie_S = 0;
    coppie_P = 0;
    coppie_T = 0;
    playing = false;
}

Memory::~Memory() {
    for (int i = 0; i < dim; ++i) {
        delete[] schema[i];
    }
    delete[] schema;
}

Memory::Memory(const Memory& m1){
    dim = m1.dim;
    punt = 0;

    schema = new char*[dim];
    for (int i = 0; i < dim; ++i) {
        schema[i] = new char[dim];
    }
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            schema[i][j] = m1.schema[i][j];
        }
    }

    coppie_G = m1.coppie_G;
    coppie_C = m1.coppie_C;
    coppie_S = m1.coppie_S;
    coppie_P = m1.coppie_P;
    coppie_T = m1.coppie_T;
    playing = m1.playing;
}

ostream& operator<<(ostream& os, const Memory& m){
    for (int i = 0; i < m.dim; ++i) {
        for (int j = 0; j < m.dim; ++j) {
            os << m.schema[i][j] << ' ';
        }
        os << endl;
    }
    os << endl << "Punteggio: " << m.punt << endl;
    return os;
}

void Memory::inserisci(char tipo, int riga1, int colonna1, int riga2, int colonna2){
    if (riga1 >= dim || riga1 < 0) return;
    if (colonna1 >= dim || colonna1 < 0) return;
    if (riga2 >= dim || riga2 < 0) return;
    if (colonna2 >= dim || colonna2 < 0) return;

    if (tipo != 'G' && tipo != 'C' && tipo != 'S' && tipo != 'P' && tipo != 'T') return;
    if (riga1 == riga2 && colonna1 == colonna2) return;
    if (schema[riga1][colonna1] != '-') return;
    if (schema[riga2][colonna2] != '-') return;

    playing = true;
    schema[riga1][colonna1] = tipo;
    schema[riga2][colonna2] = tipo;

    switch (tipo) {
        case 'G':
            coppie_G++;
            break;
        case 'C':
            coppie_C++;
            break;
        case 'S':
            coppie_S++;
            break;
        case 'P':
            coppie_P++;
            break;
        case 'T':
            coppie_T++;
            break;
        default:
            break;
    }
}

void Memory::riassumi(){
    if (playing && coppie_G == 0 && coppie_C == 0 && coppie_S == 0 && coppie_P == 0 && coppie_T == 0) {
        cout << "VITTORIA!" << endl;
        playing = false;
        return;
    }

    int conta_G = 0, conta_C = 0, conta_S = 0, conta_P = 0, conta_T = 0;
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            switch (schema[i][j]) {
                case 'G':
                    conta_G++;
                    break;
                case 'C':
                    conta_C++;
                    break;
                case 'S':
                    conta_S++;
                    break;
                case 'P':
                    conta_P++;
                    break;
                case 'T':
                    conta_T++;
                    break;
                default:
                    break;
            }
        }
    }

    coppie_G = conta_G / 2;
    coppie_C = conta_C / 2;
    coppie_S = conta_S / 2;
    coppie_P = conta_P / 2;
    coppie_T = conta_T / 2;

    cout << "Gatto: " << coppie_G << endl;
    cout << "Cane: " << coppie_C << endl;
    cout << "Serpente: " << coppie_S << endl;
    cout << "Pavone: " << coppie_P << endl;
    cout << "Tigre: " << coppie_T << endl;
}

bool Memory::flip(int riga1, int colonna1, int riga2, int colonna2){
    if (riga1 == riga2 && colonna1 == colonna2) return false;

    if (riga1 >= dim || riga1 < 0) return false;
    if (colonna1 >= dim || colonna1 < 0) return false;
    if (riga2 >= dim || riga2 < 0) return false;
    if (colonna2 >= dim || colonna2 < 0) return false;

    if (schema[riga1][colonna1] == '-') return false;
    if (schema[riga2][colonna2] == '-') return false;

    char type1, type2;
    type1 = schema[riga1][colonna1];
    type2 = schema[riga2][colonna2];

    if (type1 == type2){
        switch (type1) {
            case 'G':
                coppie_G--;
                break;
            case 'C':
                coppie_C--;
                break;
            case 'S':
                coppie_S--;
                break;
            case 'P':
                coppie_P--;
                break;
            case 'T':
                coppie_T--;
                break;
            default:
                break;
        }
        schema[riga1][colonna1] = '-';
        schema[riga2][colonna2] = '-';
        punt++;
        return true;
    }
    if (type1 != type2){
        punt--;
    }
    return false;
}

Memory Memory::operator+(const Memory& m1){
    Memory mm(*this);

    int diff = dim - m1.dim;
    mm.punt = 0;

    if (diff >= 0) {
        for (int i = 0; i < dim - diff; ++i) {
            for (int j = diff; j < dim; ++j) {
                if (mm.schema[i][j] == '-' && mm.schema[i][j - diff] != '-')
                    mm.schema[i][j] = m1.schema[i][j - diff];
            }
        }
    }
    if (diff < 0){
        for (int i = 0; i < dim; ++i) {
            for (int j = 0; j < dim; ++j) {
                if (mm.schema[i][j] == '-' && mm.schema[i][j - diff] != '-')
                    mm.schema[i][j] = m1.schema[i][j - diff];
            }
        }
    }
    return mm;
}

Memory& Memory::operator>>(int i){
    if (i == 0 && i % 4 == 0) return *this;
    int rot = (i < 0) ? -i : i;

    Memory mm(*this);   //faccio una copia per non perdere le tessere sovrascritte

    if (rot % 4 == 1 && i > 0 || rot % 4 == 3 && i < 0){   //90 gradi senso orario
        for (int ii = 0; ii < dim; ++ii) {
            for (int j = 0; j < dim; ++j) {
                schema[j][dim - 1 - ii] = mm.schema[ii][j];
            }
        }
        return *this;
    }

    if (rot % 4 == 2 && i > 0 || rot % 4 == 2 && i < 0){    //180 gradi
        for (int ii = 0; ii < dim; ++ii) {
            for (int j = 0; j < dim; ++j) {
                schema[dim - 1 - ii][dim - 1 - j] = mm.schema[ii][j];
            }
        }
        return *this;
    }

    if (rot % 4 == 3 && i > 0 || rot % 4 == 1 && i < 0){    //90 gradi senso antiorario
        for (int ii = 0; ii < dim; ++ii) {
            for (int j = 0; j < dim; ++j) {
                schema[dim - 1 - j][ii] = mm.schema[ii][j];
            }
        }
        return *this;
    }
}



// fine file