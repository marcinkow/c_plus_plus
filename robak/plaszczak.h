#ifndef PLASZCZAK_H_INCLUDED
#define PLASZCZAK_H_INCLUDED

#include <iostream>

using namespace std;

class Plaszczak
{
    int pozx;
    int pozy;
    char wyglad;
public:
    Plaszczak(int pozx=0, int pozy=0, char w=(char)15) : pozx(pozx), pozy(pozy), wyglad(w) {};
    Plaszczak &operator=(const Plaszczak& p)
    {
        pozx=p.pozx;
        pozy=p.pozy;
        wyglad=p.wyglad;
    }
    ~Plaszczak()=default;
    int getx() const {return pozx;}
    int gety() const {return pozy;}
    void setx(int x) {pozx=x;}
    void sety(int y) {pozy=y;}
    friend ostream& operator<<(ostream &os, const Plaszczak &P)
    {
        return os<<P.wyglad;
    }

};

#endif // PLASZCZAK_H_INCLUDED
