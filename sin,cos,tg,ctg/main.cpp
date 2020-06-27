#include <Windows.h>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
#include <conio.h>
#include <string>
#include<limits>

using namespace std;


int main() {
	
	int a[5], b[5];
	int ok=0;
	a[0] = 0;
	b[0] = 0;
	
for(;;) {

		char wybor;

		cout << "MENU" << endl;

			cout << "|------------------|" << endl;
			cout << "|   1. Przedzial   |" << endl;
			cout << "|   2. Sinus       |" << endl;
			cout << "|   3. Cosinus     |" << endl;
			cout << "|   4. Tangens     | " << endl;
			cout << "|   5. Cotangens   |" << endl;
			cout << "|   6. Wyjscie     |"  << endl;
			cout << "|------------------|" << endl;
		
			cout << "Twoj przedzial: ";

			cout << a[0] << " - " << b[0] << endl;
		wybor=getch();
		
{

		// MENU 

		switch(wybor) {
			case '1': {		
			
				do
				{
				do
				
				{	
				system("cls");
				a[0]=0;
				b[0]=0;

				cout<< endl << "PRZEDZIAL"<< endl << endl;
					cout << "Podaj przedzial w stopniach" << endl << endl;
					cout << "Liczba poczatkowa : ";
    				cin >> a[0];
					cout << "Liczba koncowa - ";
					cin >> b[0];
					cout << endl;
				
				if (cin.fail())
        		{
        		system("cls");
           			cout << "Nie podano liczby" << endl;
           			cout << "Podaj ponownie przedzial";
           			cin.clear();
           		getchar();getchar();getchar();
           		
           		a[0]=0;
				b[0]=0;
        		}
        		else ok=1;
        		} while (ok==0);
        		
				if(a[0]>b[0])
					{
						system("cls");
						
						cout << "Przedzial jest nieprawidlowy" << endl;
						cout << "Wprowadz przedzial ponownie ";
						getchar();getchar();
					}
				
				} while (a[0]>b[0]);
				
				getchar();
				system("cls");
			}
			break;
// SINUS 
			case '2': {		 
				system("cls");

				cout<< endl << "SINUS" << endl << endl;
				a[1]=a[0], b[1]=b[0];
				for(a[1]; a[1]<=b[1]; a[1]++) {
					cout << "Sin " <<a[1]<< " = " << sin((a[1]*(2*M_PI))/360) << endl;

				}
				getchar();
				system("cls");
			}
			break;
// COSINUS
			case '3': {		
				system("cls");

				cout<< endl << "COSINUS" << endl << endl;
				a[2]=a[0], b[2]=b[0];
				for(a[2]; a[2]<=b[2]; a[2]++) {
					cout << "Cos " <<a[2]<< " = " << cos((a[2]*(2*M_PI))/360) << endl;

				}
				getchar();
				system("cls");
			}
			break;
	// TANGENS
			case '4': {		
				system("cls");

				cout<< endl << "TANGENS" << endl << endl;
				a[3]=a[0], b[3]=b[0];
				for(a[3]; a[3]<=b[3]; a[3]++) {
					cout << "Tg " <<a[3]<< " = " << tan((a[3]*(2*M_PI))/360) << endl;

				}
				getchar();
				system("cls");
			}
			break;
// COTANGENS
			case '5': {		
				system("cls");

				cout<< endl << "COTANGENS" << endl << endl;
				a[4]=a[0], b[4]=b[0];
				for(a[4]; a[4]<=b[4]; a[4]++) {
					cout << "Ctg " <<a[4]<< " = " << 1/(tan((a[4]*(2*M_PI))/360))<< endl;

				}
				getchar();
				system("cls");
			}
			break;
			
// ZAKOÑCZENIE PÊTLI 
			case '6':			
				system("cls");
				exit(0);
			break;

			default:
				system("cls");
				cout << "Brak takiej opcji" << endl;

				getchar();
				system("cls");
			break;


		}
	}
}
}
