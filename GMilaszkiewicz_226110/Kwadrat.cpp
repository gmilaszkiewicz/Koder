#include "Kwadrat.h"
#include "KoderDekoder.h"
#include <iostream>
#include <string>
using namespace std;

Kwadrat::Kwadrat()
{

}
Kwadrat::Kwadrat(string x)
{
	tekst = x;							//przypisanie tekstu do zakodowania
	dlugosc = tekst.length();			//obliczenie d³ugoœci tekstu
	int  k;
	do
	{
		wymiar++;
		k = wymiar*wymiar;				//ustalanie wielkosci 
	} while (k<dlugosc);
	macierz = new char *[wymiar];		//tworzenie dynamicznej tablicy dwuwymiarowej
	for (int i = 0; i < wymiar; i++)
	{
		macierz[i] = new char[wymiar];
	}
}
void Kwadrat::koduj()
{
	int  m, n, j = 0;
	for (int i = 0; i < wymiar; i++)
	{
		for (m = 0; m<wymiar; m++)
		{
			macierz[i][m] = 32;			//wype³nianie spacjami 
		}
	}
	m = 0; n = 0;
	for (int i = 0; i < dlugosc; i++)
	{
		{
			macierz[n][m] = tekst[i];	//przypisywanie tekstu do zakodowania
			m++;
			if (m == wymiar)					//przeskoczenie do nastepnego wiersza
			{
				n++;
				m = 0;
			}
		}
	}
	tekst = "";
	for (int i = 0; i < wymiar; i++)
	{
		for (m = 0; m<wymiar; m++)
		{
			char znak = macierz[m][i];	//przypisanie zakodowanego tekstu
			tekst.push_back(znak);
		}
	}
	cout << tekst;
	for (int i = 0; i < wymiar; i++)		
	{
		delete[] macierz[i];
	}
	delete[] macierz;
}
void Kwadrat::dekoduj()
{
	int  m, n, j = 0;
	for (int i = 0; i < wymiar; i++)
	{
		for (m = 0; m<wymiar; m++)
		{
			macierz[i][m] = 32;			//wype³nianie spacjami 
		}
	}
	m = 0; n = 0;
	for (int i = 0; i < dlugosc; i++)
	{
		{
			macierz[n][m] = tekst[i];	//przypisywanie tekstu do zakodowania
			m++;
			if (m == wymiar)					//przeskoczenie do nastepnego wiersza
			{
				n++;
				m = 0;
			}
		}
	}
	tekst = "";
	for (int i = 0; i < wymiar; i++)
	{
		for (m = 0; m<wymiar; m++)
		{
			char znak = macierz[m][i];	//przypisanie zakodowanego tekstu
			tekst.push_back(znak);
		}
	}
	cout << tekst;
	for (int i = 0; i < wymiar; i++)		
	{
		delete[] macierz[i];
	}
	delete[] macierz;
}

Kwadrat::~Kwadrat()
{
	//cout<<"Kwadrat"<<endl;
}
