#include "compito.h"

MediaPlaylist::MediaPlaylist() {
    head = nullptr;
}

MediaPlaylist::MediaPlaylist(item vett[], int n) {
    if (n <= 0) return;

    head = nullptr;
    file *r = new file; //alloco primo elemento
    strncpy(r->title, vett[0].nome, TITLEN);
    r->title[strlen(vett[0].nome)] = '\0';
    r->type = vett[0].tipo;
    r->num = 1;
    r->next = nullptr;
    head = r;

    file *p, *q;
    for (int i = 1; i < n; ++i) {
        for (p = head; p!= nullptr; p=p->next)
            q=p;
        file *o = new file;
        strncpy(o->title, vett[i].nome, TITLEN);
        o->title[strlen(vett[i].nome)] = '\0';
        o->type = vett[i].tipo;
        o->num = i+1;
        o->next = p;
        q->next = o;
        q = o;
    }
}

MediaPlaylist::MediaPlaylist(MediaPlaylist& mp){
    if (mp.head == nullptr)
        head = nullptr;

    file *r = new file; //alloco primo elemento
    strncpy(r->title, mp.head->title, TITLEN);
    r->title[strlen(mp.head->title)] = '\0';
    r->type = mp.head->type;
    r->num = 1;
    r->next = nullptr;
    head = r;

    file *i, *p, *q;
    for (i = mp.head->next; i!= nullptr; i=i->next) {
        for (p = head; p!= nullptr; p=p->next)
            q=p;
        file *o = new file;
        strncpy(o->title, i->title, TITLEN);
        o->title[strlen(i->title)] = '\0';
        o->type = i->type;
        o->num = i->num;
        o->next = p;
        q->next = o;
        q = o;
    }
}

MediaPlaylist::~MediaPlaylist() {
    head = nullptr;
}

item::item(Tipo t, const char *n) {
    tipo = t;
    strncpy(nome, n, TITLEN);
    nome[strlen(n)] = '\0';
}

void MediaPlaylist::inserisci(char *titolo, Tipo tipo) {
    if (tipo != AUDIO && tipo != VIDEO) return; //puo essere rimosso perchè se tipo non è ne AUDIO ne VIDEO non compila
    for (file *q = head; q!= nullptr; q=q->next)
        if (strcmp(q->title, titolo) == 0 && q->type == tipo) return;

    file *r = new file;

    strncpy(r->title, titolo, 20);
    r->title[strlen(titolo)] = '\0';
    r->type = tipo;
    r->num = 0;

    if (head == nullptr)
        r->next = nullptr;
    else
        r->next = head;

    head = r;
    for (file *p = head; p!= nullptr; p=p->next)
        p->num++;
}

void MediaPlaylist::elimina(char *titolo, Tipo tipo) {
    if (head == nullptr) return;

    if (strcmp(head->title, titolo) == 0 && head->type == tipo) {
        head = head->next;
        for (file *l = head; l!= nullptr; l=l->next)
            l->num--;
        return;
    }
    file *p, *q;
    for(p = head; p!= nullptr; p=p->next){
        if (strcmp(p->title, titolo) == 0 && p->type == tipo) {
            q->next = p->next;
            delete p;
            for (q=q->next; q!= nullptr; q=q->next)
                q->num--;
            return;
        }
        q = p;
    }
}

ostream& operator<<(ostream& os, MediaPlaylist& mp){
    if (mp.head == nullptr) {
        os << "[-]" << endl;
        return os;
    }
    char tipoTemp[6];
    file *p;
    for (p = mp.head; p!= nullptr; p=p->next){
        if (p->type == AUDIO)
            strcpy(tipoTemp, "Audio");
        if (p->type == VIDEO)
            strcpy(tipoTemp, "Video");
        os << '[' << p->num << ']' << '<' << p->title << ',' << ' ' << tipoTemp << '>' << endl;
    }
    return os;
}

bool MediaPlaylist::riproduci(char *titolo, Tipo &tipo) {
    file *p;
    for (p = head; p!= nullptr ; p=p->next) {
        if (strcmp(p->title, titolo) == 0) {
            tipo = p->type;
            return true;
        }
    }
    return false;
}