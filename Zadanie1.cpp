/*
Link do treœci zadañ: http://home.agh.edu.pl/~gsmyk/www/materials/PI/zajecia1.pdf

Uwaga!
G³ówn¹ funkcj¹ jest zawsze "int zadanieX ()". Jeœli chcesz skompilowaæ u siebie ca³oœæ musisz mieæ dodatkowo maina, gdzie j¹ wywo³as,
albo po prostu zmienisz jej nazwê na int main (). :)
Dodatkowo ka¿de æwiczenia posiadaj¹ swoj¹ przestrzeñ nazw zadX.

Pozadrawiam MicP :).
*/

#include <iostream>
#include <math.h>

using namespace std;

namespace zad1
{
	void wypisz_liczby();
	void zadanie_fizyka();
	void zadanie_fizyka2();
}


using namespace zad1;

int zadanie1()
{
	wypisz_liczby();
	zadanie_fizyka();
	zadanie_fizyka2();

	return 0;
}

void zad1::wypisz_liczby()
{
	cout << "Petla 1" << endl;
	for (int k = 0; k <= 10; k++)
	{
		cout << k <<" ";
	}

	cout <<endl<< endl << "Petla 2" << endl;
	for (int k = 10; k >= 0; k--)
	{
		cout << k <<" ";
	}

	cout <<endl<< endl << "Petla 3" << endl;
	double liczba = 0.1;
	for (int k = 0; k <= 10; k++)
	{
		cout << liczba*k <<" ";
	}
	cout << endl;
}

void zad1::zadanie_fizyka()
{
	double v = 400;
	double s = 0.4;

	double a = (v*v) / (2 * s);
	cout << "\n\nSrednie opoznienie wynosilo " << a << " m/s^2."<<endl;

	double t = v / a;

	cout << "Czas zaglebiania sie wyniosl " << t << " s." << endl;
}

void zad1::zadanie_fizyka2()
{
	double v = 800;
	double g = 9.81;
	int alpha = 1;
	double pi = 3.14;

	double zasieg;

	cout << "\n\nZadanie z zasiegu:" << endl;
	for (int k = 1; k < 18; k++)
	{
		alpha = 5 * k;
		
		zasieg = v*v*sin( pi*(2 * alpha)/180) / g;
		cout << "\tDla " << alpha << " stopni zasieg wynosi: " << zasieg << endl;
	}

}
