#include "compito.h"

Tragitto::Tragitto() {
    post *p = new post;  //alloco postazione 1
    strcpy(p->pers, vuoto);
    p->num = 1;

    post *q = new post;  //alloco postazione 2
    strcpy(q->pers, vuoto);
    q->num = 2;

    head = p;  //gestisco i collegamenti
    p->next = q;
    q->next = nullptr;

    totPost = 2;
}

ostream& operator<<(ostream& os, Tragitto& t){
    if (t.head == nullptr) return os;

    post *p;
    for (p = t.head; p!= nullptr; p=p->next)
        os << '[' << p->num << ']' << ' ' << p->pers << endl;

    return os;
}

void Tragitto::inserisci(char *s) {
    if (head == nullptr) return;
    if (strlen(s) > 19) return;

    post *p;
    for (p = head; p!= nullptr; p=p->next)  //se esiste una persona con nome s gia sul tragitto lascio tragitto invariato
        if (!strcmp(s, p->pers)) return;

    if (!strcmp(head->pers, vuoto))  //se nella prima postazione non c'è nessuno ci aggiungo s
        strcpy(head->pers, s);
}

void Tragitto::avanza(int j) {
    if (head == nullptr) return;
    if (j > totPost) return;

    post *p, *q;
    for(p = head; p!= nullptr; p=p->next) {
        q = p;
        if (q->num == j){
            p=p->next;
            break;
        }
    }
    if (strcmp(p->pers, vuoto) == 0){
        strcpy(p->pers, q->pers);
        strcpy(q->pers, vuoto);
    }
}

Tragitto& Tragitto::operator+=(int n) {
    if (n <= 0) return *this;

    post *p, *q;
    for (p = head; p!= nullptr; p=p->next) q = p;  //arrivo in fondo alla lista

    if (head == nullptr){
        post *l = new post;
        strcpy(l->pers, vuoto);
        l->num = 1;
        totPost = 1;
        l->next = nullptr;
        head = l;
        n--;
    }

    for (int i = 1; i <= n; ++i) {
        post *r = new post;
        strcpy(r->pers, vuoto);
        r->num = ++totPost;
        q->next = r;
        r->next = nullptr;
        q = r;
    }
}

Tragitto::Tragitto(Tragitto &t) {
    if (t.head == nullptr) return;
    post *p, *q;

    q = new post;   //alloco in testa il primo elemento
    strcpy(q->pers, t.head->pers);
    q->num = t.head->num;
    q->next = nullptr;
    head = q;

    for (p = t.head->next; p!= nullptr; p=p->next){
        post *r = new post;
        strcpy(r->pers, p->pers);
        r->num = p->num;
        r->next = nullptr;
        q->next = r;
        q = r;
    }
    totPost = t.totPost;
}

Tragitto::~Tragitto() {
    head = nullptr;
}