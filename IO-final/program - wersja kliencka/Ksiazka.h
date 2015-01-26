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
	/**
		\brief Konstruktor klasy przyjmuj¹cy jako argumenty tytu³ oraz cene
	**/
	Ksiazka(string t, double c);
	/**
		\brief Destruktor domyœlny
	**/
	~Ksiazka();
	/**
		\brief Funkcja zwraca tytu³ ksi¹¿ki
		\details Zwraca tytu³ ksi¹¿ki typu string
		\return tytu³ ksi¹¿ki
	**/
	string getTytul();
	/**
		\brief Funkcja ustalaj¹ca tytu³ ksi¹¿ki
		\details Funkcja ustala tytu³ ksi¹¿ki typu string
		\param nowy_tytul typu string 
	**/
	void setTytul(string nowy_tytul);
	/**
		\brief Funkcja zwraca cene ksi¹¿ki
		\details Zwraca cenê ksi¹¿ki typu double
		\return cena typu double
	**/
	double getCena();
	/**
		\brief Funkcja ustalaj¹ca cene ksi¹¿ki
		\details Funkcja ustala cene ksi¹¿ki typu double
		\param nowa_cena typu double
	**/
	void setCena(double nowa_cena);
};
#endif