#include<cstdlib>
#include<iostream>
#ifndef sznur_h
#define sznur_h
struct Sznur
{
private:
    struct Node{
        int dane;
        Node * nast;
        Node(int a, Node * N=NULL)
        {
            dane = a;
            nast = N;
        }
    };
    Node * pocz;
    Node * ogon;
    int ileJest;
public:
    Sznur();
    ~Sznur(); /// pamietac o destruktorze na kolosie
    void wypisz();
    void wstaw(int a);
    void usunFragmenty(int N);

};
#endif
