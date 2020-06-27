#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

    int wynik,a;
    int tablica[100000];

bool czy_pierwsza(int n)
{
    if(n<2)
            return false;
    for (int i=2; i*i<=n; i++)
    {if(n%i==0)
            return false;
    }
    return true;

}

int main()
{

    cout<<"Podaj liczbe testow: ";
    cin>>a;

    for (int i=1;i<=a;i++)
    {
        cin>>tablica[i];
    }
//for (int i=1;i<100001;i++)

   //tablica[i]=i;
//cout<<tablica[i]<<endl;
for (int i=1;i<=a;i++)
    if(czy_pierwsza(tablica[i])==1)
        cout<<"TAK"<<endl;
    else
        cout<<"NIE"<<endl;

    //system("pause");
    return 0;
}
