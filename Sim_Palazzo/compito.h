#include <iostream>
using namespace std;

enum stato {Aperta, Chiusa};

class Palazzo
{
    stato** v;      //vettore di vettori
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

