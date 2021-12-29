#include <iostream>
#include "compito.h"

using namespace std;

int main()
{
    cout << "---PRIMA PARTE---" << endl;
    cout << "Test costruttore e operatore uscita:" << endl;
    Prenotazione p;
    cout << p << endl;

    cout << "Test funzione prenota:" << endl;
    for (int i = 1; i <= 6; i++)
        p.prenota(i, GOLD);
    for (int i = 7; i <= 13; i++)
        p.prenota(i, SILVER);
    cout << p << endl;

    cout << "Test funzione cancella:" << endl;
    p.cancella(2, GOLD);
    p.cancella(3, GOLD);
    p.cancella(4, GOLD);
    p.cancella(5, GOLD);
    p.cancella(13, GOLD);
    p.cancella(7, SILVER);
    p.cancella(5, SILVER);
    cout << p << endl;

    cout << "---SECONDA PARTE---" << endl;
    cout << "Test operatore int():" << endl;
    cout << "Silver partecipanti: " << int(p) << endl;

    cout << "Test funzione chiudi:" << endl;
    Ammessi a = p.chiudi();
    cout << "AMMESSI" << endl;
    for (int i = 0; i < a.quanti; i++)
        cout << a.elenco[i].id << '\t' << a.elenco[i].t << endl;

    cout << endl << "Test prenota e cancella a prenotazione chiusa:" << endl;
    p.prenota(20, GOLD);
    p.cancella(11, SILVER);
    cout << p << endl;

    cout << "Test distruttore:" << endl;
    {
        Prenotazione p2;
        p2.prenota(10, GOLD);
        p2.prenota(20, SILVER);
    }
    cout << "(distruttore chiamato)" << endl;

    return 0;
}
