/*
Link do treœci zadañ: http://home.agh.edu.pl/~gsmyk/www/materials/PI/zajecia4.pdf

Uwaga!
G³ówn¹ funkcj¹ jest zawsze "int zadanieX ()". Jeœli chcesz skompilowaæ u siebie ca³oœæ musisz mieæ dodatkowo maina, gdzie j¹ wywo³as,
albo po prostu zmienisz jej nazwê na int main (). :)
Dodatkowo ka¿de æwiczenia posiadaj¹ swoj¹ przestrzeñ nazw zadX.

Pozadrawiam MicP :).
*/

#include <iostream>

using namespace std;

namespace zad4
{
	double dodawanie(double, double);
	double odejmowanie(double, double);
	double mnozenie(double, double);
	double dzielenie(double, double);
	int modulo(int, int);

	double potegowanie(int liczna, int potega = 2);
	int sumacyfr(int liczba);

	void ZadPrzedzialy(int poczatek, int koniec);
	bool LiczbaPierwsza(int liczba);
	double  Ciag(double, int);
	void LiczeniePol();

	double LiczProstokat(double a, double b);
	double LiczTrojkat(double a, double h);
	double LiczProstopadloscian(double a, double b, double c);

}
using namespace zad4;

int zadanie4()
{
	bool koniec = false;
	int wybor;

	while (!koniec)
	{

		system("cls"); //Czyszczenie ekranu


		double a, b;
		int c, d;

		cout << "Podaj a:" << endl;
		cin >> a;
		cout << "Podaj b:" << endl;
		cin >> b;

		//Menu
		cout << "Wybierz dzialanie:" << endl;
		cout << "\t1. Dodawanie.\t(a+b)" << endl;
		cout << "\t2. Odejmowanie.\t(a-b)" << endl;
		cout << "\t3. Mnozenie. \t(a*b)" << endl;
		cout << "\t4. Dzielenie. \t(a/b)" << endl;
		cout << "\t5. Modulo. \t(a%b)" << endl << endl;
		cout << "\t6. Potegowanie.\t(a^b i a^2)" << endl;
		cout << "\t7. Cwiczenie z przedzialami." << endl;
		cout << "\t8. Czy podane liczby sa pierwsze?" << endl;
		cout << "\t9. Ciag" << endl;
		cout << "\t10. Liczenie pol." << endl << endl;


		cout << "\t0. Wyjscie." << endl;

		cin >> wybor;

		switch (wybor)
		{
		case 0:
			koniec = true;
			break;
		case 1:
			cout << "Wynik dodawania to: " << dodawanie(a, b) << endl;
			break;
		case 2:
			cout << "Wynik odejmowania to: " << odejmowanie(a, b) << endl;
			break;
		case 3:
			cout << "Wynik mnozenia to: " << mnozenie(a, b) << endl;

			break;
		case 4:
			if (b == 0)
				cout << "Nie mozna dzielic przez 0!" << endl;
			else
				cout << "Wynik dzielenia to: " << dzielenie(a, b) << endl;

			break;
		case 5:
			c = (int)(a);//Zamiana typu double na int
			d = (int)(b);
			cout << "Wynik modulo to: " << modulo(a, b) << endl;
			break;
		case 6://Zadanie 2 - potêgowanie
			d = (int)(b);
			potegowanie(a, d);
			cout << "Wynik potegowania: " << potegowanie(a, d) << endl;
			cout << "Potegowanie do kwadratu: " << potegowanie(a) << endl;
			break;
		case 7://Zadanie 3 - badanie przedzia³ów
			c = (int)(a);
			d = (int)(b);
			ZadPrzedzialy(c, d);
			break;
		case 8://Zadanie 4 - liczby pierwsze
			c = (int)(a);
			d = (int)(b);

			if (LiczbaPierwsza(c) == true)
				cout << "Liczba " << c << " jest liczba pierwsza." << endl;
			else
				cout << "Liczba " << c << " nie jest liczba pierwsza." << endl;

			if (LiczbaPierwsza(d) == true)
				cout << "Liczba " << d << " jest liczba pierwsza." << endl;
			else
				cout << "Liczba " << d << " nie jest liczba pierwsza." << endl;


			break;
		case 9://Zadanie 5 - Ciag

			d = (int)(b);

			cout << "A - liczba a0, B - ktory wyraz" << endl;
			cout << "Wynik to: " << Ciag(a, d) << endl;

			break;
		case 10: //Zadanie 6 - Liczenie pol - wywoluje funkcje z nowym menu 
			LiczeniePol();
			break;
		default:
			break;
		}


		//Zamkniecie programu
		char czykoniec;
		cout << "\nCzy zamknac program?[T/N]" << endl;
		cin >> czykoniec;

		if (czykoniec == 't' || czykoniec == 'T')
			koniec = true;



	}
	//system ("pause");
	return 0;
}


