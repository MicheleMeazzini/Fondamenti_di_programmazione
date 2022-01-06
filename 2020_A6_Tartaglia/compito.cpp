#include "compito.h"

Tartaglia::Tartaglia(int n) {
    if (n < 0 || n > 15) return;

    ordine = n;
    schema = new int*[n+1];
    for (int i = 0; i <= n ; ++i) {
        schema[i] = new int[i+1];
        schema[i][i] = 1;
        schema[i][0] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            schema[i][j] = schema[i-1][j-1] + schema[i-1][j];
        }
    }
}

Tartaglia::~Tartaglia() {
    for (int i = 0; i <= ordine; ++i)
        delete[] schema[i];

    delete[] schema;
}

ostream& operator<<(ostream& os, Tartaglia& t){
    for (int i = 0; i <= t.ordine; ++i) {
        for (int j = 0; j <= i; ++j)
            os << '\t' << t.schema[i][j];
        os << endl;
    }
    return os;
}

int Tartaglia::fibonacci(int n) {
    if (n < 0 || n > ordine) return -1;

    int fibo = 0;
    int quante_volte;
    quante_volte = n/2; //2
    for (int i = 0; i <= quante_volte; ++i)
            fibo += schema[n-i][i];

    return fibo;
}

void Tartaglia::espandi(int n){
    if (n < 0 || n > ordine) return;

    if (n == 0) cout << "{1}";
    int esp_a = n, esp_b = 0;
    cout << '{';
    for (int i = 0; i <= n; ++i) {
        if (schema[n][i] > 1)
            cout << schema[n][i];
        if (esp_a > 0)
            cout << "a^" << esp_a;
        if (esp_a > 0 && esp_b > 0)
            cout << '*';
        if (esp_b > 0)
            cout << "b^" << esp_b;
        if (i != n)
            cout << " + ";
        esp_a--;
        esp_b++;
    }
    cout << '}';
}

Tartaglia& Tartaglia::operator=(const Tartaglia& t){
    if (ordine == t.ordine) return *this;
    if (this == &t) return *this;

    for (int i = 0; i <= ordine; ++i) //dealloco *this
        delete[] schema[i];
    delete[] schema;

    schema = new int*[t.ordine + 1];    //alloco nuovo *this
    for (int i = 0; i <= t.ordine; ++i) {
        schema[i] = new int[i+1];
    }

    for (int i = 0; i <= t.ordine; ++i) { //copio t in *this
        for (int j = 0; j <= i; ++j) {
            schema[i][j] = t.schema[i][j];
        }
    }

    ordine = t.ordine;

    return *this;
}

