#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <cstdlib>   
#include <ctime>
#include <conio.h>
// Biblioteki czasu ?? 
#include<time.h>
#include<stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

char znak[4] ={3,4,5,6};

string figura[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};


string karty[152];
string karty_z[52];
string skladanie[4];
string schowek[4];


int zwyciestwo()
{
system("CLS");
cout<<endl<<endl<<endl<<"\t \t \t \t Wygrales!!!"<<endl<<endl<<endl;

	
system ("pause");
exit(0);
return 0;	
}


	void tworzenie_kart()
	{
		int i=0;
		int j=0;



for(int x=0;x<52;x++)
{

	
	karty[x]="|";
	karty[x]+=znak[i];
	karty[x]+=figura[j];
	karty[x]+="|";

	karty_z[x]=karty[x];
	j++;

	if(j%13==0)
	{
		i=i+1;
		j=0;
	}
	
	
}
		}

void zasady_gry()
{
	cout<<"Witamy w grze Pasjans FreeCell Autorstwa : Michal Sliwa i Mateusz Malysiak"<<endl;
	cout<<"zapoznaj siê z zasadami gry a nastepnie kliknij dowolny klawisz"<<endl;
	cout<<"Zasady:"<<endl<<"plansza do gry sklada siê z trzech grup pol: "<<endl<<"pierwsza grupa to grupa docelowa skladajaca sie z czterech pol w ktorej znajduja sie posortowane karty od asa do krola"<<endl;
	cout<<"druga grupa to grupa pomocnicza, skladajaca sie z czterech pol, na kazde pole mozesz przesunac jedna, dowolna karte z grupy glownej"<<endl;
	cout<<"grupa trzecia to grupa glowna na ktorej znajduja sie losowo posortowane karty"<<endl<<endl;
	cout<<"w kazdym ruchu mozna przeniesc dokladnie jedna karte. Do poprawnych ruchow naleza:"<<endl;
	cout<<"przeniesienie karty z pola glownego na inne pole"<<endl<<"przeniesienie karty z pola glownego na pole pomocznice"<<endl;
	cout<<"przeniesienie karty z pola pomocnicznego na pole glowne"<<endl<<"przeniesienie kart z pola glownego do pola docelowego"<<endl;
	cout<<"przeniesienie karty z pola pomocniczego na pole docelowe"<<endl<<endl;
	cout<<"zasady sterowania zostana opisane po rozpoczeciu gry"<<endl;
	cout<<endl;
	system("pause");
	}
	
void wyswietlanie_kart()
{

	
	cout<<"Sterowanie:"<<endl<<"a=lewo"<<endl<<"d=prawo"<<endl<<"p=zaznacz karte do przeniesienia"<<endl<<"z=gdzie karta ma byc przeniesiona"<<endl<<"s=przenies do schowka"<<endl;
	cout<<"1 2 3 4 zaznacz karte z schowka"<<endl;
	cout<<"K dodaj karte do zlozonej tali"<<endl<<endl;
	cout<<"Numer kolumny:"<<endl;
	for(int i=1;i<9;i++)
	{
		cout<<"\t"<<i;
	}
	
cout<<endl;
	for(int i=0;i<=151;i++){
	if(i%8==0)cout<<endl;
	if(i==0){
		
		cout<<"\t"<<karty[i];
	}else{
	
		 
	cout<<"\t"<<karty[i];
}
	
}
cout<<endl<<"Zlozone talie:";
for(int k=0;k<=3;k++)
{
	cout<<skladanie[k];
}

cout<<endl<<"Schowek:";

for(int j=0;j<=3;j++)
{
	cout<<endl<<j+1<<"."<<schowek[j];
}
cout<<endl;
cout<<endl;

}



 

void tasowanie ()
{
	
	srand(time(0));

    int  los;

    int random;
    string temp;

       for (los = 0; los < 52; los++)

      {

            random = rand() % 52;

            temp = karty[los]; karty[los] = karty[random]; karty[random] = temp;

        }

}

