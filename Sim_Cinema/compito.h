class Cinema{
    bool seduta[26][9];

    char nome[31];

    int filetot, postitot;

public:

    Cinema(const int n, const int p, const char s[31]);
    bool prenota(const char l, const int j);
    bool cancella(const char l, const int j);
    void stampa();
    int quantiLiberi();
    bool prenotaAdiacenti(const int k);
};
