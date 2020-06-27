#include <iostream>

using namespace std;

 int licznik;

double silnia(int n)
{

if(n==0 || n==1 )    return 1;
else  return n*silnia(n-1);

}

ciagfib(int n)
{
    licznik++;
    if(n==1 || n==2 ) return 1;

   return  ciagfib(n-1)+ciagfib(n-2);

}



int main()
{

    int n;
    cout << "Podaj n: " ;
    cin>>n;
    cout<<silnia(n)<<endl;
    cout <<ciagfib(n)<<endl;
    cout<<licznik;
    return 0;
}
