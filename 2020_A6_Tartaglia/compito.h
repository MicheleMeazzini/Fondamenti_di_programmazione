#include <iostream>
using namespace std;

class Tartaglia{
    int **schema;
    int ordine;

public:
    Tartaglia(int);
    ~Tartaglia();
    friend ostream& operator<<(ostream&, Tartaglia&);
    int fibonacci(int);
    void espandi(int);
    Tartaglia& operator=(const Tartaglia&);
};
