#include <iostream>
#include <cstring>
using namespace std;

class Boardgame{
    char schema[7][8]; //8 colonne perchè considero anche le due colonne composte da '|' (colonna 0 e 7)

public:
    Boardgame();
    Boardgame(Boardgame&);
    friend ostream& operator<<(ostream& os, const Boardgame&);
    void muovi(char, int, char, int);
    void attacca(char, int, char, int);
    Boardgame operator<<(const int);
    Boardgame compatta(Boardgame&);
    Boardgame operator!();
    friend int operator~(const Boardgame&);
};