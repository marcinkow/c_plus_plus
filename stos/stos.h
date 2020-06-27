#ifndef STOS
#define STOS

#include <iostream>
#include <cstdlib>


using namespace std;

struct Stos {
private:
    struct Node
    {
        int dane;
        Node * nast;
        Node ( int D, Node * N =NULL)
        { dane = D; nast=N;}
    };
   Node * wierzcholek;
   int ileJest;
public:
    Stos();
    ~Stos();
    void Wypisz();
    void Wloz(int a );
    int Zdejmij();

};
#endif // STOS
