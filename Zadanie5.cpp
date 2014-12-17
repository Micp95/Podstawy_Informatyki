/*
Link do treœci zadañ: http://home.agh.edu.pl/~gsmyk/www/materials/PI/zajecia1.pdf

Uwaga!
G³ówn¹ funkcj¹ jest zawsze "int zadanieX ()". Jeœli chcesz skompilowaæ u siebie ca³oœæ musisz mieæ dodatkowo maina, gdzie j¹ wywo³as,
albo po prostu zmienisz jej nazwê na int main (). :)
Dodatkowo ka¿de æwiczenia posiadaj¹ swoj¹ przestrzeñ nazw zadX.

Pozadrawiam MicP :).
*/

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

namespace zad5
{
	void Cwiczenia_1();
	void Zapisz_do_tablicy(int* poczatek, int przedzial, int pojemnosc_tablicy = 20);
	void wyswietl_tablice(int* poczatek, int pojemnosc = 20);

	void Cwiczenia_2();
	void Zapisz_losowe(int* poczatek,int pojemnosc_tablicy = 1000);
	void wyswietl_losowe(int* poczatek, int pojemnosc = 1000);


	void Cwiczenia_3();
	void ZapisBinarny(int liczba);
	int  DlugoscLiczby(int liczba);

	void Cwiczenia_4();
	void sumowanie_elementow(int tablica[100][100]);
	void srednia_arytmetyczna(int tablica[100][100]);
	int** odwrotnosc(int tablica[3][4]);
	int licz_wyznacznik();


	void Cwiczenia_5();
	void mnozeniemaciezy(int a, int b, int c,int d);


	void Cwiczenia_6();

}


using namespace zad5;




int zadanie5()
{
	Cwiczenia_6();


	return 0;
}



void zad5::Cwiczenia_1()
{
	int moja_tablica[20];
	cout << "Podaj przedzial:\t";
	int przedzial;
	cin >> przedzial;
	Zapisz_do_tablicy(moja_tablica, przedzial);
	wyswietl_tablice(moja_tablica);

}
void zad5::Zapisz_do_tablicy(int* poczatek, int przedzial, int pojemnosc_tablicy )
{
	for (int k = 0; k < pojemnosc_tablicy; k++)
	{
		poczatek[k] = przedzial++;
	}

}
void zad5::wyswietl_tablice(int* poczatek, int pojemnosc )
{
	cout << endl;
	for (int k = 0; k < pojemnosc; k++)
	{
		cout <<k <<".\t"<<poczatek[k]<<endl;
	}
	cout << endl;
}



void zad5::Cwiczenia_2()
{
	int duza_tablica[1000];
	Zapisz_losowe(duza_tablica);
	wyswietl_losowe(duza_tablica);

}
void zad5::Zapisz_losowe(int* poczatek, int pojemnosc_tablicy )
{
	for (int k = 0; k < pojemnosc_tablicy; k++)
	{
		poczatek[k] =10 + rand()%81;

	}

}
void zad5::wyswietl_losowe(int* poczatek, int pojemnosc )
{
	cout << "Parzyste:" << endl;
	for (int k = 0; k < pojemnosc; k++)
	{
		if (poczatek[k] % 2 == 0)
			cout <<"\t"<<poczatek[k];
	}
	cout << "\n\nNieparzyste:" << endl;
	for (int k = 0; k < pojemnosc; k++)
	{
		if (poczatek[k] % 2 == 1)
			cout <<"\t" << poczatek[k];
	}
	cout << "\n\nNieparzyste podzielne przez 3:" << endl;
	for (int k = 0; k < pojemnosc; k++)
	{
		if (poczatek[k] % 2 == 1 && poczatek[k] % 3 == 0)
			cout << "\t" << poczatek[k];
	}
	cout << endl;
}


void zad5::Cwiczenia_3()
{
	cout << "Podaj liczbe:\t";
	int liczba;
	cin >> liczba;
	ZapisBinarny(liczba);

}
void zad5::ZapisBinarny(int liczba)
{
	int dlugosc_tablicy = DlugoscLiczby(liczba);
	int *wsk = new int[dlugosc_tablicy];

	int ilosc_jedynek = 0;
	for (int k = dlugosc_tablicy-1; k >=0; k--)
	{
		wsk[k] = liczba % 2;
		liczba = liczba / 2;

		if (wsk[k] == 1)
			ilosc_jedynek++;
	}
	cout << endl;
	for (int k = 0; k < dlugosc_tablicy; k++)
	{
		cout << wsk[k];
	}
	cout << "\n\nIlosc jedynek to: " << ilosc_jedynek << endl;
	cout << endl;

}
int zad5::DlugoscLiczby(int liczba)
{
	int zwrot =0;
	while (liczba > 0)
	{
		liczba = liczba / 2;
		zwrot++;
	}
	return zwrot;
}


