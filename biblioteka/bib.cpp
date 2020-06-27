#include "bib.h"
#include<iostream>
using namespace std;

void Osoba::wypisz()
{
    cout << imie << " " << nazwisko << endl;
    cout << "Nr PESEL: ";
    for(int i=0; i<11; i++)
        cout << pesel[i];
    cout << endl;
    cout << "Wzrost: " << wzrost << endl;
    cout << endl;
}

void Osoba::zmienWzrost(int nowyWzrost)
{
    wzrost=nowyWzrost;
}

Osoba::Osoba(string im, string naz, string pes, int wz)
{
    imie=im;
    nazwisko=naz;
    wzrost=wz;
    for(int i=0; i<11; i++)
        pesel[i]=pes[i]-'0';
    cout << "Skonstruowalem osobe!" << endl;
}

void Osoba::zmienNazwisko(string noweNazwisko)
{
    nazwisko=noweNazwisko;
}

bool Osoba::czyKobieta(int a)
{
    if(a%2==0)
        return true;
    else
        return false;
}

