#include "stdafx.h"
#include "Interfejs.h"
#include "Uzytkownik.h"
#include "Ksiazka.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
#include <vector>

using namespace std;


Interfejs::Interfejs(): gora(72), dol(80), enter(13), pozycja(0), kod(0)
{
	

	wczytajListeKsiazek(lista_ksiazek);
	
	menu_zalogowany.push_back("Przegladaj");
	menu_zalogowany.push_back("Koszyk");
	menu_zalogowany.push_back("Wyloguj");

	menu_glowne.push_back("rejestracja");
	menu_glowne.push_back("logowanie");
	menu_glowne.push_back("przegladaj");
	menu_glowne.push_back("Wyjscie");

}
Interfejs::~Interfejs()
{
	lista_ksiazek.clear();
	menu_zalogowany.clear();
	menu_glowne.clear();
}
void Interfejs::wczytajListeKsiazek(vector<Ksiazka> &lista_ksiazek)
{
	fstream plik;
	string tytul;
	double cena;

	plik.open("ksiazki.txt", ios::in | ios::out);
	for(int i=0; i<4; i++)
	{
		plik>>tytul;
		plik>>cena;
		Ksiazka k(tytul, cena);
		lista_ksiazek.push_back(k);
	}
	
	plik.close();
}

void Interfejs::bialy()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void Interfejs::zielony()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN );
}
void Interfejs::wyswietl(vector<string> wektor, int pozycja)
{
	for(int i=0;i<(int)wektor.size();i++)
	{
		bialy();
		if(pozycja==i)
			zielony();
		cout<<wektor[i]<<endl;
	}	
}
void Interfejs::wyswietlKsiazki(vector<Ksiazka> lista_ksiazek, int pozycja)
{
	for(int i=0;i<(int)lista_ksiazek.size();i++)
	{
		bialy();
		if(pozycja==i)
			zielony();
		cout<<lista_ksiazek[i].getTytul()<<"\t"<<lista_ksiazek[i].getCena()<<endl;
	}
	bialy();
	if(pozycja == (int)lista_ksiazek.size()  )
		zielony();
	cout<<"Powrot"<<endl;
}
void Interfejs::wyswietlKoszyk(vector<Ksiazka>& koszyk_uzytkownika, int pozycja)
{
	for(int i=0;i<(int)koszyk_uzytkownika.size();i++)
	{
		bialy();
		if(pozycja==i)
			zielony();
		cout<<koszyk_uzytkownika[i].getTytul()<<"\t"<<koszyk_uzytkownika[i].getCena()<<endl;
	}
	bialy();
	if(pozycja == (int)koszyk_uzytkownika.size()  )
		zielony();
	cout<<"Powrot"<<endl;
	bialy();
	if(pozycja == (int)koszyk_uzytkownika.size() + 1 )
		zielony();
	cout<<"Zamow"<<endl;
}
int Interfejs::pozycjaKursora(int kod)
{
	if(kod == 72) ///gora
	{
		if(pozycja>0)
		{
			pozycja--;
		}
	}
	if(kod == 80)///dol
	{
		if(pozycja<100)
		{
			pozycja++;
		}
	}
	return pozycja;
}
void Interfejs::menuGlowne()
{
	pozycja=0;
	while(true)
	{
		system("cls");
		bialy();
		cout<<"==================== MENU GLOWNE ========================"<<endl;
		wyswietl(menu_glowne, pozycja);
		kod= _getch();
		pozycjaKursora(kod);
		if(kod == enter ) // enter 
		{
			if(pozycja == 0)
			{
				system("cls");
				user.rejestracja();
				this->menuZalogowany();
			}
			else if(pozycja == 1)
			{
				system("cls");
				user.logowanie();
				this->menuZalogowany();
			}
			else if(pozycja == 2)
			{
				this->menuPrzegladaj();
			}
			else if(pozycja == 3)
			{
				exit(0);
			}
		}
	}
}
void Interfejs::menuPrzegladaj()
{
	pozycja=0;
	while(true)
	{
		system("cls");
		bialy();
		cout<<"==================== Przegladaj ksiazki ========================"<<endl;
		cout<<"Tytul \tcena"<<endl;
		wyswietlKsiazki(lista_ksiazek, pozycja);		
		kod= _getch();
		pozycjaKursora(kod);
		if(kod == enter ) // enter 
		{
			if(pozycja == lista_ksiazek.size() )	//opcja powrot
			{
				if( user.aktywny == true )
					this->menuZalogowany();
				else 
					this->menuGlowne(); 
			}
			else if( pozycja < (int)lista_ksiazek.size() ) //dodawanie do koszyka 
			{
				if( user.aktywny == true ) 
				{
					//user.dodajDoKoszyka(Ksiazka ksiazka_ktora_chce_kupic);
					user.dodajDoKoszyka(lista_ksiazek[pozycja]);
					system("cls");
					cout<<"Dodano do koszyka "<<endl;
					Sleep(1000);
				}
				else if( user.aktywny == false )
				{
					char wybor;
					cout<<"Czy posiadasz konto w serwisie? (t/n)"<<endl;
					cin>>wybor;
					if( wybor == 't')
					{
						user.logowanie();
						//user.dodajDoKoszyka(Ksiazka ksiazka_ktora_chce_kupic);
						user.dodajDoKoszyka(lista_ksiazek[pozycja]);
						system("cls");
						cout<<"Dodano do koszyka "<<endl;
						Sleep(1000);
					}
					else if( wybor == 'n' )
					{
						user.rejestracja();
						user.dodajDoKoszyka(lista_ksiazek[pozycja]);
						//user.dodajDoKoszyka(Ksiazka ksiazka_ktora_chce_kupic);
						system("cls");
						cout<<"Dodano do koszyka "<<endl;
						Sleep(1000);
					}
				}
			}
		}
	}
}
void Interfejs::menuZalogowany()
{
	pozycja=0;
	while(true)
	{
		system("cls");
		bialy();
		cout<<"==================== Witaj  " <<user.login <<" ========================"<<endl;
		wyswietl(menu_zalogowany,pozycja);	
		kod= _getch();
		pozycjaKursora(kod);
		if(kod == enter ) // enter 
		{
			if(pozycja == 0)
			{
				this->menuPrzegladaj();
			}
			else if(pozycja == 1)
			{
				this->menuKoszyk();
			}
			else if(pozycja == menu_zalogowany.size()-1)
			{
				exit(0); //wyloguj 
			}
		}
	}
}
void Interfejs::menuKoszyk()
{
	pozycja=0;
	while(true)
	{
		system("cls");
		bialy();
		cout<<"==================== Twoj koszyk  ========================"<<endl;
		wyswietlKoszyk(user.getKoszyk().getZakupioneKsiazki(), pozycja);	
		kod= _getch();
		pozycjaKursora(kod);
		if(kod == enter ) // enter 
		{
			if( pozycja == user.getKoszyk().getZakupioneKsiazki().size() )
			{
				this->menuZalogowany(); 
			}
			else if(pozycja == user.getKoszyk().getZakupioneKsiazki().size() + 1 )
			{
				this->zamow();	
			}
		}
	}
}
void Interfejs::zamow()
{
	char wybor;
	system("cls");
	bialy();
	cout<<"================ Potwierdz zamowienie ====================="<<endl;
	cout<<"Suma Twojego zamowienia to: "<<this->user.getKoszyk().sumaZamowienia()<<endl<<endl;
	cout<<"Czy na pewno chcesz kupic te ksiazki? (t/n)"<<endl;
	cin>>wybor;
	if ( wybor == 't' )
	{
		system("cls");
		cout<<"Gratulujemy zakupu!"<<endl;
		this->user.usunKoszyk();
		Sleep(1000);
		menuZalogowany();
	}
	else if ( wybor == 'n' )
	{
		system("cls");
		cout<<"Transakcja anulowana"<<endl;
		Sleep(1000);

	}
}
