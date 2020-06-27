#include "planeta.h"
Planeta::Planeta(int s, int w, Plaszczak* p)
{
    ile=3;
    szer=s;
    wys=w;
    postac=new Plaszczak[ile];
    postac[0].setx(szer/2);
    postac[0].sety(wys/2);
    postac[1].setx(postac[0].getx());
    postac[1].sety(postac[0].gety());
    postac[2].setx(postac[0].getx());
    postac[2].sety(postac[0].gety());
    robak=NULL;
    ileRobakow=0;

}

bool Planeta::czyJestNaWspolrzednych(int x, int y) const
{
    for(int i=0; i<ile; i++)
    {
        if(postac[i].getx()==x && postac[i].gety()==y)
            return true;
    }
    return false;
}

ostream& operator<<(ostream& os, const Planeta &p)
{
    for(int j=0; j<p.wys; j++)
    {
        for(int i=0; i<p.szer; i++)
        {
            if(i==0 || j==0 || i==p.szer-1 || j==p.wys-1)
            {
                os<<(char)219;
            }

            else if(p.czyJestNaWspolrzednych(i, j))
            {
                os<<p.postac[0];
            }

            else if(p.robak!=NULL && p.robak[0].getx()==i && p.robak[0].gety()==j)
            {
                os<<p.robak[0];
            }
            else
            {
                os<<' ';
            }
        }
        os<<endl;
    }
    return os;
}

void Planeta::wLewo()
{
    for(int i=ile-1; i>0; i--)
    {
        postac[i].setx(postac[i-1].getx());
        postac[i].sety(postac[i-1].gety());
    }
    if(postac->getx()==1)
        postac[0].setx(szer-2);
    else
        postac[0].setx(postac->getx() -1);
}

void Planeta::wPrawo()
{
    for(int i=ile-1; i>0; i--)
    {
        postac[i].setx(postac[i-1].getx());
        postac[i].sety(postac[i-1].gety());
    }
    if(postac->getx()==szer-2)
        postac[0].setx(1);
    else
        postac[0].setx(postac->getx() +1);
}

void Planeta::wGore()
{

    for(int i=ile-1; i>0; i--)
    {
        postac[i].setx(postac[i-1].getx());
        postac[i].sety(postac[i-1].gety());
    }

    if(postac->gety()==1)
        postac[0].sety(wys-2);
    else
        postac[0].sety(postac->gety() -1);
}

void Planeta::wDol()
{
    for(int i=ile-1; i>0; i--)
    {
        postac[i].setx(postac[i-1].getx());
        postac[i].sety(postac[i-1].gety());
    }
    if(postac->gety()==wys-2)
        postac[0].sety(1);
    else
        postac[0].sety(postac->gety() +1);
}

Planeta::~Planeta()
{
    delete [] postac;
    postac=NULL;
    delete [] robak;
    robak=NULL;
}

bool Planeta::czyNaObiekcie(int a, int b)
{
    for(int i=0; i<ile; i++)
    {
        if(postac[i].getx()==a && postac[i].gety()==b)
            return true;
    }
    return false;
}

void Planeta::losujJedzenie()
{
    srand(time(NULL));
    int a;
    int b;
    do
    {
        a=rand()%(szer-2)+1;
        b=rand()%(wys-2)+1;

    }while(czyNaObiekcie(a, b));

    ileRobakow=1;

    Robak *rob=new Robak [ileRobakow];
    rob[0].setx(a);
    rob[0].sety(b);
    robak=rob;



}
void Planeta::wydluz()
{
    Plaszczak *nowy = new Plaszczak [ile+1];
    for(int i=0; i<ile; i++)
    {
        nowy[i]=postac[i];
    }
    ile++;
    nowy[ile-1].setx(postac[ile-2].getx());
    nowy[ile-1].sety(postac[ile-2].gety());
    delete [] postac;
    postac=nowy;
}

bool Planeta::czyZjadl()
{
    if(robak!=NULL && postac[0].getx()==robak[0].getx() && postac[0].gety()==robak[0].gety())
        return true;
    return false;
}

void Planeta::zniszJedzenie()
{
    delete [] robak;
    robak==NULL;
}

bool Planeta::koniec()
{
    for(int i=3; i<ile; i++)
    {
        if(postac[0].getx()==postac[i].getx() && postac[0].gety()==postac[i].gety())
            return true;
    }
    return false;
}
