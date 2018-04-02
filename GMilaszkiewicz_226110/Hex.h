#pragma once
#include "KoderDekoder.h"
class Hex :public KoderDekoder
{
	string tekst;
	int dlugosc;
public:
	void koduj();
	void dekoduj();
	Hex();
	Hex(string x);
	~Hex();
	friend string zapis_do(Hex H);
};

