#include <iostream>
#include <string>
using namespace std;

//transmitere parametru prin valoare
void incrementeaza(int x)
{
	x = x + 1;
}

//transmitere parametru prin referinta
void incrementeaza2(int& x)
{
	x = x + 1;
}

//transmitere parametru prin adresa/pointer
void incrementeaza3(int* x)
{
	*x = * x + 1;
}

//nu orice steluta inseamna ca parametrul e transmis prin pointer
//in acest caz avem doar un pointer transmis prin valoare
void incrementeaza4(int* x)
{
	x = x + 1;
}

//enumeratie - tip de data ce rastrange numarul de valori posibile
//la cele de mai jos
enum ziLucratoare { luni = 1, marti = 2, joi = 4 };

//uniune - atributele sunt salvate la aceeasi zona de memorie
union codBare
{
	short codIntern;
	int codFurnizor;
	long long codExtern;
};

//clasa
class student
{
//membrii publici
public:
	//atribute
	string nume;
	int varsta;
	//metoda
	void schimbare_grupa(string grupa_noua)
	{
		if (grupa.length() == grupa_noua.length())
		{
			grupa = grupa_noua;
		}
	}
	//constructor implicit (fara parametri)
	student()
	{
		nume = "anonim";
		varsta = 18;
		nr_matricol = 0;
		cout << "s-a apelat constructorul" << endl;
	}
	//constructor cu parametri
	student(string n, int v, string g)
	{
		nume = n;
		grupa = g;
		if (v > 0)
		{
			varsta = v;
		}
		else
		{
			varsta = 18;
		}
	}
	//constructor cu 1 parametru
	student(string nume)
	{
		//this este un pointer
		//ce salveaza adresa obiectului curent
		this->nume = nume;
	}
	//destructor
	~student()
	{
		cout << "s-a apelat destructorul" << endl;
	}

private:
	//atribute private
	string grupa = "1050";
	int nr_matricol;
};

int main()
{
	int x = 5;
	incrementeaza(x);
	cout << x << endl;
	incrementeaza2(x);
	cout << x << endl;
	incrementeaza3(&x);
	cout << x << endl;
	int* pointer = &x;
	cout << pointer << endl;
	incrementeaza4(pointer);
	//adresa nu se va modifica deoarece
	//functia primeste ca parametru un pointer prin valoare
	cout << pointer << endl;
	ziLucratoare z = ziLucratoare::luni;
	//va afisa un intreg (1 in acest caz)
	cout << z << endl;
	z = (ziLucratoare)2;
	cout << z << endl;
	codBare cod;
	cod.codIntern = 99;
	cout << cod.codIntern << endl;
	cout << cod.codFurnizor << endl;
	cod.codExtern = 9999;
	cout << cod.codExtern << endl;
	cout << cod.codIntern << endl;
	//apel automat de constructor implicit
	//s este un obiect
	student s;
	//utilizare atribute publice
	s.nume = "Ion Popescu";
	cout << s.nume << endl;
	cout << s.varsta << endl;

	//apel metoda publica
	s.schimbare_grupa("1053");

	//pointer la student(obiect)
	student* ps;
	ps = &s;
	cout << (*ps).nume << endl;
	cout << ps->nume << endl;
	cout << sizeof(s) << endl;
	student s2 = s;
	cout << sizeof(s2) << endl;

	//alocare dinamica a unui obiect
	//prin apelul constructorului implicit
	ps = new student();
	ps->schimbare_grupa("1048");
	cout << ps->nume << endl;
	//dezalocare obiect alocat dinamic
	delete ps;
	//apel constructor cu 3 parametri
	student s3("Maria Popescu", 20, "1050");
	cout << s3.nume << endl;
	//apel constructor cu 1 parametru
	student s4("Vasile Musat");
	cout << s4.nume << endl;

	//la crearea unui vector de obiecte
	//constructorul implicit se apeleaza automat
	//pentru fiecare element al vectorului
	student vector[3];

	//alocare dinamica obiect
	//folosind constructorul cu 1 parametru
	student* ps2 = new student("Marcel Ionascu");
	cout << ps2->nume << endl;
	//dezalocare obiect alocat dinamic
	delete ps2;

	//toate obiectele ce sunt in stack
	//sunt sterse dupa acest comentariu
	//lucru ce va duce la apelul destructorului
	//pentru fiecare dintre ele
}