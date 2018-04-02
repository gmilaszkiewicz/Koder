#include "ROT13.h"
#include "KoderDekoder.h"
#include <iostream>
using namespace std;

ROT13::ROT13()
{

}
ROT13::ROT13(string x)
{
	tekst = x;					//przypisanie tekstu do zakodowania
	dlugosc = tekst.length();	//obliczenie d³ugoœci tekstu
}
void ROT13::koduj()
{
	for (int i = 0; i < dlugosc; i++)
	{
		(int)tekst[i];
		if ((tekst[i] >= 65) && (tekst[i] <= 90))		//du¿e litery
		{
			tekst[i] -= 65;
			tekst[i] += 13;
			tekst[i] = fmod(tekst[i], 26);
			tekst[i] += 65;
			(char)tekst[i] = tekst[i];
		}
		else if ((tekst[i] >= 97) && (tekst[i] <= 122)) //ma³e litery
		{
			tekst[i] -= 97;
			tekst[i] += 13;
			tekst[i] = fmod(tekst[i], 26);
			tekst[i] += 97;
			(char)tekst[i] = tekst[i];
		}
		else if ((tekst[i] >= 48) && (tekst[i] <= 57))	//cyfry
		{
			(char)tekst[i] = tekst[i];
		}
		else if (tekst[i] == 32)						//spacje
		{
			(char)tekst[i] = tekst[i];
		}
		cout << tekst[i];
	}

}
void ROT13::dekoduj()
{
	for (int i = 0; i < dlugosc; i++)
	{
		(int)tekst[i];
		if ((tekst[i] >= 65) && (tekst[i] <= 90))
		{
			tekst[i] -= 65;
			tekst[i] += 13;
			tekst[i] = fmod(tekst[i], 26);
			tekst[i] += 65;
			(char)tekst[i] = tekst[i];
		}
		else if ((tekst[i] >= 97) && (tekst[i] <= 122))
		{
			tekst[i] -= 97;
			tekst[i] += 13;
			tekst[i] = fmod(tekst[i], 26);
			tekst[i] += 97;
			(char)tekst[i] = tekst[i];
		}
		else if ((tekst[i] >= 48) && (tekst[i] <= 57))
		{
			(char)tekst[i] = tekst[i];
		}
		else if (tekst[i] ==32)
		{
			(char)tekst[i] = tekst[i];
		}
		cout << tekst[i];
	}
}

ROT13::~ROT13()
{
	//cout << "ROT"<<endl;
}
