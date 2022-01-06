#include <iostream>
using namespace std;

class Flotta{
    int *flotta;
    int maxfile;
    bool fila_aggiunta;
public:
    Flotta(int);
    ~Flotta();
    Flotta(const Flotta&);
    void forma_fila(int, int);
    operator int()const ;
    friend ostream& operator<<(ostream&, const Flotta&);
    Flotta operator+(const Flotta&);
    Flotta operator-=(const Flotta&);
    Flotta operator+=(const int[]);
};


