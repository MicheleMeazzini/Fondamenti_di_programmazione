#include <iostream>
#include <cstring>
using namespace std;

const int MAXLEN = 10;

struct mess{
    char testo[MAXLEN];
    mess* next;
};

class Monitor{
    int maxMessaggi;
    int numMessaggi;
    mess* testa;

public:
    Monitor(int);
    void inserisci(char[]);
    friend ostream& operator<<(ostream&, const Monitor&);
    Monitor(const Monitor&);
    friend Monitor operator+(const Monitor&, const Monitor&);
    ~Monitor();
};