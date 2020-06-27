#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <chrono>
using namespace std::chrono;
using namespace std;


int ShellSort(int tab[], int n, int przedzialy[], int m)
{
    int przedzial;
    int zamiany= 0 ;
    for (int g = 0; g < m; g++)
    {
        przedzial = przedzialy[g];

        for (int i = przedzial; i < n; i += 1)//przedzial zamiast +=1
        {
            int temp = tab[i];
            int j;

            for (j = i; j >= przedzial && tab[j - przedzial] > temp; j -= przedzial)
            {
                tab[j] = tab[j - przedzial];
                zamiany += 1;
            }
            tab[j] = temp;
        }
        /*cout<<"Dla przedzialu "<<przedzial<<": ";
        for(int i =0; i <n; i++)
        {cout<<tab[i]<<" ";
        }
        cout<<endl;*/
    }
    return zamiany;
}

int sortowanie_Shella(int tab[], int n)
{
    int k = 1; int i = 0;
    int krok;
    do
    {
        krok = floor(n/pow(2,k));
        tab[i]=krok;
        k+=1;
        i+=1;
    }
    while(krok>1);
    return i;
}

int sortowanie_Frank_Lazarus(int tab[], int n)
{
    int k = 1; int i = 0;
    int krok;
    do
    {
        krok = 2*floor(n/pow(2,k+1))+1;
        tab[i]=krok;
        k+=1;
        i+=1;
    }
    while(krok>1);
    return i;
}
int sortowanie_Hibbarda(int tab[], int n)
{
    int k = 1; int i = 0;
    int krok;
    while(true)
    {
        krok = pow(2,k)-1;
        if(krok>n) break;
        tab[i]=krok;
        k+=1;
        i+=1;
    }

    reverse(tab,tab+i);
    return i;
}

int sortowanie_Papiernow_Stasiewicz(int tab[], int n)
{
    int k = 1; int i = 1;
    int krok;
    tab[0] = 1;
    while(true)
    {
        krok = pow(2,k)+1;
        if(krok>n) break;
        tab[i]=krok;
        k+=1;
        i+=1;
    }

    reverse(tab,tab+i);
    return i;
}
int sortowanie_Sedgewick(int tab[], int n)
{
    tab[0] = 1;
    int k = 1; int i = 1;
    int krok;
    while(true)
    {
        krok = pow(4,k)+ 3*pow(2,k-1)+1;
        if(krok>n) break;
        tab[i]=krok;
        k+=1;
        i+=1;
    }

    reverse(tab,tab+i);
    return i;
}

int sortowanie_Sedgewick2(int tab[], int n)
{
    int k = 0; int i = 0;
    int krok;
    while(true)
    {
        if (k%2==0) krok = 9*(pow(2,k)-pow(2,k/2))+1;
        if (k%2!=0) krok = 8*pow(2,k) - 6*pow(2, (k+1)/2) + 1;
        if(krok>n) break;
        tab[i]=krok;
        k+=1;
        i+=1;
    }

    reverse(tab,tab+i);
    return i;
}

int sortowanie_Tokuda(int tab[], int n)
{
    int k = 1; int i = 0;
    int krok;
    while(true)
    {
        krok = ceil(0.2*(9*pow(9/4.,k-1)-4));//zaokraglenie
        if(krok>n) break;
        tab[i]=krok;
        k+=1;
        i+=1;
    }

    reverse(tab,tab+i);
    return i;
}



int main()
{
    auto start = high_resolution_clock::now();


    srand( time( NULL ) );
    int rozmiar = 100000;
    int*tab = new int[rozmiar];
    int zamiany;

//    cout<< "Nieposortowana tablica: "<<endl;
    for (int i=0; i<rozmiar; i++){
        tab[i] = rand()%10000+1;
//        cout << tab[i]<< " ";
    }

    int * przedzialy = new int[10];
    int gap = 0;


    /*Wybór rodzaju ci¹gów odstêpu */

 //   gap = sortowanie_Shella(przedzialy, rozmiar); // N^2
//    gap = sortowanie_Frank_Lazarus(przedzialy, rozmiar);  // N^3/2
    gap = sortowanie_Hibbarda(przedzialy, rozmiar); //N^3/2
//    gap = sortowanie_Sedgewick(przedzialy, rozmiar);  //N^4/3
 //   gap = sortowanie_Sedgewick2(przedzialy, rozmiar); // N^4/3
//    gap = sortowanie_Papiernow_Stasiewicz(przedzialy, rozmiar); //N^3/2
//    gap = sortowanie_Tokuda(przedzialy, rozmiar);   // nie wiemy



    zamiany = ShellSort(tab, rozmiar, przedzialy, gap);//wykonanie g³ównego algorytmu

    /*Wydrukowanie posortowanej tablicy */
//        cout<<"Posortowana tablica: "<<endl;
//    for(int i=0; i<rozmiar; i++)
//    {
//        cout << tab[i]<< " ";
//    }


    cout<<endl<<"Konkretne odstepy: ";
    for (int i =0; i < gap;i++)
    {
        cout << przedzialy[i]<<" ";
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
//    cout <<"Czas: "<< duration.count() << endl;
//
//    cout<<endl<<"Posortowanie wymagalo: "<<zamiany<<" przesuniec.";
cout << endl<<duration.count()<<endl;
 cout<<zamiany;

    delete [] tab;
    delete [] przedzialy;

    return 0;

}
