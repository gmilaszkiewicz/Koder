#pragma once
#include "KoderDekoder.h"
class ROT13 :public KoderDekoder
{
	string tekst;
	int dlugosc;
public:
	void koduj();
	void dekoduj();
	ROT13();
	ROT13(string x);
	~ROT13();
	friend string zapis_do(ROT13 R);
};

