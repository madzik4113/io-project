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
	/**
		\brief Konstruktor klasy przyjmuj�cy jako argumenty tytu� oraz cene
	**/
	Ksiazka(string t, double c);
	/**
		\brief Destruktor domy�lny
	**/
	~Ksiazka();
	/**
		\brief Funkcja zwraca tytu� ksi��ki
		\details Zwraca tytu� ksi��ki typu string
		\return tytu� ksi��ki
	**/
	string getTytul();
	/**
		\brief Funkcja ustalaj�ca tytu� ksi��ki
		\details Funkcja ustala tytu� ksi��ki typu string
		\param nowy_tytul typu string 
	**/
	void setTytul(string nowy_tytul);
	/**
		\brief Funkcja zwraca cene ksi��ki
		\details Zwraca cen� ksi��ki typu double
		\return cena typu double
	**/
	double getCena();
	/**
		\brief Funkcja ustalaj�ca cene ksi��ki
		\details Funkcja ustala cene ksi��ki typu double
		\param nowa_cena typu double
	**/
	void setCena(double nowa_cena);
};
#endif