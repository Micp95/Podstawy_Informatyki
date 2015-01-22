/*
Link do treœci zadañ: http://home.agh.edu.pl/~gsmyk/www/materials/PI/zajecia11.pdf

Uwaga!
G³ówn¹ funkcj¹ jest zawsze "int zadanieX ()". Jeœli chcesz skompilowaæ u siebie ca³oœæ musisz mieæ dodatkowo maina, gdzie j¹ wywo³as,
albo po prostu zmienisz jej nazwê na int main (). :)
Dodatkowo ka¿de æwiczenia posiadaj¹ swoj¹ przestrzeñ nazw zadX.

Pozadrawiam MicP :).
*/

#include <iostream>
#include <string>

using namespace std;

namespace zad9
{
	void cwiczenie1();
	bool CzySamogloska(string slowo);

	void cwiczenie2();
	int LiczSlowa(string tekst, string wzorzec);

	void cwiczenie3();
	struct User
	{
		string name;
		string password;
		int key;
		string notatka;
	};
	string Szyfruj(string tekst, int kod);
	string Odszyfruj(string tekst, int kod);

	void cwiczenie4();
	void Rejestracja(User* baza, int maks, int& aktualnie, int klucz);
	int Logowanie(int klucz, User* baza, int maks);


	string GeneratorHasla();

	char losujLiczbe();
	char LosujDuza();
	char LosujMala();
	void cwiczenie8();
}


using namespace zad9;

int zadanie9()
{
	cwiczenie4();


	return 0;
}

template <class a, class b>
a fun(b cos, int)
{
	a d;
	return d;
}




bool zad9::CzySamogloska(string slowo)
{
	char samogloski[] = {'a','A','e','E','i','I','o','O','u','U','y','Y'};

	for (int k = 0; k < 12; k++)
		if (slowo[0] == samogloski[k])
			return true;
	return false;
}

void zad9::cwiczenie1()
{
	string tablica[10];

	cout << "Podaj 10 wyrazow:" << endl;
	for (int k = 0; k < 10; k++)
	{
		cout << k + 1 << ". ";
		cin >> tablica[k];
		cout << endl;
	}
	int licznik = 1;
	cout << "\n\nZaczynajace sie od samoglosek:\n" << endl;
	for (int k = 0; k < 10; k++)
	{
		if (CzySamogloska(tablica[k])==true)
		{
			cout << licznik++ << ". " << tablica[k] << endl;

		}

	}

}


int zad9::LiczSlowa(string tekst, string wzorzec)
{
	int licznik = 0;
	int DlugoscTekst = tekst.length();
	int DlugoscWzorzec = wzorzec.length();


	for (int k = 0; k < DlugoscTekst; k++)
	{
		for (int p = 0; p < DlugoscWzorzec; p++)
		{
			if (tekst[k + p] == wzorzec[p])
			{
				if (p == DlugoscWzorzec - 1)
					licznik++;
			}
			else
				break;

		}

	}

	return licznik;
}

void zad9::cwiczenie2()
{
	string tekst, wzorzec;
	cout << "Podaj tekst." << endl;
	//cin >> tekst;
	getline(cin, tekst);
	cout << "Podaj czego szukasz" << endl;
	cin >> wzorzec;


	int licznik = 0;
	string::size_type pozycja = 0;
	int bload = 0;
	while (true)
	{

		pozycja = tekst.find(wzorzec, pozycja + bload);

		if (pozycja != string::npos)
		{
			licznik++;
			bload = 1;
		}
		else
			break;

	}
	int licznikFun = LiczSlowa(tekst, wzorzec);


	cout << "\n\nW podanym tekscie bylo: " << licznik << " wg. wbudowanej funkcji i " << licznikFun << " wg. autorskiej funkcji." << endl;

}

string zad9::Szyfruj(string tekst, int kod)
{
	int dlugosc = tekst.length();

	char litera;
	for (int k = 0; k < dlugosc; k++)
	{
		litera = tekst[k];
		if (litera + kod > 'z')
			litera = litera + kod - 26;
		else if (litera < 'a' && litera + kod > 'Z')
			litera = litera + kod - 26;
		else
			litera += kod;
		tekst[k] = litera;
	}

	return tekst;
}

