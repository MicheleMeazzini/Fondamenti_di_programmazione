#include <iostream>
using namespace std;

struct elem{
    int valore;
    int indice;
    elem* next;
};

class VettoreSparso{
    int dimensione;
    elem* testa;

public:
    VettoreSparso(int);
    void set(int, int);
    friend ostream& operator<<(ostream&, const VettoreSparso&);
    void visualizzaComeDenso();
    void reset(int);
    VettoreSparso& operator*=(int k);
    void distruggi();
    ~VettoreSparso(){distruggi();}
};