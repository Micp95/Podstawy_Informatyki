/*
Link do treœci zadañ: http://home.agh.edu.pl/~gsmyk/www/materials/PI/zajecia1.pdf

Uwaga!
G³ówn¹ funkcj¹ jest zawsze "int zadanieX ()". Jeœli chcesz skompilowaæ u siebie ca³oœæ musisz mieæ dodatkowo maina, gdzie j¹ wywo³as,
albo po prostu zmienisz jej nazwê na int main (). :)
Dodatkowo ka¿de æwiczenia posiadaj¹ swoj¹ przestrzeñ nazw zadX.

Pozadrawiam MicP :).
*/

#include <iostream>
using namespace std;

namespace zad6
{
	void Cwiczenie1();
	int* Tworz(int wymiar);
	void Uzupelnij(int* wskaznik,int wymiar);


	void Cwiczenie2();
	float* Tworz_tab(int wymiara);
	float** Tworz_tab(int wymiara, int wymiarb );

	void Wyswietl_tab (float*wskaznik, int wymiara);
	void Wyswietl_tab(float**wskaznik, int wymiara,int wymiarb);

	void Cwiczenie3();
	void SpecjalneUzupelnienie(float** tablica,int wymiara,int wymiarb, int schemat);

	void Cwiczenie4();
	double delta(double* parametry);
	double* licz(double* parametry);

	void test(int x);
	void fun();
}


using namespace zad6;

int* tworzi(int ile)
{
	int* tab = new int[ile];
	return tab;
}
void wyp(int* tab, int b)
{
	for (int i = 0; i < b; i++)
		cout << tab[i]<< endl;
}
void uzu(int* tab, int c)
{
	for (int i = 0; i < c; i++)
	{
		tab[i] = 5;
	}
}
void zad6::fun()
{
	int a = 2, b = 3;

	float c = (int)(b);

	
	b = c + a;
	test(20.2);


	int* wskz;
	wskz= tworzi(a);
	cout << wskz[1] << endl;
	uzu(wskz, a);
	wyp(wskz, a);
}


void zad6::test( int x)
{
	
	cout << x << endl;

}


int zadanie6()
{
	//test();
	Cwiczenie4();
	return 0;
}

void zad6::Cwiczenie1()
{
	cout << "Podaj ilosc elementow tablicy:" << endl;
	int a;
	cin >> a;

	int* tablica = Tworz(a);
	
	Uzupelnij(tablica, a);

	delete[] tablica;


	int ilosc_elementow = (int)(400000000 / sizeof(int));
	tablica = Tworz(ilosc_elementow);
	delete[]tablica;
}
int* zad6::Tworz(int wymiar)
{
	int* wskaznik = new int[wymiar];
	for (int k = 0; k < wymiar; k++)
	{
		wskaznik[k] = 0;
	}

	return wskaznik;
}
void zad6::Uzupelnij(int* wskaznik, int wymiar)
{
	int a = 0, b = 1;

	for (int i = 0; i<wymiar; i++)
	{
		wskaznik[i] = b;
		b += a; //pod zmienn¹ b przypisujemy wyraz nastêpny czyli a+b
		a = b - a; //pod zmienn¹ a przypisujemy wartoœæ zmiennej b
	}

}

void zad6::Cwiczenie2()
{


}


float** zad6::Tworz_tab(int wymiara, int wymiarb)
{
	float** tablica = new float*[wymiara];

	for (int k = 0; k < wymiara; k++)
	{
		tablica[k] = new float[wymiarb];
	}

	for (int k = 0; k < wymiara; k++)
	{
		for (int p = 0; p < wymiarb; p++)
			tablica[k][p] = float(float(rand())) / (RAND_MAX);
	}


	return tablica;
}
float* zad6::Tworz_tab(int wymiara)
{
	float* tablica = new float[wymiara];

	for (int k = 0; k < wymiara; k++)
		tablica[k] = float(rand()) / (RAND_MAX);

	return tablica;
}
void zad6::Wyswietl_tab(float*wskaznik, int wymiara)
{
	cout << "Tablica 1-wymiarowa:\n" << endl;
	cout.precision(2);
	for (int k = 0; k < wymiara; k++)
	{
			cout << wskaznik[k] << "  ";
	}
	cout << endl;
}
void zad6::Wyswietl_tab(float**wskaznik, int wymiara, int wymiarb)
{
	cout << "Tablica 2-wymiarowa:\n" << endl;
	cout.precision(2);

	for (int k = 0; k < wymiara; k++)
	{
		for (int p = 0; p < wymiarb; p++)
			cout << wskaznik[k][p] << "  ";
	cout << endl;
	}
}


void zad6::Cwiczenie3()
{
	float** moja_tablica = Tworz_tab(4, 4);

	SpecjalneUzupelnienie(moja_tablica,4,4, 2);
	Wyswietl_tab(moja_tablica,4,4);

}
void zad6::SpecjalneUzupelnienie(float** tablica,int wymiara,int wymiarb, int schemat)
{
	float licznika = 1;
	float  licznikb = 1;

	switch (schemat)
	{
	case 1:
		for (int k = 0; k < wymiara; k++)
		{
			for (int p = 0; p < wymiarb;p++)
			{
				tablica[k][p] = (licznika++ );
			}
		}

		break;
	case 2:
		licznikb = 0;
		for (int k = 0; k < wymiara; k++)
		{
			for (int p = 0; p < wymiarb; p++)
			{
				if ( k == 0)
					tablica[k][p] = licznika++;
				else
					tablica[k][p] = licznika--;

			}
				licznikb++;
			licznika = wymiarb*licznikb;

		}

		break;
	case 3:
		/*
		for (int k = 0; k < wymiara*wymiarb; k++)
		{

			if (k == (wymiara - 1))
				tablica[(int)licznika][(int)licznikb] = k;

		}
		*/

		for (int k = 0; k < wymiara; k++)
		{
			for (int p = 0; p < wymiarb; p++)
			{
				if (k == 0)
					tablica[k][p] = licznika++;
				else if ( k == wymiarb-1)
					tablica[k][p] = licznika++;

				licznikb++;
			}
			licznika = wymiarb*licznikb;

		}

		break;
	default:
		break;
	}


}


void zad6::Cwiczenie4()
{
	double* tablica = new double[3];
	cout << "Podaj A:\n";
	cin >> tablica[0];

	cout << "Podaj B:\n";
	cin >> tablica[1];

	cout << "Podaj C:\n";
	cin >> tablica[2];

	double* wyniki;
	wyniki = licz(tablica);



}

double zad6::delta(double* parametry)
{

	return 0;
}
double* zad6::licz(double* parametry)
{
	if (parametry[0] != 0)
	{
		//Licz delte itp.


	}
	else
	{



	}
	return 0;
}