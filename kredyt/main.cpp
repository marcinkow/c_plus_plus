#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <cmath>

using namespace std;

char wybor,YN,SM;
double long endkwota,S,n,r,m,q,okres,ilosc,prowizja;

double long mies,raty1,raty2;



int main()
{
    /*
    cout<<"Witaj w programie Marcina Kowalczyka"<<endl;
    Sleep(3000);
    system("cls");
    */
    cout << "Wybierz: " << endl;
    cout << "1.Symulator splaty wielkosci rat. " << endl;
    cout << "2.Symulacja zadluzenia. " << endl;
for(;;){
    wybor=getch();
    switch(wybor)
    {
    case '1':
       cout<<"Kwota zaci¹gniêtego kredytu(zl): ";
        cin>>S;
         cout<<"Okres kredytu: ";
        cin>>okres;
        cout<<"Iloœæ rat w roku(podaj liczne calkowita): ";
        cin>>ilosc;
        cout<<"Oprocentowanie w skali roku(%): ";
        cin>>r;
        cout<<"Czy jest pobierana prowizja?(Y/N):";
        cin>>YN;
        if (YN=='y'||YN=='y')
        {
         cout<<"Podaj wysokosc prowizji: ";
         cin>>prowizja;

            endkwota=endkwota+prowizja;
        }

            cout<<"Raty stale(S)/Raty malejace(M)"<<endl;
            for(;;){
            cin>>SM;

            if(SM=='s'||SM=='S')
            {
                r=r*0.01;
                q=1+(r/ilosc);
                n=okres*ilosc;

            endkwota=S * pow(q,n) * (q-1)/(pow(q,n)-1);
            cout<<"Masz do zaplaty: "<<endkwota<<"zl"<<endl;
            cout<<"Sp³acisz to w :"<<n<<" miesi¹ce";
            }
            else if(SM=='M'||SM=='m')
            {



            }
            else
            {
                cout<<"Wpisz odpowiednia liczbe "<<endl;
            }
            }
            /*
        if(YN=='y'||YN=='Y')
        {
        }
            else if(YN=='n'||YN=='N')
        {
            cout<<"jest gitnn";
        }
        else
        {
            cout<<"chuj";
        }
*/

break;
    case '2':


    break;
    default:
    cout<<"nie ma takiej opcji w menu!"<<endl;
    }

}
}
