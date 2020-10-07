#include<stdio.h>

int main()
{
	int x = 2;
	int y = 0;
	//linia de mai jos, daca o decomentam, va genera o eroare de executie
	//erorile de executie sunt mai clar vizibile daca se utilizeaza optiunea
	//Debug -> Start Debugging (F5)
	//int z = x / y;

	//definire pointer si initializare cu NULL
	int* pointer = nullptr;

	int a = 5;

	//pointer salveaza adresa lui a
	pointer = &a;

	//afiseaza adresa de memorie (adresa lui a in acest caz particular)
	printf("%p\n", pointer);

	//afiseaza continutul de la o adresa de memorie
	//operatorul * joaca aici rol de operator de dereferentiere
	printf("%d\n", *pointer);

	//creste adresa salvata in pointer cu sizeof(int)
	pointer++;
	printf("%p\n", pointer);

	//q salveaza o adresa mai mica cu 2 * sizeof(int) decat pointer
	int* q = pointer - 2;
	printf("%p\n", q);

	//diferenta a doi pointeri este un intreg
	//si reprezinta cate variabile de tip int, in acest caz particular
	//incap intre cele doua adrese de memorie
	printf("%d\n", pointer - q);

	pointer--;
	//w este un pointer la pointer la intreg
	//el poate salva doar adrese de adrese de intregi
	int** w = &pointer;
	//adresa salvata in w
	printf("%p\n", w);
	//valoarea de la adresa salvata in w
	//de fapt valoarea lui pointer, pentru acest caz particular
	printf("%p\n", *w);
	//valoarea de la adresa a carei adresa este salvata in w
	printf("%d\n", **w);
}