#include <iostream>
using namespace std;

enum tipo{GOLD, SILVER};

struct pren{
    int cliente;
    tipo tipo;  //0 gold 1 silver
    pren* next;
};

struct aPren{
    int id;
    int t;  //-1 prenotazione inesistente 0 gold 1 silver
};

class Ammessi{
public:
    int quanti;
    aPren elenco[5];

    Ammessi();
};

class Prenotazione{
    pren* testa;
    bool stato;     //1 prenotazione aperta, 0 prenotazione chiusa
public:
    Prenotazione();
    ~Prenotazione();
    void prenota(int,  tipo);
    void cancella(int, tipo);
    friend ostream& operator<<(ostream&, Prenotazione&);
    operator int();
    Ammessi chiudi();
};


