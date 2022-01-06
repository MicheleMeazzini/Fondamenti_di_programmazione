#include "compito.h"

int main() {

    cout<<endl<<"--- PRIMA PARTE ---" << endl;

    Tartaglia t(9);
    cout<<t<<endl<<endl;

    cout<<"Test della funzione fibonacci:"<<endl;
    cout<< t.fibonacci(0)<<endl; // deve stampare 1
    cout<< t.fibonacci(1)<<endl; // deve stampare 1
    cout<< t.fibonacci(2)<<endl; // deve stampare 2
    cout<< t.fibonacci(5)<<endl; // deve stampare 8
    cout<< t.fibonacci(8)<<endl; // deve stampare 34
    cout << endl;

    cout<<endl<<"--- SECONDA PARTE ---" << endl;

    cout<<"Test della espandi (deve stampare {a^4 + 4a^3*b^1 + 6a^2*b^2 + 4a^1*b^3 + b^4})"<<endl;
    t.espandi(4);

    cout << endl<<endl;
    cout << "Creazione dell'oggetto t2 di ordine 13 e sua stampa" <<endl;
    Tartaglia t2(13);
    cout<<t2<<endl<<endl;

    cout << "Test dell'operatore di assegnamento" <<endl;
    t2 = t;
    cout<<t2<<endl;

}
