#include <iostream>
using namespace std;

// Versione ottimizzata per risparmiare memoria

class Palazzo
{
    bool** v; // false=finestra chiusa, true=finestra aperta
    int maxPiani;
    int quantiPiani;
    
  public:
    Palazzo(int N);
    Palazzo(const Palazzo& p);
    bool aggiungi();
    void stampa(); // OPPURE: void stampa()const;
    
    // --- SECONDA PARTE --- //
    void cambia(int i, int j);
    Palazzo& operator%=(const Palazzo& p);
    int operator!(); // OPPURE: int operator!()const;
    ~Palazzo();
};