bool zasady_przenoszenia(string gora, string dol)
{
	string porownanie;
	for(int i=0; i<152;i++)
	{
		porownanie=karty_z[i];

	if(porownanie==gora)
	{
		
		if(i<=13)
		{
			if(dol==karty_z[i+25] || dol==karty_z[i+38])
			{
				return true;
			}
			else         //czarne do czerwonych
			{
				return false;
			}
		}
		else if(i>=14 && i<=26)
		{
			if(dol==karty_z[i+12] || dol==karty_z[i+25])
			{
				return true;
			}
			else        //czarne do czerwonych
			{
				return false;
			}
		}
		else if(i>=27 && i<=39)
		{
			if(dol==karty_z[i-14] || dol==karty_z[i-27])
			{
				return true;
			}
			else    //czerwone do czarnych
			{
				return false;
			}
		}
		else if(i>=40)
		{
			if(dol==karty_z[i-27] || dol==karty_z[i-40])
			{
				return true;
			}
			else    // czerwone do czarnych
			{
				return false;
			}
		}
		
	}
	
	if(gora=="")
	{
		return true;
	}
	
	
	}
}

bool skladanie_f(string dol)
{
	int j=0;
	int i=0;
for(int k=0;k<53;k++)
{

while(j!=4)
{
	if(skladanie[j]=="" && dol==karty_z[i])
{
	skladanie[j]=dol;
	return true;
}
else if(skladanie[j]==karty_z[k] && dol==karty_z[k+1])
{
	skladanie[j]=dol;
	return true;
	
}


j++;
i+=13;


}
j=0;
i=0;
}

	return false;

	
}

bool schowek_f(string dol)
{
bool schowek_tak;
	
for(int i=0;i<=4;i++)
	if(schowek[i]=="")
	{
	
	schowek[i]=dol;
	schowek_tak=true;
	return schowek_tak;
	}
	else if(i<3)
	{
		continue; 
	}
	else
	{
		cout<<"Schowek jest pelny!"<<endl;
		Sleep(2000);
		break;
	}
}


string gora_f(int d)
{
	string gora;
	while(true)
	{
		d+=8;
		
	if(karty[d]=="")
	{
	gora=karty[d-8];
	return gora;
	}
}
}

string dol_f(int z)
{
	string dol;
	
		while(true)
	{
		z+=8;
		
	if(karty[z]=="")
	{

		 dol=karty[z-8];
		
		
		return dol;
	}
	}	
	
}

void usun_f(int u)
{
	while(true)
	{
		u+=8;
		if(karty[u]=="")
		{
			karty[u-8]="";
			break;
		}
	}
	
	
}

void usun_schowek(int u)
{
schowek[u]="";	
}




void przeniesienie(int d,int z)
{
string gora;
string dol;

	while(true)
	{
		d+=8;
		
	if(karty[d]=="")
	{
	gora=karty[d-8];
	break;
	}
	}
	
	while(true)
	{
		z+=8;
		


	if(karty[z]=="")
	{
		 dol=karty[z-8];
		bool tak=zasady_przenoszenia(gora,dol);
		if(tak)
		{
		if(gora=="")
		karty[d-8]=dol;
		else
		karty[d]=dol;
		

		karty[z-8]="";
		break;
		}
		else
		{
		
			cout<<"Niedozwolony ruch!";
				Sleep(2000);
				break;
		};
	}
	

}
}


void przeniesienie_z_schowka(int d, string dol)
{
string gora;


	while(true)
	{
		d+=8;
		
	if(karty[d]=="")
	{
	gora=karty[d-8];
	break;
	}

	}
	

		bool tak=zasady_przenoszenia(gora,dol);
		if(tak)
		{
		if(gora=="")
		karty[d-8]=dol;
		else
		karty[d]=dol;

		for(int i=0;i<5;i++)
		{
		if(dol==schowek[i])
		{
		schowek[i]="";
		break;
		}
		}
		
		}
		else
		{
		
			cout<<"Niedozwolony ruch!";
				Sleep(2000);
			
		};
	
	

}
	
	
	
	


