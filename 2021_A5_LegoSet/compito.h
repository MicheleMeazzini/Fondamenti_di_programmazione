#include <iostream>
#include <cstring>
using namespace std;

const int DESCLEN = 31;

struct matt{
    char desc[DESCLEN];
    char colore[6];
    matt* next;
};

struct mattCom{
    int code;
    char desc[DESCLEN];
    char colore[6];
    mattCom* next;
};
static mattCom* headCom;

class LegoSet{
    matt* head;

public:
    LegoSet();
    ~LegoSet();
    friend ostream& operator<<(ostream&, LegoSet&);
    void aggiungiMattoncino(char*, char);
    void eliminaMattoncino(char*);
    int operator%(char);
    void eliminaMattoncino(char);
    void aggiungiMattoncinoComune(int, char*, char);
    void aggiungiMattoncinoComune(int);
};