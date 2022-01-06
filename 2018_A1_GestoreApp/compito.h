#include <iostream>
#include <cstring>
using namespace std;

struct app{
    char nome[21];
    bool foreg;
    app* next;
};

class GestoreApp{
    app* head;
public:
    GestoreApp();
    ~GestoreApp();
    void operator+=(char*);
    friend ostream& operator<<(ostream&, GestoreApp&);
    void foreground(char*);
    void operator-=(char*);
    void chiudi_tutte();

};