void sterowanie ()
{
	char kierunek;
	int zaznaczony=10;
	int ster=1;
	string schowany;
	int schowany_numer;
	cout<<"Zaznaczona kolumna :"<<ster;

	while(kierunek!='z'){
	
	kierunek=getch();


	
switch(kierunek)
{
	case 'd':
		if(ster<8 )
		{
			ster++;
			cout<<"\b"<<ster;
		}
		else
		{
			cout<<"\b"<<ster;
		}
		
		
	break;
	
	case 'a':
	
		
		if(ster>1){
		
		ster--;
		cout<<"\b"<<ster;
		}
		else
		{
			cout<<"\b"<<ster;
		}
	
		
	break;
	
	case 'p':
	
	zaznaczony=ster-1;
	cout<<endl<<"Przenies do kolumny :"<<ster;
	
	
		
	break;

	case 'z':
	
		if(zaznaczony!=10)
		{
			int d=ster-1;
		
			
			
			system("CLS");
			przeniesienie(d,zaznaczony);
			wyswietlanie_kart();
			sterowanie();
		}
		else if(schowany!="")
		{
			int d=ster-1;
			system("CLS");
			przeniesienie_z_schowka(d, schowany);
			wyswietlanie_kart();
			sterowanie();			
			
		}
		else
		{
			system("CLS");
			cout<<"Nie zaznaczyles ktora karte nalezy przeniesc !"<<endl;
			Sleep(2000);
			system("CLS");
			wyswietlanie_kart();
			sterowanie();
		}

	break;
		
	case 's':
		
			if(zaznaczony!=10)
		{
			
		
			
			
			system("CLS");
			bool s_tak=schowek_f(dol_f(zaznaczony));
			if(s_tak==true)
			{
				usun_f(zaznaczony);
			}
			wyswietlanie_kart();
			sterowanie();
		}
		else
		{
			system("CLS");
			cout<<"Nie zaznaczyles ktora karte nalezy przeniesc do schowka!"<<endl;
			Sleep(2000);
			system("CLS");
			wyswietlanie_kart();
			sterowanie();
		}
	
	
		
	break;
	
	case 'k':
		if(zaznaczony!=10)
		{
			bool sk_tak=skladanie_f(dol_f(zaznaczony));
			if(sk_tak==true)
			{
			usun_f(zaznaczony);
			system("CLS");
			wyswietlanie_kart();
			sterowanie();
			}
			else
			{
			system("CLS");
			cout<<"Ruch niedozwolony !"<<endl;
			Sleep(2000);
			wyswietlanie_kart();
			sterowanie();	
			}

		}
		else if(schowany!="")
		{
			bool sk_tak=skladanie_f(schowany);
			if(sk_tak==true)
			{
			usun_schowek(schowany_numer);
			system("CLS");
			wyswietlanie_kart();
			sterowanie();
			}
			else
			{
			system("CLS");
			cout<<"Ruch niedozwolony !"<<endl;
			Sleep(2000);
			system("CLS");
			wyswietlanie_kart();
			sterowanie();	
			}					
		}
		else
		{
			cout<<"Nie zaznaczyles ktora karte nalezy przeniesc !"<<endl;
			Sleep(2000);
			system("CLS");
			wyswietlanie_kart();
			sterowanie();
		}
		

	
	break;
	case '1':
	schowany=schowek[0];
	schowany_numer=0;
	cout<<endl<<"Zaznaczono karte z schowka ";
	cout<<endl<<"Przenies do kolumny :"<<ster;
	break;
	
	case '2':
	schowany=schowek[1];
	schowany_numer=1;
	cout<<endl<<"Zaznaczono karte z schowka ";
	cout<<endl<<"Przenies do kolumny :"<<ster;
	break;
	
	case '3':
	schowany=schowek[2];
	schowany_numer=2;
	cout<<endl<<"Zaznaczono karte z schowka ";
	cout<<endl<<"Przenies do kolumny :"<<ster;
	break;
	case '4':
	schowany=schowek[3];
	schowany_numer=3;
	cout<<endl<<"Zaznaczono karte z schowka ";
	cout<<endl<<"Przenies do kolumny :"<<ster;
	break;
	
	case '*':
		zwyciestwo();
	break;
	
	default:
	
	system("CLS");
	cout<<"Sterowanie za pomoca klawiszy A D Z S P K 1 2 3 4"<<endl;
	Sleep(2000);
	system("CLS");
	wyswietlanie_kart();
	sterowanie();
		
	break;
	}
	
}

}







int main(int argc, char** argv) {

   
zasady_gry();
system("cls");

tworzenie_kart();
tasowanie ();

wyswietlanie_kart();

sterowanie();

system ("pause");

return 0;
}
