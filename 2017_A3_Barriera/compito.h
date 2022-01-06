#include <iostream>
#include <cstring>
using namespace std;

struct veicolo{
    char targa[7];
    veicolo* next;
};

struct casello{
    bool stato; //1 aperto, 0 chiuso
    int numVeicoli; //numero veicoli in coda
    veicolo* head;
};

class Barriera{
    casello barr[5];
public:
    Barriera();
    ~Barriera();
    Barriera nuovoVeicolo(char*);
    bool serviVeicolo(int i);
    friend ostream& operator<<(ostream&, Barriera&);
    int apriOppureChiudi(double);
    operator int();
};
