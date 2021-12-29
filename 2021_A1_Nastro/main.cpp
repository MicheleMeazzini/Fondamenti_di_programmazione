#include <iostream>
#include "compito.h"
using namespace std;

int main(){

    cout<<"--- PRIMA PARTE ---"<<endl;
    cout<<"Test del costruttore"<<endl;
    Nastro n;
    cout<<n<<endl;

    cout<<"Test della aggiungi"<<endl;
    n.aggiungi("B", 5);
    cout<<n<<endl;

    n.aggiungi("C", 8);
    cout<<n<<endl;

    n.aggiungi("A", 6);
    cout<<n<<endl;

    cout<<"Test della consuma"<<endl;
    n.consuma("A");
    cout<<n<<endl;

    Nastro n1;
    n1.aggiungi("AA", 6);
    n1.aggiungi("D", 7);
    n1.aggiungi("C", 7); // piatto con lo stesso prezzo ma nome precedente a "D"
    n1.aggiungi("E", 7); // piatto con lo stesso prezzo ma nome successivo a "D"
    n1.aggiungi("B", 5);
    n1.aggiungi("B", 8); // piatto con stesso nome di "B" ma prezzo diverso
    n1.aggiungi("B", 5); // piatto identico a "B"
    cout<<n1<<endl;

    cout<<endl<<"--- SECONDA PARTE ---"<<endl;
    cout<<"Test dell'operatore +="<<endl;
    n += n1;
    cout<<n<<endl;

    cout<<"Test dell'operatore |"<<endl;
    cout<<( n | n1 )<<endl;

    {
        cout<<"Test del distruttore"<<endl;
        Nastro n2;
        n2.aggiungi("AA", 6);
        n2.aggiungi("D", 7);
        n2.aggiungi("B", 5);
        n2.aggiungi("C", 7);
        cout << n2 << endl;
    }
    cout<<"(l'oggetto n2 e' appena stato distrutto)"<<endl;

return 0;
}