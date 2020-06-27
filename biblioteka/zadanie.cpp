#include<iostream>
#include "bib.h"
using namespace std;

int main()
{
    Osoba kolega;
    kolega.imie="Hubert";
    kolega.nazwisko="Urbanski";
    kolega.wzrost=160;

    kolega.wypisz();

    Osoba kolezanka("Ewa","Ptak","974291430514",172);
    kolezanka.wypisz();
    cout<<kolezanka.czyKobieta(kolezanka.pesel[9]);

    return 0;
}

