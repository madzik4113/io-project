#include "stdafx.h"
#include "Uzytkownik.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


Uzytkownik::Uzytkownik(void): aktywny(false)
{
}
Uzytkownik::~Uzytkownik(void){}

void Uzytkownik::rejestracja()
{
	fstream plik;
	plik.open("baza.txt",ios::out| ios::in | ios::app);
	if( plik.good() == false )
	{
		cout<<"nie udalo sie otworzyc pliku"<<endl;
		exit(0);
	}
	else
	{
		cout<<"===REJESTRACJA==="<<endl;
		//cout<<"udalo sie owtorzyc plik baza"<<endl;
		{
			cout<<"[rejestracja] Podaj nazwe Uzytkownika : "<<endl;
			cin>>login;
			
			cout<<"[rejestracja] Podaj haslo : "<<endl;
			cin>>haslo;
			
			plik<<login<<";"<<haslo<<endl;
			// ksiegarnia.potwierdz_zamowienie();
			plik.close();
			aktywny = true;
		}

		
	}
}
void Uzytkownik::logowanie()
{
	fstream plik;
	plik.open("baza.txt",ios::out| ios::in | ios::app);
	if(plik.good()==false)
	{
		cout<<"nie udalo sie otworzyc pliku"<<endl;
		exit(0);
	}
	else
	{
		cout<<"Udalo sie nawiazac kontakt z plikiem baza"<<endl;
		cout<<"=====LOGOWANIE DO SYSTEMU====="<<endl;
		cout<<"[logowanie] Podaj login : "<<endl;
		cin>>tempLogin;
		cout<<"[logowanie] Podaj haslo : "<<endl;
		cin>>tempHaslo;

		string loginIhaslo = tempLogin+";"+tempHaslo;
		string linia;

		int licznik=0;
		while(!plik.eof())
		{
			while(getline(plik,linia))
			{
				temp=linia;
				//cout<<temp<<endl;
				if(temp==loginIhaslo)
				{
					cout<<"znalazlem cie !"<<endl;
					cout<<"ZOSTALES POPRAWNIE ZALOGOWANY DO SYSTEMU"<<endl;
					login = tempLogin;
					aktywny = true;
					//ksiegarnia.potwierdz_zamowienie();
				}
				else
				{
					//cout<<"nie znam cie"<<endl;
				}
				licznik++;
			}
		}
		
	}
}
void Uzytkownik::dodajDoKoszyka(Ksiazka ks)
{
	koszyk.setZakupioneKsiazki(ks);
}
Koszyk Uzytkownik::getKoszyk()
{
	return koszyk;
}
void Uzytkownik::usunKoszyk()
{
	koszyk.getZakupioneKsiazki().clear();
}

