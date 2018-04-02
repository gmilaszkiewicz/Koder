#include "Hex.h"
#include "KoderDekoder.h"
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;
Hex::Hex()
{

}
Hex::Hex(string x)
{
	tekst = x;					//przypisanie tekstu do zakodowania
	dlugosc = tekst.length();	//obliczenie d³ugoœci tekstu
}

void Hex::koduj()
{
	stringstream ss;
	ss << hex << setfill('0');
	for (int i = 0; i < dlugosc; i++)
	{
		cout << hex << (int)tekst[i] << " ";				//wyœwietlenie tekstu
		ss << setw(2) << static_cast<unsigned>(tekst[i]);	
	}
	tekst = ss.str();										//przypisanie zakodowanego tekstu
	
}
void Hex::dekoduj()
{
	string newString;
	for (int i = 0; i < dlugosc; i += 2)
	{
		string byte = tekst.substr(i, 2);
		char chr = (char)(int)strtol(byte.c_str(), NULL, 16);	//odczytanie 2 znaków jako 1
		newString.push_back(chr);								//dodanie znaku do zmiennej 
	}
	tekst = newString;											//przypisanie zakodowanego tekstu
	cout << tekst;
}

Hex::~Hex()
{
	//cout << "HEX" << endl;
}
