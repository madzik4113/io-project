#ifndef KOSZYK_H
#define KOSZYK_H

#include "Ksiazka.h"
#include <iostream>
#include <vector>

using namespace std;
/**
	\brief Klasa odpowiedzialna za reprezentacje koszyka 
	\details Klasa reprezentuje ksiazki zakupione przez u¿ytkownika w sklepie. Zawiera vector w którym s¹ przechowywane wszystkie zakupione
		ksi¹¿ki. Posiada funkcje zwracaj¹ce zakupione ksi¹¿ki, sumê ca³ego zamówienia, a tak¿e funkcjê wk³adaj¹c¹ ksi¹¿ki do vectora.

**/
class Koszyk
{
	vector <Ksiazka> zakupione_ksiazki;
public:
	/**
		\brief Konstruktor klasy, nie przyjmuj¹cy ¿adnych argumentów
	**/
	Koszyk();
	/**
		\brief Destruktor usuwaj¹cy vector z zakupionymi ksi¹¿kami
	**/
	~Koszyk();
	/**
		\brief Funkcja zwraca sumê zamówienia
		\details Zwraca sumê zamówienia typu double, na podstawie obiektów znajduj¹cych siê w  wektorze zakupione_ksiazki
		\return suma obiektow w koszyku 
	**/
	double sumaZamowienia();
	/**
		\brief Funkcja dok³adaj¹ca ksi¹¿ki do vectora 
		\details Funkcja dok³ada obiekty typu Ksi¹¿ka do vectora zakupione_ksiazki
		\param ks obiekt typu Ksiazka który chcemy dodaæ do listy
	**/
	void setZakupioneKsiazki(Ksiazka ks);
	/**
		\brief Funkcja zwraca ksi¹¿ki w³o¿one do koszyka
		\details Funkcja zwraca vector z obiektami typu Ksi¹¿ka 
		\return vector typu Ksi¹¿ka, lista z ksi¹¿kami
	**/
	vector<Ksiazka>& getZakupioneKsiazki();
};
#endif