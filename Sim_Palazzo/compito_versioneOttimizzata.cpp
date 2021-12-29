#include "compito.h"

// Versione ottimizzata per risparmiare memoria

Palazzo::Palazzo(int N)
{
  // verifica parametro di ingresso
  maxPiani = (N<=0)? 1: N;
  
  // allocazione memoria dinamica
  // per l'intero palazzo
  v = new bool* [maxPiani];
  // inizialmente, solo un piano con finestra chiusa
  quantiPiani = 1;
  v[0] = new bool[1];
  v[0][0] = false;
}

Palazzo::Palazzo(const Palazzo& p)
{
  maxPiani = p.maxPiani;
  quantiPiani = p.quantiPiani;
  
  // allocazione memoria dinamica
  v = new bool* [maxPiani];
  for(int i=0; i< quantiPiani; i++) 
  {
    v[i] = new bool[i+1];
    for (int j=0; j<=i; j++)
      v[i][j]= p.v[i][j];
  }
}

bool Palazzo::aggiungi()
{
  if (quantiPiani < maxPiani)
  {
    quantiPiani++;
    // alloco il nuovo piano, con finestre chiuse
    v[quantiPiani-1] = new bool[quantiPiani];
    for(int j=0; j < quantiPiani; j++)
      v[quantiPiani-1][j] = false;

    return true;
  }
  return false;
}

void Palazzo::stampa()
{
  cout << '<' << quantiPiani << '>' << endl;
  for(int i=0; i< quantiPiani; i++) {
    cout << "Piano " << (i+1) << ": ";
    for (int j = 0; j <= i; j++)
      if (v[i][j] == false)
        cout << "Chiusa" << ' ';
      else cout << "Aperta" << ' ';
        cout << endl;
  }
}

// --- SECONDA PARTE --- //

Palazzo::~Palazzo()
{
  // eliminazione dei singoli piani
  for(int i=0; i< quantiPiani; i++)
    delete[] v[i];
  
  // eliminazione del palazzo
  delete[] v;
}

void Palazzo::cambia(int i, int j)
{
  // verifica parametri ingresso
  if ((i<=0) || (j<=0) || (i > quantiPiani) || (j > i))
    return;
  
  // i-1 e j-1 perche' la numerazione parte da 1 
  if (v[i-1][j-1] == false)
    v[i-1][j-1] = true;
  else
    v[i-1][j-1] = false;
}

int Palazzo::operator!() // OPPURE: int Palazzo::operator!()const
{
  int conta=0;
  
  // scorre tutte le finestre del palazzo
  // e incrementa il contatore
  for(int i=0; i< quantiPiani; i++)
    for (int j = 0; j <= i; j++)
      if (v[i][j] == true) 
        conta++;
   
  return conta;
}

Palazzo& Palazzo::operator%=(const Palazzo& p)
{
  // se numero piani e' diverso, lascia il palazzo inalterato
  if(quantiPiani != p.quantiPiani)
    return *this;
  
  // per ogni finestra chiusa di p,
  // chiudi la corrispondente finestra
  // del palazzo su cui la funzione e' invocata
  for(int i=0; i< quantiPiani; i++)
    for (int j = 0; j <= i; j++)
      if (p.v[i][j] == false) 
        v[i][j]=false;

  return *this;
}