void zad4::LiczeniePol()
{
	system("cls"); //Czyszczenie ekranu
	int wybor;
	cout << "Wybierz figure." << endl;
	cout << "\t1. Kwadrat." << endl;
	cout << "\t2. Prostokat." << endl;
	cout << "\t3. Trojkat." << endl;
	cout << "\t4. Rab." << endl;
	cout << "\t5. Prostopadloscian." << endl;
	cin >> wybor;

	double a, b, c;
	switch (wybor)
	{
	case 1:
		cout << "Podaj a:" << endl;
		cin >> a;
		cout << "Pole to: " << LiczProstokat(a, a);
		break;
	case 2:
		cout << "Podaj a:" << endl;
		cin >> a;

		cout << "Podaj b:" << endl;
		cin >> b;

		cout << "Pole to: " << LiczProstokat(a, b);
		break;
	case 3:
		cout << "Podaj a:" << endl;
		cin >> a;

		cout << "Podaj h:" << endl;
		cin >> b;

		cout << "Pole to: " << LiczTrojkat(a, b);

		break;
	case 4:
		cout << "Podaj a:" << endl;
		cin >> a;

		cout << "Podaj h:" << endl;
		cin >> b;

		cout << "Pole to: " << LiczProstokat(a, b);

		break;
	case 5:
		cout << "Podaj a:" << endl;
		cin >> a;

		cout << "Podaj b:" << endl;
		cin >> b;
		cout << "Podaj c:" << endl;
		cin >> c;

		cout << "Pole to: " << LiczProstopadloscian(a, b, c);

		break;
	default:
		break;
	}




}

double zad4::LiczProstokat(double a, double b)
{
	return a*b;
}
double zad4::LiczTrojkat(double a, double h)
{
	return 0.5*a*h;
}
double zad4::LiczProstopadloscian(double a, double b, double c)
{
	return (a*b * 2 + a*c * 2 + b*c * 2);
}


double zad4::Ciag(double a0, int ile)
{
	double zwrot = a0;

	for (int k = 0; k < ile; k++)
	{
		zwrot = 0.8 * zwrot + k - 3.5;

	}



	return zwrot;
}

bool zad4::LiczbaPierwsza(int liczba)
{

	for (int k = 2; k < liczba; k++)
	{
		if (liczba%k == 0)
			return false;

	}
	return true;

}

int zad4::sumacyfr(int liczba)
{
	int zwrot = 0;

	while (liczba > 0)
	{
		zwrot += liczba % 10;
		liczba = liczba / 10;
	}
	return zwrot;
}

void zad4::ZadPrzedzialy(int poczatek, int koniec)
{
	if (koniec < poczatek)
	{
		int tymczas = poczatek;
		poczatek = koniec;
		koniec = tymczas;
	}

	cout << "\n\nLiczby parzyste: " << endl;
	for (int k = poczatek; k <= koniec; k++)
	{
		if (k % 2 == 0)
			cout << "\t" << k;
	}
	int prog;
	cout << "Podaj prog :" << endl;
	cin >> prog;

	cout << "\n\nSuma cyfr mniejszych niz " << prog << " : " << endl;
	for (int k = poczatek; k <= koniec; k++)
	{
		if (sumacyfr(k) <= prog)
			cout << "\t" << k;
	}


}

double zad4::potegowanie(int liczna, int potega)
{
	double zwrot = 1;
	for (int k = 0; k < potega; k++)
	{
		zwrot = zwrot * liczna;

	}
	return zwrot;
}


double zad4::dodawanie(double a, double b)
{
	return a + b;
}
double zad4::odejmowanie(double a, double b)
{

	return a - b;
}
double zad4::mnozenie(double a, double b)
{
	return a*b;
}
double zad4::dzielenie(double a, double b)
{
	return a / b;
}
int zad4::modulo(int a, int b)
{
	return a%b;
}
