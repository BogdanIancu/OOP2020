#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//functie template (tip generic T)
template<class T>
T sum(T a, T b)
{
	return a + b;
}

//functie template (tipuri generice T1 si T2)
template<typename T1, typename T2>
bool egal(T1 x, T2 y)
{
	return x == y;
}

class Student
{
public:
	int id = -1;
	int matricol = 0;
	float medie = 0;
	char nume[20] = { "" };

};

class StudentVoluntar : public Student
{
public:
	string organizatie = "";
};

template<class T>
class Repository
{
private:
	string fileName;
public:
	Repository(string fileName)
	{
		this->fileName = fileName;
	}

	void add(T obj)
	{
		ofstream f(fileName, ios::binary | ios::app);
		f.write((char*)&obj, sizeof(obj));
		f.close();
	}

	T read(int id)
	{
		ifstream f(fileName, ios::binary);
		T obj;
		while (!f.eof())
		{
			if (f.read((char*)&obj, sizeof(obj)))
			{
				if (obj.id == id)
				{
					f.close();
					return obj;
				}
			}
			else
			{
				break;
			}
		}
		f.close();
		T default_obj;
		return default_obj;
	}

	void update(T obj)
	{
		ifstream f(fileName, ios::binary);
		ofstream g("temp.bin", ios::binary | ios::trunc);

		while (!f.eof())
		{
			T obj2;
			bool ok = f.read((char*)&obj2, sizeof(obj2)) ? true : false;
			if (ok)
			{
				if (obj.id == obj2.id)
				{
					g.write((char*)&obj, sizeof(obj));
				}
				else
				{
					g.write((char*)&obj2, sizeof(obj2));
				}
			}
			else {
				break;
			}

		}
		f.close();
		g.close();
		remove(fileName.c_str());
		int r = rename("temp.bin", fileName.c_str());
	}

	void erase(int id)
	{
		ifstream f(fileName, ios::binary);
		ofstream g("temp.bin", ios::binary | ios::trunc);

		T obj;
		while (f.read((char*)&obj, sizeof(obj)))
		{
			if (obj.id != id)
			{
				g.write((char*)&obj, sizeof(obj));
			}
		}
		f.close();
		g.close();
		remove(fileName.c_str());
		int r = rename("temp.bin", fileName.c_str());
	}

};

//specializare
template<>
class Repository<StudentVoluntar>
{
private:
	string fileName;
public:
	Repository(string fileName)
	{
		this->fileName = fileName;
	}

	void add(StudentVoluntar obj)
	{
		ofstream f(fileName, ios::binary | ios::app);
		f.write((char*)&obj.id, sizeof(obj.id));
		f.write((char*)&obj.matricol, sizeof(obj.matricol));
		f.write((char*)&obj.medie, sizeof(obj.medie));
		f.write(obj.nume, sizeof(obj.nume));
		int length = obj.organizatie.length() + 1;
		f.write((char*)&length, sizeof(int));
		f.write(obj.organizatie.c_str(), length);
		f.close();
	}

	StudentVoluntar read(int id)
	{
		ifstream f(fileName, ios::binary);
		StudentVoluntar obj;
		while (!f.eof())
		{
			f.read((char*)&obj.id, sizeof(obj.id));
			f.read((char*)&obj.matricol, sizeof(obj.matricol));
			f.read((char*)&obj.medie, sizeof(obj.medie));
			f.read(obj.nume, sizeof(obj.nume));
			int length = 0;
			f.read((char*)&length, sizeof(int));
			char* temp = new char[length];
			f.read(temp, length);
			obj.organizatie = temp;
			if (obj.id == id)
			{
				f.close();
				return obj;
			}

		}
		f.close();
		StudentVoluntar default_obj;
		return default_obj;
	}
};

int main()
{
	cout << sum<int>(2, 3) << endl;
	cout << sum<double>(2.5, 3.5) << endl;
	cout << egal<short, int>(1, 1) << endl;
	//cout << egal<int*, int>(nullptr, 1) << endl;
	//inlocuirea tipului se face la compilare

	//repository pattern
	Repository<Student> repo("student.bin");
	Student s1;
	s1.id = 1;
	s1.matricol = 123;
	s1.medie = 9.5;
	strcpy_s(s1.nume, "Popescu Ion");
	//repo.add(s1);

	Student s2;
	s2.id = 2;
	s2.matricol = 124;
	s2.medie = 8.66f;
	strcpy_s(s2.nume, "Georgescu Ion");
	repo.add(s2);

	Student s3 = repo.read(1);
	Student s4 = repo.read(2);
	Student s5 = repo.read(99);

	Student s6;
	s6.id = 2;
	s6.matricol = 125;
	s6.medie = 7.01f;
	strcpy_s(s6.nume, "Popescu Andrei");

	//repo.update(s6);

	repo.erase(2);

	Student s7 = repo.read(2);
	cout << endl;

	Repository<StudentVoluntar> repo2("studenti_voluntari.bin");
	StudentVoluntar sv1;
	sv1.id = 3;
	sv1.matricol = 126;
	sv1.medie = 7.44f;
	strcpy_s(sv1.nume, "Popescu Bogdan");
	sv1.organizatie = "SISC";
	repo2.add(sv1);
	StudentVoluntar sv2 = repo2.read(3);
}