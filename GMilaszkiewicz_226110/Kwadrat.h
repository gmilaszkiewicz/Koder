#pragma once
#include "KoderDekoder.h"
class Kwadrat :public KoderDekoder
{
	string tekst;
	int dlugosc, wymiar=1;
	char **macierz;
public:
	void koduj();
	void dekoduj();
	Kwadrat();
	Kwadrat(string x);
	~Kwadrat();
	friend string zapis_do(Kwadrat K);
};

