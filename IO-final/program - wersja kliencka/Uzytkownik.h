#pragma once

#include "Koszyk.h"
#include "Ksiazka.h"
#include <iostream>
#include <string>
using namespace std;

/**
	\brief Klasa odpowiedzialna za reprezentacje u¿ytkownika 
	\details Klasa reprezentuje u¿ytkownika w programie przechowuje ona jego dane oraz koszyk z zakupionymi ksi¹¿kami

**/
class Uzytkownik
{
	Koszyk koszyk;
public:
	Uzytkownik(void);
	~Uzytkownik(void);
	string login, haslo, mail;
	string tempLogin, tempHaslo;
	string temp;
	bool aktywny;
	void rejestracja();
	void logowanie();
	void dodajDoKoszyka(Ksiazka ks);
	Koszyk getKoszyk();
	void usunKoszyk();
};

