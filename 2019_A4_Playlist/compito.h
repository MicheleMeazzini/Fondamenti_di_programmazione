#include <iostream>
#include <cstring>
using namespace std;

struct song{
    char *titolo;
    char *artista;
    char *album;
    int durata;
    int trascorso;
    bool playing;
    song* next;
};

class SongPlaylist{
    song* head;

public:
    SongPlaylist();
    SongPlaylist(SongPlaylist&);
    ~SongPlaylist();
    void aggiungi(const char*,const char*,const char*,const int);
    friend ostream& operator<<(ostream&, SongPlaylist&);
    void play(int);
    void elimina(const char*,const char*,const char*);
    SongPlaylist operator+=(SongPlaylist&);
    operator int();
};

