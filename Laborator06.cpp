#include <iostream>
#include <string>
using namespace std;

class student
{
private:
	string grupa = "1050";
	int nr_matricol;
	int* note;
	int nr_note;
	char* adresa = nullptr;
	const int aniDeStudiu;
	static string universitate;

public:
	string nume;
	int varsta;

	student() : aniDeStudiu(3)
	{
		nume = "anonim";
		varsta = 18;
		nr_matricol = 0;
		note = nullptr;
		nr_note = 0;
	}

	student(string n, int v, string g, int aniDeStudiu) : note(nullptr), nr_note(0), aniDeStudiu(aniDeStudiu)
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

	student(string nume, const char* adresa) :student()
	{
		this->nume = nume;
		this->adresa = new char[strlen(adresa) + 1];
		strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
	}

	student(string nume, int* note, int nr_note) :student()
	{
		this->nume = nume;
		if (note != nullptr && nr_note > 0)
		{
			this->nr_note = nr_note;
			this->note = new int[nr_note];
			for (int i = 0; i < nr_note; i++)
			{
				this->note[i] = note[i];
			}
		}

	}

	student(const student& s) : aniDeStudiu(s.aniDeStudiu)
	{
		this->nume = s.nume;
		this->varsta = s.varsta;
		this->nr_matricol = s.nr_matricol;
		this->grupa = s.grupa;
		if (s.note != nullptr && s.nr_note != 0)
		{
			this->nr_note = s.nr_note;
			this->note = new int[s.nr_note];
			for (int i = 0; i < s.nr_note; i++)
			{
				this->note[i] = s.note[i];
			}
		}
		else
		{
			this->note = nullptr;
			this->nr_note = 0;
		}
		if (s.adresa != nullptr)
		{
			this->adresa = new char[strlen(s.adresa) + 1];
			strcpy_s(this->adresa, strlen(s.adresa) + 1, s.adresa);
		}
		else
		{
			this->adresa = nullptr;
		}
	}

	student& operator=(const student& s)
	{
		if (note != nullptr)
		{
			delete[] note;
		}
		if (adresa != nullptr)
		{
			delete[] adresa;
		}
		this->nume = s.nume;
		this->varsta = s.varsta;
		this->nr_matricol = s.nr_matricol;
		this->grupa = s.grupa;
		if (s.note != nullptr && s.nr_note != 0)
		{
			this->nr_note = s.nr_note;
			this->note = new int[s.nr_note];
			for (int i = 0; i < s.nr_note; i++)
			{
				this->note[i] = s.note[i];
			}
		}
		else
		{
			this->note = nullptr;
			this->nr_note = 0;
		}
		if (s.adresa != nullptr)
		{
			this->adresa = new char[strlen(s.adresa) + 1];
			strcpy_s(this->adresa, strlen(s.adresa) + 1, s.adresa);
		}
		else
		{
			this->adresa = nullptr;
		}
		return *this;
	}

	~student()
	{
		if (note != nullptr)
		{
			delete[] note;
		}
		if (adresa != nullptr)
		{
			delete[] adresa;
		}
	}

	//operatorul de negatie
	bool operator!()
	{
		return nr_note > 0;
	}

	//operatorul de preincrementare
	student operator++()
	{
		this->varsta++;
		return *this;
	}

	//operatorul de postincrementare
	student operator++(int i)
	{
		student copie = *this;
		this->varsta++;
		return copie;
	}

	//operator +
	student operator+(int valoare)
	{
		student copie = *this;
		copie.varsta += valoare;
		return copie;
	}

	//operator index cu rol de citire-scriere
	int& operator[](int index)
	{
		if (index >= 0 && index < nr_note)
		{
			return note[index];
		}
		throw exception("index invalid");
	}

	//operator de cast la int explicit
	explicit operator int()
	{
		return varsta;
	}

	//operator functie ce returneaza lungimea adresei
	int operator()()
	{
		if (adresa != nullptr)
		{
			return strlen(adresa);
		}
		else
		{
			return 0;
		}
	}

	string getGrupa()
	{
		return grupa;
	}

	int getMatricol()
	{
		return nr_matricol;
	}

	void setMatricol(int nr_matricol)
	{
		if (nr_matricol > 0)
		{
			this->nr_matricol = nr_matricol;
		}
	}

