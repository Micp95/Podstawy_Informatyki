
#include <iostream>
#include<fstream>
#include<string>

using namespace std;

namespace zad10
{
	void cwiczenie1();
	struct Student
	{
		string imie, nazwisko, kierunek;
		int rok;
		string plik_nazwa;
		void Zapisz(string nazwa_pliku);
		void WczytajWyswielt();
	};

	void cwiczenie3();
	void cwiczenie4();
	void cwiczenie5();
	void cwiczenie6();
	void cwiczenie7();
}


using namespace zad10;

int zadanie10()
{
	cwiczenie1();


	cwiczenie3();
	cwiczenie4();
	cwiczenie5();
	cwiczenie6();
	cwiczenie7();



	return 0;
}


void zad10::Student::WczytajWyswielt()
{
	fstream plik(plik_nazwa, ios::out | ios::in);
	string *linijki = new string[4];
	for (int k = 0; k < 4; k++)
		linijki[k] = "";

	if (plik.good())
	{
		string wiersz;

		for (int k = 0; k < 4; k++)
		{
			if (!plik.eof())
			{
				getline(plik, wiersz);
				linijki[k] = wiersz;
			}
			else
				break;
		}

	}
	else
	{
		cout << "Blad wczytywania pliku!"<<endl;
	}
	plik.close();


	cout << "Imie: " << linijki[0]<<endl;
	cout << "Nazwisko: " << linijki[1]<<endl;
	cout << "Kierunek: " << linijki[2]<<endl;
	cout << "Ro: " << linijki[3]<<endl;
}

void zad10::Student::Zapisz(string nazwa_pliku)
{
	fstream plik(nazwa_pliku, ios::out);
	if (plik.good())
	{
		plik << imie << endl;
		plik << nazwisko << endl;
		plik << kierunek << endl;
		plik << rok << endl;
		plik.flush();
		
		plik_nazwa = nazwa_pliku;
	}
	else
	{
		cout << "Blad strumienia!" << endl;
	}
	plik.close();
}

void zad10::cwiczenie1()
{
	Student ktos;
	ktos.imie = "Jan";
	ktos.nazwisko = "Kowalski";
	ktos.kierunek = "IS";
	ktos.rok = 1;
	ktos.Zapisz("dane.txt");
	ktos.WczytajWyswielt();

}

void zad10::cwiczenie3()
{
	fstream plik("text.txt", ios::out | ios::in);

	int ilosc_znakow = 0;
	if (plik.good())
	{
		string wiersz;

		char tymczas;

		while (true )
		{
			if (!plik.eof())
			{
				plik >> tymczas;
				ilosc_znakow++;
			}
			else
				break;
		}
		ilosc_znakow--;

	}
	else
	{
		cout << "Blad wczytywania pliku!" << endl;
	}
	plik.close();

	cout << "Ilosc znakow w pliku to: " << ilosc_znakow << endl;

}

void zad10::cwiczenie4()
{
	fstream plik("text.txt", ios::out | ios::in);

	int ilosc_znakow = 0;
	if (plik.good())
	{
		string wiersz;

		string tymczas;

		while (true)
		{
			if (!plik.eof())
			{
				plik >> tymczas;
				ilosc_znakow++;
			}
			else
				break;
		}

	}
	else
	{
		cout << "Blad wczytywania pliku!" << endl;
	}
	plik.close();

	cout << "Ilosc slow w pliku to: " << ilosc_znakow << endl;

}

void zad10::cwiczenie5()
{
	fstream plik("napis.txt", ios::out | ios::in);

	int ilosc_zdan = 0;
	if (plik.good())
	{
		string wiersz;

		string tymczas;
		string tymczas_slowo;

		while (true)
		{

			if (!plik.eof())
			{
				ilosc_zdan++;
			}
			else
				break;
			

			getline(plik, tymczas,'.');
		}

	}
	else
	{
		cout << "Blad wczytywania pliku!" << endl;
	}
	plik.close();

	cout << "Plik zawiera " << ilosc_zdan << " zdan." << endl;

}

void zad10::cwiczenie6()
{
	fstream plik("napis.txt", ios::out | ios::in);

	int najdluzsze = 0;
	if (plik.good())
	{
		string wiersz;

		string tymczas;
		string tymczas_slowo;

		while (true)
		{

			if (plik.eof())
			{
				break;

			}


			getline(plik, tymczas, '.');

			int aktualne_zdanie = 0;
			for (int k = 0; k <tymczas.size(); k++)
			{

				if (tymczas[k] == ' ')
					aktualne_zdanie++;

			}
			if (aktualne_zdanie > najdluzsze)
				najdluzsze = aktualne_zdanie;
		}

	}
	else
	{
		cout << "Blad wczytywania pliku!" << endl;
	}
	plik.close();

	cout << "Najdluzsze zdanie w pliku ma: " << najdluzsze << " wyrazow." << endl;

}

void zad10::cwiczenie7()
{
	fstream plik("napis.txt", ios::out | ios::in);

	int ilosc_zdan = 0;
	if (plik.good())
	{
		string wiersz;

		string tymczas;
		string tymczas_slowo;

		while (true)
		{
			if (!plik.eof())
			{
				ilosc_zdan++;
			}
			else
				break;
			getline(plik, tymczas, '.');
		}

		plik.seekg(0);
		while (true)
		{
			getline(plik, tymczas, '!');
			if (!plik.eof())
			{
				ilosc_zdan++;
			}
			else
				break;
		}

		plik.seekg(0);
		while (true)
		{
			getline(plik, tymczas, '?');
			if (!plik.eof())
			{
				ilosc_zdan++;
			}
			else
				break;
		}
	}
	else
	{
		cout << "Blad wczytywania pliku!" << endl;
	}
	plik.close();

	cout << "Plik zawiera " << ilosc_zdan << " zdan." << endl;

}