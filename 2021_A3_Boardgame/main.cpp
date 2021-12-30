#include <iostream>
#include "compito.h"

int main() {
    cout << "--- PRIMA PARTE ---" << endl;
    cout << "Test del costruttore" << endl;
    Boardgame b;
    cout << b << endl;
    cout << "Test della muovi" << endl;
    b.muovi('D', 3, 'B', 3);
    cout << b << endl;
    cout << "Test della attacca" << endl;
    b.attacca('D', 3, 'E', 2);
    cout << b << endl;
    cout << "---SECONDA PARTE---" << endl;
    cout << "Test operatore <<" << endl;
    cout << (b << 1) << endl;
    cout << "Test della compatta" << endl;
    cout << !b << endl;
    cout << "Test operatore ~" << endl;
    b.muovi('B', 3, 'A', 3);
    b.muovi('B', 1, 'A', 1);
    cout << b << endl;
    cout << (~b) << endl;
}

