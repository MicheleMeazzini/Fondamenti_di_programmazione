#include <iostream>
using namespace std;

int main (){
    int n, g, i;
    cout<< "inserire numero naturale dispari:";
    cin>>n;
    g=n;

    cout << "Triangolo isoscele" << endl;

    for (int l = 0; l < (n / 2) + 1; ++l) {
        for (int p = 0; p < l; ++p) {
            cout << "   ";
        }
        for (int j = 0; j < g; ++j) {
            cout << "*  ";
        }
        g = g - 2;
        cout << endl;
    }

    cout <<"Triangolo isoscele di lato" << endl;
    for (i = 1; i < (n / 2) + 1; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << "*  ";
        }
        cout << endl;
    }
    if (i == (n / 2) + 1){
        for (int j = (n / 2) + 1; j > 0; --j) {
            for (int k = 0; k < j; ++k) {
                cout << "*  ";
            }
            cout << endl;
        }
    }
    return 0;
}

