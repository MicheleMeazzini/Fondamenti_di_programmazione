#include <iostream>
#include <cstring>
using namespace std;

struct post{
    char pers[20];
    int num;
    post* next;
};

class Tragitto{
    post* head;
    char* vuoto = "/////";
    int totPost;

public:
    Tragitto();
    Tragitto(Tragitto&);
    ~Tragitto();
    friend ostream& operator<<(ostream&, Tragitto&);
    void inserisci(char*);
    void avanza(int);
    Tragitto& operator+=(int);
};
