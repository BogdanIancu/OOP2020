#include <iostream>
#include <string>
using namespace std;

//functia de adaugare a unui element intr-un vector alocat dinamic
int* adauga_element(int* vector, int dimensiune, int element)
{
	if (vector != nullptr && dimensiune > 0)
	{
		int* aux = new int[dimensiune + 1];
		for (int i = 0; i < dimensiune; i++)
		{
			aux[i] = vector[i];
		}
		aux[dimensiune] = element;
		//dupa apelul functiei vechiul vector nu va mai putea fi folosit
		//decat daca apelul se face ca in main
		delete[] vector;
		return aux;
	}
	return nullptr;
}

int main()
{
	//vector alocat static cu 9 elemente de tip int
	int v[9];
	//calcularea dimensiunii unui vector alocat static
	cout << sizeof(v) / sizeof(int) << endl;

	//vector alocat dinamic cu 11 elemente de tip int
	int dim = 11;
	//spre deosebire de vectorii statici, cei alocati dinamic
	//pot folosi variabile ca si dimensiune
	int* w = new int[dim];
	for (int i = 0; i < dim; i++)
	{
		w[i] = i + 1;
	}
	for (int i = 0; i < dim; i++)
	{
		cout << w[i] << " ";
	}
	cout << endl;
	//apel functie
	w = adauga_element(w, dim, 99);
	//afisam noul vector
	for (int i = 0; i < dim + 1; i++)
	{
		cout << w[i] << " ";
	}
	cout << endl;
	//dezalocare vector
	delete[] w;

	//vector de caractere
	//modalitatea de a salva in C siruri de caractere
	char sir[10];
	//al doilea parametru este lungimea sirului de copiat
	//incluzand caracterul de sfarsit \0
	strcpy_s(sir, 6, "Gigel");
	cout << sir << endl;
	//cate caractere sunt pana la \0
	cout << strlen(sir) << endl;
	//a nu se confunda cu numarul de caractere pana la \0
	cout << sizeof(sir) << endl;

	const char* const nume = "Ionel";
	//vector de caractere alocat dinamic
	char* sir_dinamic = new char[strlen(nume) + 1];
	strcpy_s(sir_dinamic, strlen(nume) + 1, nume);
	cout << sir_dinamic << endl;

	//strcmp returneaza -1 daca primul sir il precede alfabetic pe al doilea
	//0 daca sunt egale
	//si 1 in caz contrar
	cout << ((strcmp(sir, sir_dinamic) == 0) ? "sunt egale" : "nu sunt egale") << endl;

	//in C++ avem tipul string pentru siruri de caractere
	string s1 = "Vasile";
	string s2 = "Marcel";
	//lungimea unui string
	cout << s1.length() << endl;
	//concatenare
	string s3 = s1 + s2;
	cout << s3 << endl;
	//transformare din char* in string
	string s4 = sir_dinamic;
	cout << s4 << endl;
	//transformare din string in char*
	const char* t = s2.c_str();
	cout << t << endl;
	//comparare a doua stringuri
	if (s1 == s2) 
	{
		cout << "sunt la fel" << endl;
	}
	else
	{
		cout << "nu sunt la fel" << endl;
	}
	//dezalocare sir dinamic
	delete[] sir_dinamic;

	//matrice alocata static cu 2 linii si 3 coloane
	float m[2][3];
	cout << "nr linii = " << sizeof(m) / sizeof(m[0]) << endl;
	cout << "nr coloane = " << sizeof(m[0]) / sizeof(float) << endl;

	//matrice alocata dinamic cu 2 linii si 3 coloane
	int nrLinii = 2;
	int nrColoane = 3;
	float** z = new float* [nrLinii];
	for (int i = 0; i < nrLinii; i++)
	{
		z[i] = new float[nrColoane];
	}
	float k = 0;
	for (int i = 0; i < nrLinii; i++)
	{
		for (int j = 0; j < nrColoane; j++)
		{
			z[i][j] = ++k;
		}
	}

	for (int i = 0; i < nrLinii; i++)
	{
		for (int j = 0; j < nrColoane; j++)
		{
			cout << z[i][j] << " ";
		}
		cout << endl;
	}

	//dezalocare matrice alocata dinamic
	for (int i = 0; i < nrLinii; i++) 
	{
		delete[] z[i];
	}
	delete[] z;
}