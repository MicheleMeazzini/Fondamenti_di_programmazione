#include <iostream>
using namespace std;


class TorreDiPisa {
    int maxLoggiati;
    int numLoggiati;
    int *pendenze;


public:
    TorreDiPisa(int);
    TorreDiPisa(TorreDiPisa&);
    ~TorreDiPisa();

    friend ostream& operator<<(ostream&, const TorreDiPisa&);
    TorreDiPisa& operator+=(int);
    operator int()const;
    TorreDiPisa operator++(int );
    TorreDiPisa stabilizza();
};