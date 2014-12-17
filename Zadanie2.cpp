/*
Link do treœci zadañ: http://home.agh.edu.pl/~gsmyk/www/materials/PI/zajecia2.pdf

Uwaga!
G³ówn¹ funkcj¹ jest zawsze "int zadanieX ()". Jeœli chcesz skompilowaæ u siebie ca³oœæ musisz mieæ dodatkowo maina, gdzie j¹ wywo³as,
albo po prostu zmienisz jej nazwê na int main (). :)
Dodatkowo ka¿de æwiczenia posiadaj¹ swoj¹ przestrzeñ nazw zadX.

Pozadrawiam MicP :).
*/

#include <iostream>

using namespace std;

namespace zad2
{
	bool czy_sie_miesci(double liczba);
	void wypisywanie_ciogu();
	void ciag_Fibonacciego(int wyraz);

	void Rysowanie();


}
using namespace zad2;

int zadanie2()
{

	int liczba;

	cout << "Podaj liczne, ktora chcesz sprawdzic." << endl;
	cin >> liczba;

	bool sprawdz = czy_sie_miesci(liczba);
	if (sprawdz == true)
		cout << "Podana liczba miesci sie w przedziale." << endl;
	else
		cout << "Podana liczba nie miesci sie w przedziale." << endl;

	wypisywanie_ciogu();


	cout << "Podaj ostatni wyraz ciagu Fibonacciego:" << endl;
	cin >> liczba;
	ciag_Fibonacciego( liczba);

	Rysowanie();


	return 0;
}
bool zad2::czy_sie_miesci(double liczba)
{
	if (liczba >= 7 && liczba <= 50)
		return true;

	return false;

}

void zad2::wypisywanie_ciogu()
{
	int ilosc_elementow = 20;
	double element_ciagu = 0;
	double suma = 0;
	double iloczyn = 1;
	double min = 0;
	double max = 0;


	cout << "\n\nWypisywanie petla For:" << endl;
	for (int k = 0; k < ilosc_elementow; k++)
	{
		if (k != 0)
			element_ciagu = element_ciagu*(-3.5) - 12;
		else
		{
			element_ciagu = 0;
			max = min = element_ciagu;
		}
		suma += element_ciagu;
		iloczyn *= element_ciagu;

		if (element_ciagu > max)
			max = element_ciagu;

		if (element_ciagu < min)
			min = element_ciagu;

		cout << "\tElement " << k << ".\t : " << element_ciagu << endl;
	}


	cout << "\n\nWypisywanie petla While:" << endl;
	int ktory_element=0;
	element_ciagu = 1;
	while (ktory_element < ilosc_elementow)
	{
		if (ktory_element != 0)
			element_ciagu = element_ciagu*(-3.5) - 12;
		else
			element_ciagu = 0;

		cout << "\tElement " << ktory_element << ".\t : " << element_ciagu << endl;

		ktory_element++;
	}

	cout << "\n\nWypisywanie petla While:" << endl;
	ktory_element = 0;
	element_ciagu = 1;
	do 
	{
		if (ktory_element != 0)
			element_ciagu = element_ciagu*(-3.5) - 12;
		else
			element_ciagu = 0;

		cout << "\tElement " << ktory_element << ".\t : " << element_ciagu << endl;
		ktory_element++;

	} while (ktory_element < ilosc_elementow);
	

	cout << "\n\nSuma ciagu to: " << suma << endl
		<< "Iloczyn to: " << iloczyn << endl
		<< "Maksymalna wartosc ciagu to: " << max << endl
		<< "Minimalna wartosc cigu to: " << min << endl;

}

void zad2::ciag_Fibonacciego(int wyraz)
{
	int wyraz_a = 0;
	int wyraz_b = 1;
	int wyraz_tymczas;

	cout << "Wyraz 0.\tto: 0"<<endl;
	if (wyraz == 0)
	{
		return;
	}

	for (int k = 1; k <= wyraz; k++)
	{
		wyraz_tymczas = wyraz_a;
		wyraz_b = wyraz_a + wyraz_b;
		wyraz_a = wyraz_b - wyraz_tymczas;

		cout << "Wyraz " << k << ".\tto: " << wyraz_a << endl;

	}


}

void zad2::Rysowanie()
{
	cout << "Podaj wielkosc figur:" << endl;
	int wysokosc;
	cin >> wysokosc;
	
	cout << "\n\n---KWADRAT--\n";
	for (int k = 0; k < wysokosc; k++)
	{
		for (int k = 0; k < wysokosc; k++)
			cout << "*";
		cout << endl;
	}

	cout << "\n\n---TROJKAT 1--\n";
	for (int k = 1; k < wysokosc+1; k++)
	{
		for (int p = 0; p < k; p++)
			cout << "*";
		cout << endl;
	}


	cout << "\n\n---TROJKAT 2--\n";
	int biale_znaki = wysokosc - 1;
	for (int k = 1; k < wysokosc + 1; k++)
	{
		for (int p = 0; p < biale_znaki; p++)
			cout << " ";
		biale_znaki--;
		for (int p = 0; p < 2 * k - 1; p++)
		{
			if (k == 0)
			{
				cout << "*";
				break;
			}
			else if ( k == wysokosc)
				cout << "*";
			else if ( p == 0 || p == 2*k-2)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}

	cout << "\n\n---TROJKAT 3--\n";
	 biale_znaki = wysokosc - 1;
	for (int k = 1; k < wysokosc + 1; k++)
	{
		for (int p = 0; p < biale_znaki; p++)
			cout << " ";
		biale_znaki--;
		for (int p = 0; p < 2 * k - 1; p++)
		{
				cout << "*";

		}
		cout << endl;
	}

}

