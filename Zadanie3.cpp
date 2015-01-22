/*
Link do treœci zadañ: http://home.agh.edu.pl/~gsmyk/www/materials/PI/zajecia3.pdf

Uwaga!
G³ówn¹ funkcj¹ jest zawsze "int zadanieX ()". Jeœli chcesz skompilowaæ u siebie ca³oœæ musisz mieæ dodatkowo maina, gdzie j¹ wywo³as,
albo po prostu zmienisz jej nazwê na int main (). :)
Dodatkowo ka¿de æwiczenia posiadaj¹ swoj¹ przestrzeñ nazw zadX.

Pozadrawiam MicP :).
*/

#include <iostream>
#include <math.h>

using namespace std;

namespace zad3
{
	void kalkulator();
	int suma_cyfr(int liczba);
	int zmiana_binarny(int liczba);
	int zamiana(int liczba);

	int potega(int liczba, int ktora);
	int dlugoscliczby(int liczba);

}
using namespace zad3;

int zadanie3()
{
	kalkulator();

	cout << "\n\n\n-----\n\n\n";
	cout << "Podaj liczbe:" << endl;
	int liczba;
	cin >> liczba;
	cout << "Zsumowana liczba to: " << suma_cyfr(liczba)<<endl;
	cout << "Binarnie liczba to: " << zmiana_binarny(liczba) << endl;
	cout << "Zamieniona liczba to: " << zamiana(liczba) << endl;

	return 0;
}
void zad3::kalkulator()
{
	cout << "---KALKULATRO--\n\n";
	double a, b,c, p ;
	double pole = 0;
	double obwod = 0;

	cout << "1.\tProatokat." << endl
		<< "2.\tOkrag." << endl
		<< "3.\tTrojkat." << endl;
	int wybor;
	cout << "\n\nTwoj wybor to: ";
	cin >> wybor;

	switch (wybor)
	{
	case 1:
		cout << "Podaj a:" << endl;
		cin >> a;
		cout << "Podaj b:" << endl;
		cin >> b;

		cout << "\n\n";
		if (a == b)
			cout << "Podany prostokat jest kwadratem." << endl;
		pole = a*b;
		obwod = 2 * a + 2 * b;


		break;
	case 2:
		cout << "Podaj r:" << endl;
		cin >> a;

		pole = 3.14*a*a;
		obwod = 2 * 3.14*a;

		cout << "\n\n";
		break;
	case 3:
		cout << "Podaj a:" << endl;
		cin >> a;
		cout << "Podaj b:" << endl;
		cin >> b;
		cout << "Podaj c:" << endl;
		cin >> c;

		cout << "\n\n";
		if (a + b < c || a + c < b || b + c < a)
		{
			cout << "Podane boki nie tworza trojkata!"<<endl;
			break;
		}
		obwod = a + b + c;
		p = obwod / 2;
		pole = sqrt(p*(p - a)*(p - b)*(p - c));
		break;
	default:
		break;
	}
	cout << "Pole figury to : " << pole << endl;
	cout << "Obwod figury to : " << obwod << endl;
}

int zad3::suma_cyfr(int liczba)
{
	int zwrot = 0;

	while (liczba > 0)
	{
		zwrot += liczba % 10;
		liczba = liczba/10;

	}

	return zwrot;
}


int zad3::zmiana_binarny(int liczba)
{
	int zwrot = 0;

	int ktora = 0;
	int mnoznik = 1;
	while (liczba > 0)
	{
		if (ktora == 0)
			mnoznik = 1;
		else
			mnoznik = potega(10, ktora);

		ktora++;

		zwrot += (liczba % 2)*mnoznik;
		liczba = liczba / 2;
	}
	
	return zwrot;
}

int zad3::potega(int liczba, int ktora)
{
	int zwrot = 1;
	for (int k = 0; k < ktora; k++)
	{
		zwrot = zwrot * liczba;
	}
	return zwrot;
}

int zad3::dlugoscliczby(int liczba)
{
	int zwrot = 0;
	while (liczba > 0)
	{

		liczba = liczba / 10;
		zwrot++;
	}

	return zwrot;

}
int zad3::zamiana(int liczba)
{

	int zwrot = 0;

	int ktora = dlugoscliczby(liczba )-1;
	int mnoznik = 1;
	while (liczba > 0)
	{

		mnoznik = potega(10, ktora);

		ktora--;
		zwrot += (liczba % 10)*mnoznik;
		liczba = liczba / 10;
	}

	return zwrot;
}