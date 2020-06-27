#include "planeta.h"
#include "conio.h"
#include "windows.h"

void przesun(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void clear();

int main()
{
    int wynik=0;
    int najlepszyWynik=0;
    Plaszczak Teodor;


    char znak = NULL;
    char buffor;
    int licznikRobaka=0;

    int rozmiar;
    char wyborRozmiar;
    int szybkosc;
    char wyborSzybkosc;

    while(true)
    {
        cout<<"NAJLEPSZY WYNIK: "<<najlepszyWynik<<endl<<endl;
        cout<<"MENU"<<endl;
        cout<<"Wybierz rozmiar mapy: "<<endl;
        cout<<"1. 15x15"<<endl;
        cout<<"2. 20x20"<<endl;
        cout<<"3. 30x30"<<endl;
        cout<<"4. 40x40"<<endl;
        wyborRozmiar=getch();
        switch(wyborRozmiar)
        {
        case '1':
            rozmiar=15;
            break;
        case '2':
            rozmiar=20;
            break;
        case '3':
            rozmiar=30;
            break;
        case '4':
            rozmiar=40;
            break;
        }
        system("cls");
        cout<<"NAJLEPSZY WYNIK: "<<najlepszyWynik<<endl<<endl;
        cout<<"Wybierz poziom trudnosci"<<endl;
        cout<<"1 poziom LATWY"<<endl;
        cout<<"2 poziom SREDNI"<<endl;
        cout<<"3 poziom TRUDNY"<<endl;
        cout<<"4 poziom BARDZO TRUDNY"<<endl;
        wyborSzybkosc=getch();
        switch(wyborSzybkosc)
        {
        case '1':
            szybkosc=150;
            break;
        case '2':
            szybkosc=100;
            break;
        case '3':
            szybkosc=50;
            break;
        case '4':
            szybkosc=10;
            break;
        }
        system("cls");
        for(int i=3; i>0; i--)
        {
            cout<<"Mapa: "<<rozmiar<<"x"<<rozmiar<<endl;
            cout<<"Poziom: "<<wyborSzybkosc<<endl;
            cout<<endl<<"START ZA: "<<i<<endl;
            Sleep(1000);
            przesun(0, 0);

        }
        system("cls");

        Planeta Rect001(rozmiar, rozmiar, &Teodor);
        cout<<Rect001;

        znak = getch();

        while(true)
        {
            if(licznikRobaka==5) Rect001.losujJedzenie();

            if(licznikRobaka==60) licznikRobaka=0;

            licznikRobaka++;

            if(kbhit())
            {
                buffor=getch();
                if(!(znak=='w' && buffor=='s') && !(znak=='s' && buffor=='w') && !(znak=='a' && buffor=='d') && !(znak=='d' && buffor=='a'))
                    znak=buffor;
            }

            switch(znak)
            {
            case 'w':
                przesun(0, 0);

                Rect001.wGore();
                cout<<Rect001;
                cout<<endl<<"wynik: "<<wynik<<endl<<endl;
                break;
            case 'a':
                przesun(0, 0);

                Rect001.wLewo();
                cout<<Rect001;
                cout<<endl<<"wynik: "<<wynik<<endl<<endl;
                break;
            case 's':
                przesun(0, 0);

                Rect001.wDol();
                cout<<Rect001;
                cout<<endl<<"wynik: "<<wynik<<endl<<endl;
                break;
            case 'd':
                przesun(0, 0);

                Rect001.wPrawo();
                cout<<Rect001;
                cout<<endl<<"wynik: "<<wynik<<endl<<endl;
                break;
            case 'p':
                Rect001.wydluz();
                break;
            default:
                break;
            }


            if(Rect001.koniec())
            {
                przesun(0, 0);
                cout<<Rect001;
                Sleep(1000);
                break;
            }

            if(Rect001.czyZjadl())
            {
                Rect001.wydluz();
                Rect001.zniszJedzenie();
                wynik++;
            }

            Sleep(szybkosc);
        }

        cout<<"Wynik: "<<wynik<<endl;
        if(wynik>najlepszyWynik)
            najlepszyWynik=wynik;
        cout<<"Najlepszy wynik: "<<najlepszyWynik<<endl;
        char jeszczeRaz;
        do
        {
            cout<<endl<<"Chcesz zagrac jeszcze raz?"<<endl;
            cout<<"1. TAK"<<endl;
            cout<<"2. NIE"<<endl;
            jeszczeRaz=getch();
        }while(jeszczeRaz!='1' && jeszczeRaz!='2');
        if(jeszczeRaz=='2') break;
        else system("cls");
        wynik=0;


    }

    return 0;
}