void zad5::Cwiczenia_4()
{
	int tablica[100][100];
	sumowanie_elementow(tablica);
	srednia_arytmetyczna(tablica);


	//Losowa tablica 3x4
	int tab1[3][4] = { { 1, 2, 3, 4 }, { 1, 2, 3, 4 }, { 1, 2, 3, 4 } };

	//Wypisywanie elementow tablicy
	for (int k = 0; k < 3; k++)
	{
		for (int p = 0; p <4; p++)
		{
			cout << tab1[k][p] << "\t";
		}
		cout << endl;
	}

	//Odwrotnosc tablicy
	int ** wskaznik = odwrotnosc(tab1);

	//Wyswietlenie odwrotnej tablicy
	for (int k = 0; k < 4; k++)
	{
		for (int p = 0; p <3; p++)
		{
			cout << wskaznik[k][p] << "\t";
		}
		cout << endl;
	}


	licz_wyznacznik();
	


}
void zad5::sumowanie_elementow(int tablica[100][100])
{
	int suma_elementow = 0;

	for (int k = 0; k < 100; k++)
	{
		for (int p = 0; p < 100; p++)
		{
			suma_elementow += tablica[k][p];

		}
	}

	cout << "Suma to: \t" << suma_elementow<<endl;
}
void zad5::srednia_arytmetyczna(int tablica[100][100])
{
	int suma_elementow = 0;

	for (int k = 0; k < 100; k++)
	{
		for (int p = 0; p < 100; p++)
		{
			suma_elementow += tablica[k][p];

		}
	}

	float srednia_arytmetyczna = (float)suma_elementow / 10000; //Stara metoda rzutowania!!

	cout << "Srednia arytmetyczna to: \t" << srednia_arytmetyczna<<endl;

}

int zad5::licz_wyznacznik()
{
	int zwrot = 0;

	int tablica[3][3];


	cout << "\n\nTablica to:" << endl;
	for (int k = 0; k < 3; k++)
	{
		for (int p = 0; p < 3; p++)
		{
			tablica[k][p] = rand();
			cout << tablica[k][p] <<"\t";
		}
		cout << endl;
	}


	//liczenie z przekanych
	zwrot = tablica[0][0] * tablica[0][1] * tablica[0][2];
	zwrot += tablica[1][0] * tablica[2][1] * tablica[2][0];
	zwrot += tablica[2][0] * tablica[1][0] * tablica[1][2];

	zwrot -= tablica[2][0] * tablica[1][1] * tablica[1][2];
	zwrot -= tablica[0][0] * tablica[1][2] * tablica[2][1];
	zwrot -= tablica[0][1] * tablica[1][0] * tablica[2][2];

	cout << "\njej wyznacznik to:\t" << zwrot << endl;
	return zwrot;
}


int** zad5::odwrotnosc(int tablica[3][4])
{

	int wiersze = 4;
	int kolumny = 3;

	int ** nowa_tablica = new int *[wiersze];
	for (int k = 0; k < wiersze;k++)
		nowa_tablica[k] = new int[kolumny];


	for (int k = 0; k < 4; k++)
	{
		for (int p = 0; p < 3; p++)
		{
			nowa_tablica[k][p] = tablica[p][k];

		}
	}

	return nowa_tablica;
}


void zad5::Cwiczenia_5()
{
	int a, b, c, d;
	cout << "Podaj wymiar a pierwszej macierzy - kolumny: \t";
	cin >> a;
	cout << "\n\nPodaj wymiar a pierwszej macierzy - wiersze: \t";
	cin >> b;

	cout << "Podaj wymiar a drugiej macierzy - kolumny: \t";
	cin >> c;
	cout << "\n\nPodaj wymiar a drugiej macierzy - wiersze: \t";
	cin >> d;

	if (a == d)
		mnozeniemaciezy(b,a,d,c);
	else
		cout << "\n\nNie mozna przemnozyc podanych macierzy!" << endl;
}

