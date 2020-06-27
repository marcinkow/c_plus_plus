#include <iostream>
#include "stos.h"
using namespace std;

int main()
{
   Stos st;
   int L;
   cout<<"Budujemy stos, 999 koñczy";
   while(true)
   {
       cin>>L;
       if(L==999) break;
       st.Wloz(L); st.Wypisz();
    }
    cout<<st.Zdejmij();
    return 0;
}
