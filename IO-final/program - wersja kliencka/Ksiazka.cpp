#include "stdafx.h"
#include "Ksiazka.h"
#include <iostream>
#include <string>
using namespace std;


Ksiazka::Ksiazka(string t, double c): tytul(t), cena(c)
{
}
Ksiazka::~Ksiazka()
{
}
string Ksiazka::getTytul()
{
	return tytul;
}
void Ksiazka::setTytul(string nowy_tytul)
{
	tytul = nowy_tytul;
}
double Ksiazka::getCena()
{
	return cena;
}
void Ksiazka::setCena(double nowa_cena)
{
	cena = nowa_cena;
}