#include "compito.h"

Palazzo::Palazzo(int N)
{
  // verifica parametro di ingresso
  maxPiani = (N<=0)? 1: N;
  
  // allocazione memoria dinamica
  // per l'intero palazzo
  v = new stato* [maxPiani];            //creo l'array rappresentante i piani nello heap
  for(int i=0; i < maxPiani; i++)
  {
    v[i] = new stato[i+1];
    for (int j = 0; j <= i; j++)
      v[i][j]= Chiusa;
  }
  
  // inizialmente, solo un piano
  quantiPiani = 1;
}

Palazzo::Palazzo(const Palazzo& p)
{
  maxPiani = p.maxPiani;
  quantiPiani = p.quantiPiani;
  
  // allocazione memoria dinamica
  v = new stato* [maxPiani];
  for(int i=0; i< maxPiani; i++) 
  {
    v[i] = new stato[i+1];
    for (int j=0; j<=i; j++)
      v[i][j]= p.v[i][j];
  }
}

bool Palazzo::aggiungi()
{
  if (quantiPiani < maxPiani)
  {
    // basta incrementare 'quantiPiani'
    // perche' la memoria e' gia' stata 
    // allocata dal costruttore
    quantiPiani++;    
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
      if (v[i][j] == Chiusa)
        cout << "Chiusa" << ' ';
      else cout << "Aperta" << ' ';
        cout << endl;
  }
}

// --- SECONDA PARTE --- //

Palazzo::~Palazzo()
{
  // eliminazione dei singoli piani
  for(int i=0; i< maxPiani; i++)
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
  if (v[i-1][j-1] == Chiusa)
    v[i-1][j-1] = Aperta;
  else
    v[i-1][j-1] = Chiusa;
}

int Palazzo::operator!() // OPPURE: int Palazzo::operator!()const
{
  int conta=0;
  
  // scorre tutte le finestre del palazzo
  // e incrementa il contatore
  for(int i=0; i< quantiPiani; i++)
    for (int j = 0; j <= i; j++)
      if (v[i][j] == Aperta) 
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
      if (p.v[i][j] == Chiusa) 
        v[i][j]=Chiusa;

  return *this;
}

