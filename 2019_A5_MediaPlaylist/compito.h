#include <iostream>
#include <cstring>
using namespace std;

const int TITLEN = 20;
enum Tipo {AUDIO, VIDEO};

struct file{
    char title[TITLEN+1];
    Tipo type;
    int num;
    file* next;
};

struct item{
    Tipo tipo;
    char nome[TITLEN +1];
public:
    item(Tipo, const char*);
};

class MediaPlaylist{
    file* head;

public:
    MediaPlaylist();
    MediaPlaylist(item[], int );
    MediaPlaylist(MediaPlaylist&);
    ~MediaPlaylist();
    friend ostream& operator<<(ostream&, MediaPlaylist&);
    void inserisci(char*, Tipo);
    void elimina(char*, Tipo);
    bool riproduci(char*, Tipo&);
};