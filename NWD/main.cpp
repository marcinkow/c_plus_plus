#include <iostream>

using namespace std;
int tab[1000000];
int wynik[1000000];
int n=1000000, h,ile,p1,p2,a,b;

int main()
{

    cin>>ile; //ile razy sie wykona
    for (int i=0;i<ile*2;i++)
      {
            cin>>tab[i+1];
      }



for(int i=1;i<ile*2;i+=2){
        do
        {
            if(tab[i]>tab[i+1])
            {tab[i]=tab[i]-tab[i+1];
            wynik[i]=tab[i];
            }
            else{

                    tab[i+1]=tab[i+1]-tab[i];
                    wynik[i]=tab[i+1];
            }
        }
        while(tab[i]!=tab[i+1]);
}


for(int i=1;i<=ile*2;i+=2)
cout<<wynik[i]<<endl;

//for (int i=1;i<=ile*2;i++)
//cout<<tab[i]<<endl;


return 0;
}
