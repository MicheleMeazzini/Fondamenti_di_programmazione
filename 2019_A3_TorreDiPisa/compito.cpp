#include "compito.h"

TorreDiPisa::TorreDiPisa(int N) {
    if (N < 1)
        maxLoggiati = 1;
    maxLoggiati = N;
    numLoggiati = 0;
    pendenze = new int[maxLoggiati];
}

TorreDiPisa::TorreDiPisa(TorreDiPisa &t) {
    maxLoggiati = t.maxLoggiati;
    numLoggiati = t.numLoggiati;
    pendenze = new int[maxLoggiati];

    for (int i = 0; i < numLoggiati; ++i) {
        pendenze[i] = t.pendenze[i];
    }
}

ostream& operator<<(ostream& os, const TorreDiPisa& t){
    if (t.numLoggiati > 0) {
        for (int i = 0; i < t.pendenze[t.numLoggiati - 1]; ++i)
            os << ' ';
    }
    os << "========" << endl;
    for (int i = t.numLoggiati-1; i >= 0; i--) {
        for (int j = 0; j < t.pendenze[i]; ++j) {
            os << ' ';
        }
        os << "||||||||" << endl;
    }
    os << "========" << endl;
}

TorreDiPisa& TorreDiPisa::operator+=(int p){
    if (numLoggiati == maxLoggiati)
        return *this;
    if (numLoggiati == 0 && p > 4)    //nuovo loggiato avrebbe pendenza maggiore di 4 rispetto alla base
        return *this;
    if (numLoggiati > 0){
        if (p - pendenze[numLoggiati-1] > 4)  //nuovo loggiato avrebbe pendenza > 4 rispetto a quello sottostante
            return *this;
        if (p - pendenze[numLoggiati-1] < 0)  //nuovo loggiato sarebbe spostato a sinistra rispetto al sottostante
            return *this;
    }
    pendenze[numLoggiati] = p;
    numLoggiati++;
}

TorreDiPisa::operator int()const {
    int somma = 0;
    for (int i = 0; i < numLoggiati; ++i) {
        somma = somma + pendenze[i];
    }
    return (somma/numLoggiati);
}

TorreDiPisa TorreDiPisa::operator++(int n){
    if (numLoggiati == 0)
        return *this;

    if (pendenze[0] == 4)
        return *this;
    for (int i = 1; i < numLoggiati; ++i) {
        if (pendenze[i] - pendenze[i-1] == 4)
            return *this;
    }

    TorreDiPisa ret(*this);

    for (int i = 0; i < numLoggiati; ++i) {
        pendenze[i] += (i+1);
    }
    return ret;
}

TorreDiPisa TorreDiPisa::stabilizza() {
    int aux = 0;    //indica quante volte è stato stabilizzato un loggiato
    if (pendenze[0] == 4) {
        pendenze[0]--;
        aux++;
    }
    for (int i = 1; i < numLoggiati; ++i) {
        if (pendenze[i] - pendenze[i-1] >= 4)
            aux++;
        pendenze[i] -= aux;
    }
    return *this;
}

TorreDiPisa::~TorreDiPisa() {
    for (int i = 0; i < numLoggiati; ++i)  // inutile
        pendenze[i] = 0;


    delete[] pendenze;  //bastava questo
}
