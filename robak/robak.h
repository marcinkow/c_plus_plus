#ifndef ROBAK_H_INCLUDED
#define ROBAK_H_INCLUDED

#include <iostream>
class Robak
{
    char wyglad;
    int x;
    int y;
public:
    Robak(int _x=5, int _y=5, char wyg=(char)6) : x(_x), y(_y), wyglad(wyg) {};
    ~Robak()=default;
    int getx() const {return x;}
    int gety() const {return y;}
    void setx(int x) {this->x=x;}
    void sety(int y) {this->y=y;}
    friend ostream& operator<<(ostream& os, const Robak& r)
    {
        return os<<r.wyglad;
    }

};

#endif // ROBAK_H_INCLUDED
