#include "compito.h"

Monitor::Monitor(int N) {
    if (N <= 0)
        maxMessaggi = 3;
    maxMessaggi = N;
    numMessaggi = 0;
    testa = nullptr;
}

Monitor::Monitor(const Monitor& m) {
    maxMessaggi = m.maxMessaggi;
    numMessaggi = m.numMessaggi;
    testa = nullptr;
    if (m.testa == nullptr)
        return;

    mess *p = new mess;
    strcpy(p->testo, m.testa->testo);
    p->next = nullptr;
    testa = p;
    for (mess *q = m.testa->next; q!= nullptr; q=q->next) {
        mess *r = new mess;
        strcpy(r->testo, q->testo);
        p->next = r;
        p = r;
    }
    p->next = nullptr;
}

Monitor::~Monitor(){
    mess *p, *q;
    if (testa == nullptr)
        return;
    for (p = testa; p!= nullptr; p=p->next){
        q = p;
        delete q;
    }
    testa = nullptr;
}

void Monitor::inserisci(char msg[]){
    if(msg == nullptr)
        return;

    if (numMessaggi == maxMessaggi){    //se il monitor è saturo di messaggi, prima cancello il mess più vecchio
        mess *p, *q;
        if (testa == nullptr)
            return;
        for (p = testa; p->next != nullptr; p = p->next)
            q = p;
        if (p == testa) {
            testa = nullptr;
            return;
        }
        q->next = nullptr;
        delete p;
        numMessaggi--;
    }
    if (numMessaggi < maxMessaggi) {    //a questo punto il monitor non è sicuramente pieno di messaggi
        mess *newmsg = new mess;
        strncpy(newmsg->testo, msg, MAXLEN);
        newmsg->next = testa;
        testa = newmsg;
        numMessaggi++;
    }
}

ostream& operator<<(ostream& os, const Monitor& m) {
    os << '[' << m.maxMessaggi << ']' << endl;
    for (mess* p = m.testa; p!= nullptr; p=p->next)
        os << p->testo << endl;
    return os;
}

Monitor operator+(const Monitor& m1, const Monitor& m2){

    Monitor m3(m1.maxMessaggi + m2.maxMessaggi);
    m3.numMessaggi = m1.numMessaggi + m2.numMessaggi;

    mess *p = new mess;  //creo l'elemento di testa del nuovo monitor
    strcpy(p->testo, m2.testa->testo);
    p->next = nullptr;
    m3.testa = p;
    for (mess *q = m2.testa->next; q!= nullptr; q=q->next) {  //inserisco in coda tutti gli elementi di m2
        mess *r = new mess;
        strcpy(r->testo, q->testo);
        p->next = r;
        p = r;
    }
    p->next = nullptr;
    for (mess *q = m1.testa; q!= nullptr; q=q->next) {   //inserisco in coda tutti gli elementi di m1
        mess *r = new mess;
        strcpy(r->testo, q->testo);
        p->next = r;
        p = r;
    }
    p->next = nullptr;

    return m3;
}

