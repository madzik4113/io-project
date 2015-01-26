#ifndef KSIAZKA_H
#define KSIAZKA_H

#include <string>
using namespace std;

/**
	\brief Klasa odpowiedzialna za reprezentacj� ksi��ki
	\details Klasa reprezentuje w programie ksi��ki, kt�re mo�na zakupi�. Ka�da ksi��ka posiada tytu� oraz cen�. 

**/
class Ksiazka
{
	string tytul;
	double cena;
public:
	Ksiazka();
	Ksiazka(string t, double c);
	~Ksiazka();
	string getTytul();
	void setTytul(string nowy_tytul);
	double getCena();
	void setCena(double nowa_cena);
};
#endif