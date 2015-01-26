#ifndef KSIAZKA_H
#define KSIAZKA_H

#include <string>
using namespace std;

/**
	\brief Klasa odpowiedzialna za reprezentacjê ksi¹¿ki
	\details Klasa reprezentuje w programie ksi¹¿ki, które mo¿na zakupiæ. Ka¿da ksi¹¿ka posiada tytu³ oraz cenê. 

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