void zad5::mnozeniemaciezy(int m,int n, int c,int p)
{
	srand(time(NULL));//"Wspomagacz" liczb pseudolosowych
	
	
	cout << "\n\nMaciez A:\n";

	int ** maciezA = new int *[m];
	for (int k = 0; k < m; k++)
		maciezA[k] = new int[n];

	for (int k = 0; k < m; k++)
	{
		for (int g = 0; g < n; g++)
		{
			maciezA[k][g] = (rand() % 20) - 10;
			cout << maciezA[k][g] << "\t";
		}
		cout << endl;
	}


	cout << "\n\nMaciez B:\n";
	int ** maciezB = new int *[n];
	for (int k = 0; k < n; k++)
		maciezB[k] = new int[p];

	for (int k = 0; k < n; k++)
	{
		for (int g = 0; g < p; g++)
		{
			maciezB[k][g] = (rand() % 20)-10 ;
			cout << maciezB[k][g] << "\t";
		}
		cout << endl;
	}

	int ** maciezC = new int *[m];
	for (int k = 0; k < m; k++)
		maciezC[k] = new int[p];



	//Algorytm wykonujacy mnozenie wektorow
	for (int i = 0; i < m; i++)
		for (int j = 0; j < p; j++)
		{
		int s = 0;
		for (int k = 0; k < n; k++) s += maciezA[i][k] * maciezB[k][j];
		maciezC[i][j] = s;
		}


	//Wypisanie koncowego macierza
	cout << "\n\nMaciez C:\n";
	for (int k = 0; k < m; k++)
	{
		for (int g = 0; g < p; g++)
			cout << maciezC[k][g]<<"\t";
		cout << endl;

	}

}

double LiczFunkcje(double x)
{
	double y = 0;
	y = 3 * (x - 2)*(x - 2) + 3 * x - 3;	//Funkcja
//	y = x*x + 2 * x;
	return y;
}


double MetodaProstokatow(int przedzialA, int przedzialB, int n)
{
	int xk = przedzialB;
	int xp = przedzialA;

	double s = 0;
	double dx = (double)(xk - xp) / (double)n;
	//int i = 1;

	for (int i = 1; i <= n; i++)
	{
		s = s + LiczFunkcje(xp + (double)i*dx);
	}

	s = s * dx;

	return s;
}

double MetodaSimpsona(int przedzialA, int przedzialB, int n)
{
	int xk = przedzialB;
	int xp = przedzialA;

	double s = 0;
	double st = 0;
	double dx = (double)(xk - xp) / (double)n;
	//int i = 1;

	for (int i = 1; i <= n; i++)
	{
		//s = s + LiczFunkcje(xp + (double)i*dx);
		double x = xp + i*dx;
		st = st+LiczFunkcje(x - dx / 2);

		if (i < n)
		{
			s = s + LiczFunkcje(x);
		}
	}

	s = dx / 6 * (LiczFunkcje(xp) + LiczFunkcje(xk) + 2 * s + 4 * st);
	
	return s;
}

double MetodaTrapezow(int przedzialA, int przedzialB, int n)
{
	int xk = przedzialB;
	int xp = przedzialA;

	double s = 0;
	double dx = (double)(xk - xp) / (double)n;	
	//int i = 1;

	for (int i = 1; i < n; i++)
	{
		s = s + LiczFunkcje(xp + (double)i*dx);
	}

	s = (s + (LiczFunkcje(xp) + LiczFunkcje(xk)) / 2) * dx;
	return s;
}


void zad5::Cwiczenia_6()
{



	cout << "Metoda prostokata dla 4:\t" << MetodaProstokatow(0, 4, 4)<<endl;
	cout << "Metoda prostokata dla 40:\t" << MetodaProstokatow(0, 4, 40)<<endl;
	cout << "Metoda prostokata dla 400:\t" << MetodaProstokatow(0, 4, 400)<<endl;

	cout << "\n\nMetoda trapeza dla 4:\t" << MetodaTrapezow(0, 4, 4) << endl;
	cout << "Metoda trapeza dla 40:\t" << MetodaTrapezow(0, 4, 40) << endl;
	cout << "Metoda trapeza dla 400:\t" << MetodaTrapezow(0, 4, 400) << endl;
	
	cout << "\n\nMetoda Simpsona dla 4:\t" << MetodaSimpsona(0, 4, 4) << endl;
	cout << "Metoda Simpsona dla 40:\t" << MetodaSimpsona(0, 4, 40) << endl;
	cout << "Metoda Simpsona dla 400:\t" << MetodaSimpsona(0, 4, 400) << endl;
	
}

