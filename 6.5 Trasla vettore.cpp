#include <iostream>
using namespace std;

void traslaVettore (int vett[], int n){
    int a = vett[n - 1];
    for (int i = n - 1; i > 0; i--) {
        vett[i] = vett[i - 1];
    }
    vett[0] = a;
}

int main (){
    const int N = 6;
    int Vettore[N];
    int k;

    cout << "Inserire gli elementi del vettore:" << endl;
    for (int i = 0; i < N; ++i)
        cin >> Vettore[i];

    cout << "Inserisci un numero di passi di traslazione:" << endl;
    cin >> k;

    if (k < 0)
        return 0;

    for (int i = 0; i < k; ++i) {
        traslaVettore (Vettore, N);
    }

    for (int i = 0; i < N; ++i){
        cout << Vettore[i];
    }

    return 0;
}