	int* getNote()
	{
		if (note != nullptr)
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
			return nullptr;
		}
	}

	int getNote(int index)
	{
		if (index >= 0 && index < nr_note && note != nullptr)
		{
			return note[index];
		}
	}

	int getNrNote()
	{
		return nr_note;
	}

	void setNote(int* note, int nr_note)
	{
		if (note != nullptr && nr_note != 0)
		{
			this->nr_note = nr_note;
			if (this->note != nullptr)
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

	//getter si setter pentru campul static

	static string getUniversitate()
	{
		return universitate;
	}

	static void setUniversitate(string universitate)
	{
		student::universitate = universitate;
	}

	//metodele statice nu il pot prelucra pe this
	//cu toate acestea au acces la membrii privati
	//fiind membre ale clasei
	static float medieSerie(student* studenti, int nrStudenti)
	{
		float suma = 0;
		int nr = 0;
		if (studenti != nullptr && nrStudenti > 0)
		{
			for (int i = 0; i < nrStudenti; i++)
			{
				if (studenti[i].note != nullptr)
				{
					for (int j = 0; j < studenti[i].nr_note; j++)
					{
						suma += studenti[i].note[j];
						nr++;
					}
				}
			}
			if (nr > 0)
			{
				return suma / nr;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}

	//functiile friend pot accesa membrii private sau protected ai clasei
	friend ostream& operator<<(ostream&, student);
	friend istream& operator>>(istream&, student&);
};
string student::universitate = "ASE";

//conservarea comutativitatii operatorului +
student operator+(int valoare, student s)
{
	//nu este nevoie sa facem o copie locala
	//deoarece s este transmis prin valoare
	s.varsta += valoare;
	return s;
}

//operator de afisare
ostream& operator<<(ostream& out, student s)
{
	out << "nume: " << s.nume << endl;
	out << "varsta: " << s.varsta << endl;
	out << "matricol: " << s.nr_matricol << endl;
	out << "grupa: " << s.grupa << endl;
	out << "ani de studiu: " << s.aniDeStudiu << endl;
	out << "adresa: ";
	if (s.adresa != nullptr)
	{
		out << s.adresa;
	}
	out << endl;
	out << "numar note: " << s.nr_note << endl;
	out << "note: ";
	if (s.note != nullptr)
	{
		for (int i = 0; i < s.nr_note; i++)
		{
			out << s.note[i] << " ";
		}
	}
	return out;
}

//operator de citire
istream& operator>>(istream& in, student& s)
{
	cout << "nume = ";
	in >> s.nume;
	cout << "varsta = ";
	in >> s.varsta;
	cout << "numar matricol = ";
	in >> s.nr_matricol;
	cout << "grupa = ";
	in >> s.grupa;
	string buffer;
	cout << "adresa: ";
	in >> buffer;
	if (s.adresa != nullptr)
	{
		delete[] s.adresa;
	}
	s.adresa = new char[buffer.length() + 1];
	strcpy_s(s.adresa, buffer.length() + 1, buffer.c_str());
	cout << "numar note = ";
	in >> s.nr_note;
	if (s.note != nullptr)
	{
		delete[] s.note;
	}
	if (s.nr_note > 0)
	{
		s.note = new int[s.nr_note];
		for (int i = 0; i < s.nr_note; i++)
		{
			cout << "note[" << i << "] = ";
			in >> s.note[i];
		}
	}
	else
	{
		s.nr_note = 0;
		s.note = nullptr;
	}
	return in;
}

int main()
{
	student s;
	s.nume = "Ion Popescu";
	cout << s.nume << endl;
	cout << s.varsta << endl;

	student* ps;
	ps = &s;
	cout << (*ps).nume << endl;
	cout << ps->nume << endl;
	cout << sizeof(s) << endl;
	student s2 = s;
	cout << sizeof(s2) << endl;

	ps = new student();
	cout << ps->nume << endl;
	delete ps;

	student s3("Maria Popescu", 20, "1050", 2);
	cout << s3.nume << endl;

	student s4("Vasile Musat", "Str Ion Creanga, nr 8");
	cout << s4.nume << endl;

	student vector[3];

	student* ps2 = new student("Marcel Ionascu", "Str Avionului, nr 4");
	cout << ps2->nume << endl;

	delete ps2;

	int note[] = { 7,4,9 };

	student s5("Dan", note, 3);

	student s6(s5);

	cout << s.getGrupa() << endl;

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

	delete[] n;
	n = nullptr;

	student::setUniversitate("Politehnica");
	cout << s.getUniversitate() << endl;
	cout << s5.getUniversitate() << endl;
	cout << student::getUniversitate() << endl;

	student studenti[] = { s5, s6 };
	float medie = student::medieSerie(studenti, 2);
	cout << medie << endl;

	//apel constructor de copiere
	student s7 = s5;
	//apel operator=
	s = s6;
	//apel operator= in cascada
	s = s5 = s6;
	//apel operator negatie
	bool areNote = !s5;
	cout << areNote << endl;
	//apel preincrementare
	student s8 = ++s5;
	//apel postincrementare
	student s9 = s6++;

	//apel operator + din clasa
	s8 = s5 + 7;
	//apel operator + global
	s9 = 3 + s5;

	cout << s5 << endl;
	student s10;
	//apel operator de citire
	cin >> s10;
	//apel operator de afisare
	cout << s10 << endl;
	//apel operator index in mod scriere
	s5[1] = 10;
	//apel operator index in mod citire
	cout << s5[1] << endl;

	//apel operator de cast la int explicit
	int varsta = (int)s9;
	cout << varsta << endl;
	//apel operator functie
	cout << s10();
}