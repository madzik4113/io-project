#ifndef INTERFEJS_H
#define INTERFEJS_H

#include <string>
#include <vector>
#include "Uzytkownik.h"
#include "Ksiazka.h"

using namespace std;

/**
	\brief	Klasa odpowiedzialna za wyswietlanie interfejsu u¿ytkownika
	\details Klasa na podstawie informacji zawartych w pozosta³ych klasach buduje interfejs u¿ytkownika pozwalaj¹c na 
		przyjemne u¿ytkowania aplikacji 

**/
class Interfejs
{
	int gora, dol, enter, pozycja, kod;
	vector<string> menu_glowne, menu_zalogowany;
	vector<Ksiazka> lista_ksiazek;
	Uzytkownik user;
	void bialy();
	void zielony();
	int pozycjaKursora(int kod);
	void menuPrzegladaj();
	void menuZalogowany();
	void menuKoszyk();
	void zamow();
	void wyswietl(vector<string> wektor, int pozycja);
	void wyswietlKsiazki(vector<Ksiazka> lista_ksiazek, int pozycja);
	void wyswietlKoszyk(vector<Ksiazka>& koszyk_uzytkownika, int pozycja);
	void wczytajListeKsiazek(vector<Ksiazka> &lista_ksiazek);
public:
	Interfejs();
	~Interfejs();
	void menuGlowne();
};

#endif