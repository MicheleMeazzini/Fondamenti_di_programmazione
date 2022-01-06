#include "compito.h"

ToDoList::ToDoList() {
    head = nullptr;
}

ToDoList::~ToDoList(){
    head = nullptr;
}

void ToDoList::aggiungi(char* desc, int prio){
    if (prio < 1) return;
    if (strlen(desc) > 40) return;

    task *r = new task;
    r->priority = prio;
    strcpy(r->desc, desc);
    r->done = false;

    if (head == nullptr){
        r->next = nullptr;
        head = r;
    } else {
        task *p, *q;
        for (p = head; p != nullptr && p->priority <= prio; p = p->next)
            q = p;
        if (p == head){
            r->next = p;
            head = r;
        } else {
            q->next = r;
            r->next = p;
        }
    }
}

ostream& operator<<(ostream& os, ToDoList& tdl){
    task *p;
    for (p = tdl.head; p!= nullptr ; p=p->next) {
        (p->done) ? os << 'V' : os << ' '; os << ' ';
        os << p->priority << ' ' << '-' << ' ';
        os << p->desc << endl;
    }
    return os;
}

void ToDoList::operator+=(const ToDoList& tdl){
    task *p;
    for (p = tdl.head; p != nullptr; p = p->next){
        aggiungi(p->desc, p->priority);
    }
}

void ToDoList::fai(char *desc){
    if (strlen(desc) > 40) return;

    task *p;
    for (p = head; p != nullptr; p = p->next){
        if (strcmp(p->desc, desc) == 0 && !p->done){
            p->done = true;
            return;
        }
    }
}

void ToDoList::cancella_fatti() {
    task *p, *q;
    for (p = head; p != nullptr; p = p->next){
        if (p->done && p == head)
            head = head->next;
        else if (p->done)
            q->next = p->next;

        q = p;
    }
}

