#include<string>
using namespace std;

struct Osoba
{
    string imie;
    string nazwisko;
    int pesel[11];
    int wzrost;

    Osoba(string im="", string naz="", string pes="00000000000", int wz=0);

    void wypisz();
    void zmienWzrost(int nowyWzrost);
    void zmienNazwisko(string noweNazwisko);
    bool czyKobieta(int pesel);
    bool czyMezczyzna(string pesel);
};

struct Grupa
{
    Osoba tab[30];
    int ileJest=0;
};
