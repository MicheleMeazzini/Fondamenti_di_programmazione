#include <iostream>
#include <cstring>
using namespace std;

struct task{
    char desc[41];
    int priority;
    bool done;
    task* next;
};
class ToDoList{
    task* head;
public:
    ToDoList();
    ~ToDoList();
    void aggiungi(char*, int);
    friend ostream& operator<<(ostream&, ToDoList&);
    void operator+=(const ToDoList&);
    void fai(char*);
    void cancella_fatti();
};
