#include <iostream>
using namespace std;

//interfata
class afisabil
{
public:
	//metoda virtuala pura
	virtual void afiseaza() = 0;
};

//interfata
class comparabil
{
public:
	//metoda virtuala pura
	virtual int compara(comparabil* c) = 0;
};

//clasa abstracta
class persoana : public afisabil
{
private:
	string nume;
	string prenume;
	int anulnasterii;
public:
	persoana()
	{
		nume = " ";
		prenume = " ";
		anulnasterii = 1900;
	}

	persoana(string nume, string prenume, int anulnasterii)
	{
		this->nume = nume;
		this->prenume = prenume;
		this->anulnasterii = anulnasterii;
	}

	void afiseaza() override
	{
		cout << "nume: " << nume << endl;
		cout << "prenume: " << prenume << endl;
		cout << "anul nasterii: " << anulnasterii << endl;
	}

	virtual float venit() = 0;
};

class student :public persoana, public comparabil
{
private:
	const int nr_matricol;
	float bursa;
	static int nr_studenti;

public:
	student() :nr_matricol(++nr_studenti)
	{
		bursa = 0;
	}

	student(string nume, string prenume, int anulnasterii, float bursa) : 
		nr_matricol(++nr_studenti), persoana(nume, prenume, anulnasterii)
	{
		this->bursa = bursa;
	}

	float venit() override
	{
		return bursa;
	}

	int compara(comparabil* c)
	{
		student* s = (student*)c;
		if (this->nr_matricol < s->nr_matricol)
		{
			return -1;
		}
		else if (this->nr_matricol == s->nr_matricol)
		{
			return 0;
		}
		else return 1;
	}

	bool operator<(student s)
	{
		return this->bursa < s.bursa;
	}

	void afiseaza() override
	{
		persoana::afiseaza();
		cout << "bursa: " << bursa << endl;
	}
};
int student::nr_studenti = 0;

class angajat :public persoana
{
private:
	int ani_vechime;
	float salariu;
public:
	angajat()
	{
		ani_vechime = 0;
		salariu = 0;
	}

	angajat(string nume, string prenume, int anulnasterii, float salariu) :
		persoana(nume, prenume, anulnasterii)
	{
		this->salariu = salariu;
		ani_vechime = 0;
	}

	float venit() override
	{
		return salariu;
	}
};
class pensionar : public persoana, public comparabil
{
private:
	float pensie;
public:
	pensionar()
	{
		pensie = 0;
	}

	pensionar(string nume, string prenume, int anulnasterii, float pensie) :
		persoana(nume, prenume, anulnasterii)
	{
		this->pensie = pensie;
	}

	float venit()override
	{
		return pensie;
	}

	int compara(comparabil* c)
	{
		pensionar* p = (pensionar*)c;
		if (this->pensie < p->pensie)
		{
			return -1;
		}
		else if (this->pensie == p->pensie)
		{
			return 0;
		}
		else return 1;
	}
};

bool operator<(comparabil& c1, comparabil& c2)
{
	if (c1.compara(&c2) == -1)return true;
	else return false;
}

bool operator>(comparabil& c1, comparabil& c2)
{
	return c1.compara(&c2) == 1;
}

bool operator==(comparabil& c1, comparabil& c2)
{
	return c1.compara(&c2) == 0;
}
int main()
{
	persoana* p = nullptr;
	student s("Ionescu", "Ion", 2000, 700);
	angajat a("Popescu", "Vasile", 1977, 2500);
	pensionar c("Popescu", "Antonio", 1952, 1500);
	int x = 0;
	cout << "valoare=";
	cin >> x;
	if (x % 2 == 0)
	{
		p = &s;
	}
	else
	{
		p = &a;
	}
	cout << p->venit() << endl;
	angajat b("Popescu", "Maria", 1979, 2500);
	persoana** v = new persoana * [3];
	v[0] = &s;
	v[1] = &a;
	v[2] = &c;
	float buget_familie = 0;
	for (int i = 0; i < 3; i++)
	{
		v[i]->afiseaza();
		buget_familie += v[i]->venit();
	}
	delete[] v;
	cout << "Bugetul familiei " << buget_familie << endl;
	student s2;
	cout << s.compara(&s2) << endl;
	pensionar d;
	cout << c.compara(&d) << endl;
	if (s < s2) cout << "true" << endl;
	else cout << "false" << endl;
	if (c < d)cout << "true" << endl;
	else cout << "false" << endl;
}