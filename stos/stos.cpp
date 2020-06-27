#include <iostream>
#include <cstdlib>
#include <exception>
#include "stos.h"

using namespace std;

Stos::Stos()
{
    ileJest=0;
    wierzcholek = NULL;
}
Stos::~Stos()
{
    Node * killer;
while(wierzcholek!=NULL){
    killer = wierzcholek;
    wierzcholek =   (*wierzcholek).nast; //wykluczamy ze spolecznosci

    delete killer;
}
cout<<" Destruktor zadzialal"<<endl;
}

void Stos::Wypisz()
{
    Node * biegacz;
    biegacz = wierzcholek;
    cout<< "pocz -> ";
    while(biegacz!=NULL)
{
    cout<<(*biegacz).dane<<"->";
    biegacz=(*biegacz).nast;
}
cout<<" NULL: "<<endl;
}

void Stos::Wloz(int a)
{
    Node * nowy;
    try{
    nowy=new Node(a);
    }catch(exception &e ){throw runtime_error("Brak pamieci");}
    //wpisujemy w odpowiednim miejscu
        (*nowy).nast=wierzcholek;
        wierzcholek=nowy;
ileJest++;
}
int Stos::Zdejmij()
{
    if (ileJest==0) cout<<"Stos pusty :)))";

    int a = (*wierzcholek).dane;

    Node * killer;
    while(wierzcholek!=NULL){
    killer = wierzcholek;
    wierzcholek =   (*wierzcholek).nast; //wykluczamy ze spolecznosci

    delete killer;
    }
    ileJest--;
    return a;
}
