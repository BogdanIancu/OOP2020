#pragma once
#include <iostream>
#include <string>
using namespace std;

class contractStudii
{
public:
	//relatie de includere intre clasa contractStudii si enumeratia stareContract
	enum stareContract { nesemnat, semnatDeStudent, contrasemnat };
private:
	int numar;
	string data;
	stareContract stare;

public:
	contractStudii();

	contractStudii(int, string, stareContract);

	void afisareContract();
};
