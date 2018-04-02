#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include "KoderDekoder.h"
#include "Hex.h"
#include "Kwadrat.h"
#include "ROT13.h"
#include "funkcja.h"
#include "Zapis.h"
using namespace std;

int main()
{
	int wybor, wybor1;
	char znak;
	string napis, zakodowany;
	setlocale(LC_ALL, "");			//polskie znaki
	do
	{	do
		{
		system("cls");
		cout << "MENU"<<endl; 
		cout << "-----------------------------------" << endl;
		cout << "1. Wprowadzenie danych z klawiatury" << endl;
		cout << "2. Wprowadzenie danych z pliku" << endl;
		cout << endl << "0. WYJSCIE" << endl;
		cout << "-----------------------------------" << endl;
			cout << "Twój wybór: ";
			cin >> wybor;
		} while (wybor != 0 && wybor != 1 && wybor != 2);
			getchar();
			system("cls");
			switch (wybor)
			{
			case 1:
			{
				cout << "Wpisz tekst: ";
				getline(cin, napis);
				break;
			}
			case 2:
			{
				fstream plik;
				string xxx;
				do
				{
					system("cls");
					cout << "Podaj nazwê pliku: ";
					getline(cin, xxx);
					plik.open(xxx, ios::in);
				} while (plik.good() == false);
				
				getline(plik, napis);

				plik.close();
				break;
			}
			case 0: exit(0);
			}
		
		KoderDekoder *wsk;
		Hex h(napis);
		ROT13 r(napis);
		Kwadrat k(napis);
		do
		{
			system("cls");
			cout << "WYBIERZ METODÊ" << endl;
			cout << "-----------------------------------" << endl;
			cout << "1.Kodowanie" << endl << "2.Dekodowanie" << endl;
			cout << "-----------------------------------" << endl;
			cout << "Twój wybór: ";
			cin >> wybor1;
		} while (wybor1 != 1 && wybor1 != 2);
		
		do
		{
				system("cls");
				cout << "WYBIERZ ALGORYTM" << endl;
				cout << "-----------------------------------" << endl;
				cout << "1.Hex" << endl << "2.ROT-13" << endl << "3.Macierz" << endl;
				cout << "-----------------------------------" << endl;
				cout << "Twój wybór: ";
				cin >> wybor;
		} while (wybor != 1 && wybor != 2 && wybor != 3);

				switch (wybor1)
				{
				case 1:
					system("cls");
					switch (wybor)
					{
					case 1: wsk = &h; f_kodujaca(wsk); break;
					case 2: wsk = &r; f_kodujaca(wsk); break;
					case 3: wsk = &k; f_kodujaca(wsk); break;
					}
					break;
				case 2:
					system("cls");
					switch (wybor)
					{
					case 1: wsk = &h; f_dekodujaca(wsk); break;
					case 2: wsk = &r; f_dekodujaca(wsk); break;
					case 3: wsk = &k; f_dekodujaca(wsk); break;
					}
					break;
				}
		cout << "\nCzy chcesz zapisaæ dane do pliku? (t/n): ";
		cin >> znak;
	switch (znak)
	{
	case 't': 
	{
		switch (wybor)
		{
		case 1: zakodowany = zapis_do(h); break;
		case 2: zakodowany = zapis_do(r); break;
		case 3: zakodowany = zapis_do(k); break;
		}
		
		fstream plik;
		plik.open("Tekst zakodowany.txt", ios::out | ios::app);
		plik << zakodowany << endl;
		plik.close();
		break; 
	}
	case 'n': break; 
	}
	system("cls");
	cout << "Czy zakoñczyæ program? (t/n): ";
	cin >> znak;
	} while (znak != 't');
	system("pause");
	return 0;
}