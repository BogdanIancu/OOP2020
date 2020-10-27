#include <iostream>
#include <string>
using namespace std;

class student
{
public:
	string nume;
	int varsta;

	//constructor implicit (fara parametri)
	student()
	{
		nume = "anonim";
		varsta = 18;
		nr_matricol = 0;
		note = NULL;
		nr_note = 0;
	}

	//constructor cu 3 parametri
	//ce initializeaza note si nr_note direct in signatura
	//utilizand operatorul :
	student(string n, int v, string g) : note(NULL), nr_note(0)
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

	//constructor cu 2 parametri ce se foloseste si de codul
	//din constructorul implicit
	student(string nume, const char* adresa) :student()
	{
		this->nume = nume;
		this->adresa = new char[strlen(adresa) + 1];
		strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
	}

	//constructor cu 3 parametri
	//ce primeste numele, vectorul de note si dimensiunea sa
	student(string nume, int* note, int nr_note) :student()
	{
		this->nume = nume;
		if (note != NULL && nr_note > 0)
		{
			this->nr_note = nr_note;
			this->note = new int[nr_note];
			for (int i = 0; i < nr_note; i++)
			{
				this->note[i] = note[i];
			}
		}

	}

	//constructorul de copiere
	student(const student& s)
	{
		this->nume = s.nume;
		this->varsta = s.varsta;
		this->nr_matricol = s.nr_matricol;
		this->grupa = s.grupa;
		if (s.note != NULL && s.nr_note != 0)
		{
			this->nr_note = s.nr_note;
			this->note = new int[s.nr_note];
			for (int i = 0; i < s.nr_note; i++)
			{
				this->note[i] = s.note[i];
			}
		}
		if (s.adresa != NULL)
		{
			this->adresa = new char[strlen(s.adresa) + 1];
			strcpy_s(this->adresa, strlen(s.adresa) + 1, s.adresa);
		}
	}

	//destructor
	~student()
	{
		if (note != NULL)
		{
			delete[] note;
		}
		if (adresa != NULL)
		{
			delete[] adresa;
		}
	}

	//getter
	string getGrupa()
	{
		return grupa;
	}

	int getMatricol()
	{
		return nr_matricol;
	}

	//setter
	void setMatricol(int nr_matricol)
	{
		if (nr_matricol > 0)
		{
			this->nr_matricol = nr_matricol;
		}
	}

	//getter-ul pentru campul alocat dinamic
	//va returna o copie a campului
	//pentru a nu permite modificarea atributului private
	//din afara clasei
	//o alta varianta e cea de mai jos
	int* getNote()
	{
		if (note != NULL)
		{
			int* copie = new int[nr_note];
			for (int i = 0; i < nr_note; i++)
			{
				copie[i] = note[i];

			}
			return copie;
		}
		else
		{
			return NULL;
		}
	}

	int getNote(int index)
	{
		if (index >= 0 && index < nr_note && note != NULL)
		{
			return note[index];
		}
	}

	int getNrNote()
	{
		return nr_note;
	}

	//setter-ul pentru un camp de tip
	//vector alocat dinamic de elemente numerice
	//va primi 2 parametri (noul vector si noua dimensiune)
	void setNote(int* note, int nr_note)
	{
		if (note != NULL && nr_note != 0)
		{
			this->nr_note = nr_note;
			if (this->note != NULL)
			{
				delete[] this->note;

			}
			this->note = new int[nr_note];
			for (int i = 0; i < nr_note; i++)
			{
				this->note[i] = note[i];
			}
		}
	}
private:
	string grupa = "1050";
	int nr_matricol;
	int* note; //va avea valoarea default CCCCCCCC
	int nr_note;
	char* adresa = NULL;
	//pentru toti vectorii alocati dinamic avem nevoie
	//si de numarul de elemente (exceptie char*)
};

int main()
{
	//apel automat de constructor implicit
	//s este un obiect
	student s;
	//utilizare atribute publice
	s.nume = "Ion Popescu";
	cout << s.nume << endl;
	cout << s.varsta << endl;

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
	cout << ps->nume << endl;
	//dezalocare obiect alocat dinamic
	delete ps;
	//apel constructor cu 3 parametri
	student s3("Maria Popescu", 20, "1050");
	cout << s3.nume << endl;
	//apel constructor cu 2 parametri
	student s4("Vasile Musat", "Str Ion Creanga, nr 8");
	cout << s4.nume << endl;

	//la crearea unui vector de obiecte
	//constructorul implicit se apeleaza automat
	//pentru fiecare element al vectorului
	student vector[3];

	//alocare dinamica obiect
	//folosind constructorul cu 2 parametri
	student* ps2 = new student("Marcel Ionascu", "Str Avionului, nr 4");
	cout << ps2->nume << endl;
	//dezalocare obiect alocat dinamic
	delete ps2;

	int note[] = { 7,4,9 };
	//utilizare constructor cu 3 parametri
	student s5("Dan", note, 3);

	//apel constructor de copiere
	//varianta alternativa: student s6(s5);
	student s6 = s5;

	//apel getter
	cout << s.getGrupa() << endl;

	//apel setter
	s6.setMatricol(5);
	cout << s6.getMatricol() << endl;

	int z[] = { 1,2,3,4,5 };
	s6.setNote(z, 5);
	int* n = s6.getNote();

	for (int i = 0; i < s6.getNrNote(); i++)
	{
		cout << n[i] << " ";
	}
	cout << endl;

	//deoarece getNote returneza o copie a vectorului din clasa
	//copie ce este alocata dinamic
	//este sarcina apelatorului sa stearga aceasta copie
	delete[] n;
	n = NULL;
}
