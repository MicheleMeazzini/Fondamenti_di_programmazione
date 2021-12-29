#include <iostream>
#include <cstring>
using namespace std;

struct piatto{
    char nome[25];
    int prezzo;
    piatto* next;
};
class Nastro{
    int conto;
    piatto* head;

public:
    Nastro();
    ~Nastro();
    void aggiungi(char*, int);
    friend ostream& operator<<(ostream&, const Nastro&);
    Nastro& consuma(char*);
    Nastro& operator+=(Nastro&);
    Nastro operator|(const Nastro&);
};