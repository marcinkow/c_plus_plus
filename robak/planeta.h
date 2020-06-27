#ifndef PLANETA_H_INCLUDED
#define PLANETA_H_INCLUDED
#include "plaszczak.h"
#include "robak.h"
#include <time.h>
#include <cstdlib>
#include <windows.h>

class Planeta
{
    int szer;
    int wys;
    Plaszczak *postac;
    int dlugosc;
    int ile;
    Robak *robak;
    int ileRobakow;
public:
    Planeta(int s, int w, Plaszczak *p);
    ~Planeta();
    friend ostream& operator<<(ostream&,const Planeta&);
    void wLewo();
    void wPrawo();
    void wGore();
    void wDol();
    bool czyJestNaWspolrzednych(int x, int y) const;
    void losujJedzenie();
    void czyJestRobak()
    {
        if(robak==NULL)
        {
            cout<<"Nie ma"<<endl;
        }
        else
        {
            cout<<"Jest"<<endl;
        }
    }
    void wydluz();
    bool czyZjadl();
    void zniszJedzenie();
    bool koniec();
    bool czyNaObiekcie(int, int);


};

#endif // PLANETA_H_INCLUDED
