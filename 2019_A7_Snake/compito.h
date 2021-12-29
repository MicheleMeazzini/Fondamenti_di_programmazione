#include <iostream>
using namespace std;

class Snake{
    int **schema;
    int righe;
    int colonne;
    int lunghezza;
    char direzione;
    int rigaTesta;
    int colTesta;

public:
    Snake(int, int);
    ~Snake();
    friend ostream& operator<<(ostream&, Snake&);
    Snake& muovi(char);
    Snake& mela(int, int);
    Snake& inverti();
    friend Snake& operator--(Snake&);
};