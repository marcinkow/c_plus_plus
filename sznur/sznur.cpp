#include "sznur.h"
#include<cstdlib>
#include<iostream>
using namespace std;

void Sznur::wstaw(int a)
{
    Node * nowy;
    nowy=new Node(a);
    if(pocz==NULL)
    {
        pocz=nowy;
        ogon=nowy;
    }
    else
    {
        (*ogon).nast=nowy;
        ogon=nowy;
    }
    ileJest++;
    /*
    (*wsk).pole2 == wsk -> pole2
    */
}

void Sznur::wypisz()
{
    if(pocz==NULL)
        return;
    else
    {
        Node * biegacz=pocz;
        while(biegacz!=NULL)
        {
            cout<<biegacz->dane;
            biegacz=biegacz->nast;
        }
    }
}

void Sznur::usunFragmenty(int N)
{
    if(ileJest<N)
        return;
    else
    {
        Node * wsk1=pocz;
        Node * zliczacz=wsk1;
        Node * przedFragment=NULL;
        Node * zaZliczacz=NULL;
        while(wsk1!=NULL)
        {
            int dlugoscFragmentu=0;
            while(zliczacz!=NULL && zliczacz->dane==wsk1->dane)
            {
                dlugoscFragmentu++;
                zliczacz=zliczacz->nast;
                if(dlugoscFragmentu>=N)
                    {
                        Node * usuwacz = wsk1;
                        wsk1=wsk1->nast;
                        delete usuwacz;
                    }
                else if(dlugoscFragmentu<=N)
                {
                wsk1=
                }
            }
            }
    }
}

