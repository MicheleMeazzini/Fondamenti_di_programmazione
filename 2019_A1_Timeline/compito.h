#include <iostream>
#include <cstring>
using namespace std;

struct elem{
    char *nome;
    int evidenza;
    elem* next;
};

class Timeline{
    elem* headpost;

public:
    Timeline();
    void pubblica(const char* ,const int);
    void cancella(const char*);
    friend ostream& operator<<(ostream&, const Timeline&);
    bool operator!();
    void mettiInEvidenza(const char*);
    ~Timeline();
};