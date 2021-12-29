#include "compito.h"

SongPlaylist::SongPlaylist(){
    head = nullptr;
}
SongPlaylist::SongPlaylist(SongPlaylist& ps){
    song *p = ps.head, *q, *r;

    q = new song;   //creo l'elemento di testa
    q->titolo = new char[50];
    strncpy(q->titolo, p->titolo, 50);
    q->album = new char[50];
    strncpy(q->album, p->album, 50);
    q->artista = new char[50];
    strncpy(q->artista, p->artista, 50);
    q->durata = p->durata;
    q->trascorso = p->trascorso;
    q->playing = p->playing;
    q->next = nullptr;
    head = q;

    for (p = ps.head->next; p!=nullptr; p=p->next) {    //inserisco in coda i successivi
        r = new song;
        r->titolo = new char[50];
        strncpy(r->titolo, p->titolo, 50);
        r->album = new char[50];
        strncpy(r->album, p->album, 50);
        r->artista = new char[50];
        strncpy(r->artista, p->artista, 50);
        r->durata = p->durata;
        r->trascorso = p->trascorso;
        r->playing = p->playing;
        r->next = nullptr;
        q->next = r;
        q = r;
    }
}

SongPlaylist::~SongPlaylist() {
    head = nullptr;
}

void SongPlaylist::aggiungi(const char* titolo,const char* album,const char* artista,const int sec){
    song *p = head;
    song *q;

    for (; p!= nullptr; p=p->next) {    //scorro la lista fino ad arrivare in fondo
        q=p;
    }
    song* r = new song;     //alloco una nuova canzone
    r->titolo = new char[50];   //altrimenti potevo definire la dimensione dei char* nel compito.h ed evitare di
                                //allocare manualmente un new char di 50 caratteri
    strncpy(r->titolo, titolo, 50);
    r->album = new char[50];
    strncpy(r->album, album, 50);
    r->artista = new char[50];
    strncpy(r->artista, artista, 50);
    if (sec < 0)
        r->durata = 0;
    r->durata = sec;
    r->trascorso = 0;
    r->playing = false;

    if (p == head) {    //inserimento in lista vuota
        r->next = nullptr;
        head = r;
        r->playing = true;
    }else{      //inserimento in coda
        q->next = r;
        r->next = nullptr;
    }
}

ostream& operator<<(ostream& os, SongPlaylist& sp){
    song *p;
    if (sp.head == nullptr)  //in caso di lista vuota
        return os;
    for (p = sp.head; p!= nullptr; p=p->next) {
        if (p->playing)
            os << '>' << '[' << p->trascorso/60 << ':' << p->trascorso%60 << ']';
        os << p->titolo << '-' << p->album << '-' << p->artista << '-' << p->durata;
        os << endl;
    }
    return os;
}

void SongPlaylist::play(int n) {
    if (n < 0)
        return;
    if (head == nullptr)
        return;

    song *p;
    int diff = n;

    for (p = head; p!= nullptr; p=p->next){
        if (p->playing){
            while (p->trascorso + diff >= p->durata) {
                diff = (p->trascorso + diff) - p->durata;
                p->playing = false;
                p->trascorso = 0;
                if (p->next == nullptr)
                    p = head;
                else
                    p = p->next;
            }
            p->playing = true;
            p->trascorso += diff;
        }
    }
}

void SongPlaylist::elimina(const char* titolo,const char* album,const char* artista){
    song *p, *q;
    for (p = head; p!= nullptr; p=p->next){
        if (!strcmp(p->titolo, titolo) && !strcmp(p->album, album) && !strcmp(p->artista, artista)) {
            if (p == head){     //estrazione in testa
                head = p->next;
                delete p;
                return;
            }else{      //estrazione in mezzo o coda;
                q->next = p->next;
                delete p;
                return;
            }
        }
        q = p;
    }
}

SongPlaylist SongPlaylist::operator+=(SongPlaylist& sp2) {
    SongPlaylist spAux(sp2);
    song *p, *q, *r;

    for (p = head; p!= nullptr; p=p->next)    //vado alla fine della sp
        q = p;
    for (r = spAux.head; r!= nullptr; r=r->next) {
        r->trascorso = 0;
        r->playing = false;
    }
    q->next = spAux.head;   //ci attacco la testa di sp2

    return *this;
}

SongPlaylist::operator int() {
    song *p;
    int time = 0;
    for (p = head; p!=nullptr; p=p->next) {
        if (!p->playing)
            time += p->durata;
        if (p->playing) {
            time += p->trascorso;
            return time;
        }
    }
}



