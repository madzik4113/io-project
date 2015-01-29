#ifndef KOSZYK_H
#define KOSZYK_H

#include "Ksiazka.h"
#include <iostream>
#include <vector>

using namespace std;
/**
	\brief Klasa odpowiedzialna za reprezentacje koszyka 
	\details Klasa reprezentuje ksiazki zakupione przez u�ytkownika w sklepie. Zawiera vector w kt�rym s� przechowywane wszystkie zakupione
		ksi��ki. Posiada funkcje zwracaj�ce zakupione ksi��ki, sum� ca�ego zam�wienia, a tak�e funkcj� wk�adaj�c� ksi��ki do vectora.

**/
class Koszyk
{
	vector <Ksiazka> zakupione_ksiazki;
public:
	/**
		\brief Konstruktor klasy, nie przyjmuj�cy �adnych argument�w
	**/
	Koszyk();
	/**
		\brief Destruktor usuwaj�cy vector z zakupionymi ksi��kami
	**/
	~Koszyk();
	/**
		\brief Funkcja zwraca sum� zam�wienia
		\details Zwraca sum� zam�wienia typu double, na podstawie obiekt�w znajduj�cych si� w  wektorze zakupione_ksiazki
		\return suma obiektow w koszyku 
	**/
	double sumaZamowienia();
	/**
		\brief Funkcja dok�adaj�ca ksi��ki do vectora 
		\details Funkcja dok�ada obiekty typu Ksi��ka do vectora zakupione_ksiazki
		\param ks obiekt typu Ksiazka kt�ry chcemy doda� do listy
	**/
	void setZakupioneKsiazki(Ksiazka ks);
	/**
		\brief Funkcja zwraca ksi��ki w�o�one do koszyka
		\details Funkcja zwraca vector z obiektami typu Ksi��ka 
		\return vector typu Ksi��ka, lista z ksi��kami
	**/
	vector<Ksiazka>& getZakupioneKsiazki();
};
#endif