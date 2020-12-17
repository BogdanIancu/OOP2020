#include "contractStudii.h"

contractStudii::contractStudii()
{
	numar = 0;
	data = "";
	stare = stareContract::nesemnat;
}
contractStudii::contractStudii(int numar, string data, stareContract stare)
{
	this->numar = numar;
	this->data = data;
	this->stare = stare;
}
void contractStudii::afisareContract()
{
	cout << "Contractul nr. " << numar << " / " << data << endl;
}