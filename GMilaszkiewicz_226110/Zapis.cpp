#include <iostream>
#include "Hex.h"
#include "ROT13.h"
#include "Kwadrat.h"
using namespace std;

string zapis_do(Hex H)
{
	return H.tekst; 
}
string zapis_do(ROT13 R)
{
	return R.tekst;
}
string zapis_do(Kwadrat K)
{
	return K.tekst;
}