string zad9::Odszyfruj(string tekst, int kod)
{
	int dlugosc = tekst.length();

	char litera;
	for (int k = 0; k < dlugosc; k++)
	{
		litera = tekst[k];
		if (litera + kod < 'a')
			litera = litera - kod + 26;
		else if (litera > 'Z' && litera + kod < 'a')
			litera = litera - kod + 26;
		else
			litera -= kod;
		tekst[k] = litera;
	}

	return tekst;
}

void zad9::cwiczenie3()
{
	string tekst = "Zbc";

	cout << Szyfruj(tekst,8)<<endl;
	cout << Odszyfruj(Szyfruj(tekst, 8),8);
}


void zad9::Rejestracja(User* baza, int maks, int& aktualnie, int klucz)
{
	baza[aktualnie].key = klucz;
	string nazwa, haslo;
	cout << "Podaj nazwe uzytkownika: " << endl;
	cin >> nazwa;
	cout << "Podaj haslo:" << endl;
	cin >> haslo;
	baza[aktualnie].name = nazwa;
	baza[aktualnie].password = Szyfruj(haslo, klucz);

	aktualnie++;
}
int zad9::Logowanie(int klucz, User* baza, int maks)
{
	string nazwa,  haslo;
	bool blad = true;
	int nie_udane = 3;
	int polozenie;
	do
	{
		if ( nie_udane < 1 )
		{ 
		
			blad = true;
			break;
		}

		system("cls");
		if (nie_udane != 3)
			cout <<"Podano zle haslo, lub zly login! "<< "(Pozostaly " << nie_udane << " proby logowania)" << endl;


		cout << "Podaj nazwe uzytkownika:" << endl;
		cin >> nazwa;
		cout << "Podaj haslo:" << endl;
		cin >> haslo;


		for (int k = 0; k < maks; k++)
		{
			if (nazwa == baza[k].name)
			{
				if (haslo == Odszyfruj(baza[k].password, baza[k].key))
				{
					polozenie = k;
					blad = false;
					break;
				}
				break;
			}
		}
		if (blad == false)
			break;

		nie_udane--;
		blad = true;
	} while (blad);


	if (blad == true)
		return -1;
	return polozenie;
}

void zad9::cwiczenie4()
{
	cout << "\n\n";
	cout << GeneratorHasla();
	cout << "\n\n";


	User* uzytkownicy = new User[10];
	int ilosc = 0;
	int maks = 10;

	int aktualny_klucz = 4;

	bool wyjscie = false;
	int wybor;
	bool test;
	string slowo;
	char enter;
	do
	{
		//system("cls");
		cout << "Wybierz dzialanie:" << endl
			<< "1. Utworz konto." << endl
			<< "2. Zaloguj sie na konto." << endl
			<< "3. Wyjscie." << endl;
		cin >> wybor;
		switch (wybor)
		{
		case 3:
			wyjscie = true;
			break;
		case 2:
			test = Logowanie(aktualny_klucz, uzytkownicy, maks);
			if (test != -1)
			{
				cout << "Logowanie pomyslne" << endl;

				cout << "\n\nTwoja notatka to:" << endl;
				cout << uzytkownicy[test].notatka;
				cout << "\n\nWpisz nowa notatke: " << endl;
			//	getline(cin, uzytkownicy[test].notatka);
				cin >> uzytkownicy[test].notatka;
			}
			else
				cout << "Blad logowania." << endl;
			cin >> slowo;
			break;
		case 1:
			Rejestracja(uzytkownicy, maks, ilosc, aktualny_klucz);
			break;
		default:
			break;
		}

	} while (!wyjscie);

}

char zad9::losujLiczbe()
{

	return rand()%10 +48;

}
char zad9::LosujDuza()
{

	return rand() % 25 + 65;

}

char zad9::LosujMala()
{
	return rand() % 25 + 97;
}

string zad9::GeneratorHasla()
{
	string haslo = "";
	int specjalne=0;
	for (int k = 0; k < 10; k++)
	{
		int wybor = rand() % 3;


		switch (wybor)
		{
		case 0:
			haslo += losujLiczbe();
			specjalne++;
			break;
		case 1:
			haslo += LosujDuza();
			break;
		case 2:
			haslo += LosujMala();
			break;
		default:
			break;
		}

		if (k > 6 && specjalne < 2)
		{
			haslo += losujLiczbe();
			specjalne++;
		}

	}


	return haslo;
}


void zad9::cwiczenie8()
{

	int rozmiar = 3;
	int * tablica = new int[rozmiar];
	//nuuuud
	for (int i = 0; i < rozmiar; i++)
		cout << tablica[i];
}
