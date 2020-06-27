#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>

using namespace std;
char wybor;
char wybor2;
char wybor3;
int liczba[10];
float portfelgracza;
float pieniadzewbanku=5000;
float doplata;
float doplata2;
int dop;
int gry;
int sprawdzenie;
int main()
{
    cout <<"Jedna Gra 5zl"<<endl;
do{
    cout << "Ile razy chesz grac  ?: " ;
    cin>>gry;
    system("cls");

    cout << "Ile wplacasz  ? (musisz miec "<<gry*5<<"): "  ;
    cin>>portfelgracza;
    system("cls");
    sprawdzenie=((gry*5)-portfelgracza)-1;
}while(sprawdzenie>=0);

    cout <<endl<< "   1.GRAJ " << endl;
    cout << "   2.POMOC " << endl;
    cout << "   3.KONIEC " << endl;
for(;;){
     wybor=getch();
    switch(wybor)
    {
    case '1':
    srand(time(NULL));
    for(int i=1; i<=9; i=i+1)
    {
        liczba[i]=rand()%9+1;
    }
    portfelgracza=portfelgracza-5;
    pieniadzewbanku=pieniadzewbanku+5;
    if(portfelgracza<0)
{
    cout<<endl<<"Koniec gry. Jesli chcesz zagrac jeszcze raz wplac odpowiednia sume. "<<endl;
    cout<<"ile wplacasz ?: ";
    cin>>doplata2;
    portfelgracza=portfelgracza+doplata2;
    dop=doplata2/5;
    cout<<"Masz jeszcze "<<dop<<" gry";
    Sleep(1000);
}
    cout << "" << endl;
    cout << " | " <<liczba[9]<<" | "<<liczba[8]<<" | "<<liczba[7]<<" | "<< endl;
    cout << " |-----------|" << endl;
    cout << " | " <<liczba[1]<<" | "<<liczba[2]<<" | "<<liczba[3]<<" | "<<"<<<"<< endl;
    cout << " |-----------|" << endl;
    cout << " | " <<liczba[6]<<" | "<<liczba[5]<<" | "<<liczba[4]<<" | "<< endl;
    if ((liczba[1]==7)&&(liczba[2]==7)&&(liczba[3]==7))
    {cout<<"Rozbiles bank to trzy 7 !!!!!! Wygrywasz cala pule"<<endl;
    portfelgracza=portfelgracza+pieniadzewbanku;}
    else if  ((liczba[1]==6)&&(liczba[2]==6)&&(liczba[3]==6)){cout<<"To trzy 6 !!!!!! Wygrywasz cala 500zl"<<endl;
    portfelgracza=portfelgracza+500;}
    else if  ((liczba[1]==5)&&(liczba[2]==5)&&(liczba[3]==5)){cout<<"To trzy 5 !!!!!! Wygrywasz cala 100"<<endl;
    portfelgracza=portfelgracza+100; }
    else if  ((liczba[1]==4)&&(liczba[2]==4)&&(liczba[3]==4)){cout<<"To trzy 4 !!!!!! Wygrywasz cala 300"<<endl;
    portfelgracza=portfelgracza+300;}
    else if  ((liczba[1]==3)&&(liczba[2]==3)&&(liczba[3]==3)){cout<<"To trzy 3 !!!!!! Wygrywasz cala 300"<<endl;
    portfelgracza=portfelgracza+300;}
    else if  ((liczba[1]==2)&&(liczba[2]==2)&&(liczba[3]==2)){cout<<"To trzy 2 !!!!!! Wygrywasz cala 300"<<endl;
    portfelgracza=portfelgracza+300;}
    else if  ((liczba[1]==1)&&(liczba[2]==1)&&(liczba[3]==1)){cout<<"To trzy 1 !!!!!! Wygrywasz cala 300"<<endl;
    portfelgracza=portfelgracza+300;}
    else if  ((liczba[1]==8)&&(liczba[2]==8)&&(liczba[3]==8)){cout<<"To trzy 8 !!!!!! Wygrywasz cala 500"<<endl;
    portfelgracza=portfelgracza+500;}
    else if  ((liczba[1]==9)&&(liczba[2]==9)&&(liczba[3]==9)){cout<<"To trzy 9 !!!!!! Wygrywasz cala 400"<<endl;
    portfelgracza=portfelgracza+400; }
    else{
    cout<<"niestety nic nie wygrywasz"<<endl;}
    Sleep(1000);
    cout<<"Stan twojego portfela :"<<portfelgracza<<endl;
    cout<<"Nacisnij '1' by zagrac ponownie "<<endl;
    cout<<"Nacisnij '3' by wyjsc z programu "<<endl;
    break;
    system("cls");
    case '2':
    cout << "Jesli wylosujesz trzy siodemki to rozbijasz bank i wygrywasz wszystko"<< endl;
    cout << "jesli wylosujesz trzy szostki lub trzy ósemki to wygrywasz 500zl"<< endl;
    cout << "jesli wyolsujesz trzy  dziewiaki wygrywasz 400zl"<< endl;
    cout << "jesli wylosujesz trzy  jedynki,dwojku, trojki, czworki wygrywasz 300zl"<< endl;
    cout << "jesli wyolosujesz trzy piatki wygrywasz 1000zl   "<< endl;
    break;
    case '3':
    cout<<"Wyplacenie : "<<portfelgracza <<" zl"<<endl;
    system("pause");
    return 0;
    exit(0);
    break;
    default:
    cout<<"nie ma takiej opcji w menu!"<<endl;
    }
}
 system("pause");
    return 0;
}
