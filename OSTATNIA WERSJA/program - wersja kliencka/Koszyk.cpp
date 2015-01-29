#include "stdafx.h"
#include "Koszyk.h"
#include <iostream>
#include <vector>

using namespace std;

Koszyk::Koszyk()
{
}
Koszyk::~Koszyk()
{
	zakupione_ksiazki.clear();
}
double Koszyk::sumaZamowienia()
{
	double suma = 0;
	for(int i=0; i < (int)zakupione_ksiazki.size() ; i++)
 	{
		suma += zakupione_ksiazki[i].getCena();
	}
	return suma;
}
void Koszyk::setZakupioneKsiazki(Ksiazka ks)
{
	zakupione_ksiazki.push_back(ks);
}
vector<Ksiazka>& Koszyk::getZakupioneKsiazki()
{
	return zakupione_ksiazki;
}
