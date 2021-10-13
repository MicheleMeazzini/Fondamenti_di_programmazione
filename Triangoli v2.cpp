#include <iostream>
using namespace std;

int main (){
    int n, g, f, c;
    cout<< "inserire numero naturale dispari:";
    cin>>n;
    g=n;

    cout << "Triangolo isoscele" << endl;

    for (int i = 0; i < n; ++i) {
        for (int p = 0; p < i; ++p) {
            cout << "   ";
        }
        for (int j = 0; j < g; ++j) {
            cout<<"*  ";
        }
        g = g - 2;
        cout << endl;
    }

    cout <<"Triangolo isoscele di lato" << endl;
    /*for (int j = 0; j < n; j++){
        for (int i = 0; i < c; i++)
            cout << "*  ";
        if (c < (n / 2) + 1)
            c++;
        for (int i = 0 ; i < c; i++)
            cout << "*  ";



        cout << endl;
    }*/
    return 0;
}
