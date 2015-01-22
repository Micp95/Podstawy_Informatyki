#include <iostream>
#include<fstream>
#include<string>


#include <cstdlib>
#include <ctime>
#include <time.h>


#include "windows.h" 

using namespace std;

namespace zad11
{
	class Plansza
	{
	public:
		Plansza();
		~Plansza();

		bool WczytajPlansze();
		bool Rysuj(int x, int y);
		string Wyswietl();

	private:
		string plansz;
	};

	void Rysuj();
	string ZakodowaneHaslo;
	string Haslo;

	string WybraneLitery;
	string WyswietlLitery(string znaki);
	string obrazek = "";

	int zycia = 2;

	int  SprawdzLitere(char litera);
	
	string WczytajObrazek(int ktory);

	void StartGry(string slowo);

	bool PrzebiegGry();
	int TestWygranej();

}

zad11::Plansza::Plansza()
{

}

zad11::Plansza::~Plansza()
{

}

bool zad11::Plansza::Rysuj(int x, int y)
{
	x--;
	y--;
	int wskaznik = 0;
	for (int k = 0; k <= y;k++ )
	{	
		if (k == x)
		{
			for (int p = 0; p <= x; p++)
			{
				if (p == x)
				{

				}


			}
		}
		while (plansz.size() != wskaznik)
		{
			if (plansz[wskaznik] == '\n')
			{
				wskaznik++;
				break;
			}

			wskaznik++;
		}

	}

	return false;
}
bool zad11::Plansza::WczytajPlansze()
{
	fstream plik("Plansza.txt", ios::out | ios::in);

	if (plik.good())
	{

		if (!plik.eof())
		{
			getline(plik, plansz,'|');
		}
		plik.close();
		return true;
	}
	else
	{
		cout << "Blad wczytywania pliku!" << endl;
		plik.close();
		plansz = "";
		return false;
	}

}
string zad11::Plansza::Wyswietl()
{
	return plansz;
}
void zad11::StartGry(string slowo)
{
	WybraneLitery = "";
	obrazek = "";
	Haslo = slowo;

	ZakodowaneHaslo = "";
	for (int k = 0; k < Haslo.size(); k++)
	{
		ZakodowaneHaslo += "_";
	}


}

int  zad11::SprawdzLitere(char litera)
{
	for (int k = 0; k < WybraneLitery.length(); k++)
	{
		if (WybraneLitery[k] == litera)
			return 1;
	}

	WybraneLitery += litera;
	for (int k = 0; k < Haslo.length(); k++)
	{
		if (Haslo[k] == litera)
		{

			string tymczas = "";
			for (int p = 0; p < Haslo.length(); p++)
			{
				if (Haslo[p] == litera)
				{
					tymczas += litera;
				}
				else
					tymczas += ZakodowaneHaslo[p];
			}
			ZakodowaneHaslo = tymczas;

			return 0;
		}
	}


	return 2;
}

string zad11::WyswietlLitery(string znaki)
{
	string tymczas = "";

	for (int k = 0; k < znaki.length(); k++)
	{
		tymczas += znaki[k];
		if (k != znaki.length()-1)
			tymczas += ", ";
	}

	return tymczas;
}

void zad11::Rysuj()
{
	system("cls");
	cout << "Gra wisielec!\n" << endl;

	cout << "\t\t" << ZakodowaneHaslo << endl << endl;
	cout << "\n\tUzyte litery: " << WyswietlLitery(WybraneLitery) << endl;
	cout << "\n\tZycia: " << zycia+1 << endl;

	cout << "\n\n"<<obrazek << endl;

}

int zad11::TestWygranej()
{

	if (zycia < 0)
		return 2;
	for (int k = 0; k < ZakodowaneHaslo.length(); k++)
	{
		if (ZakodowaneHaslo[k] == '_')
		{
			return 0;
		}
	}


	return 1;
}

bool zad11::PrzebiegGry()
{
	Rysuj();

	string WprowadzonaLitera;
	cout << "\nPodaj nowa litere: " << endl;
	cin >> WprowadzonaLitera;

	int test = SprawdzLitere(WprowadzonaLitera[0]);

	if (test == 1) // Wprowadzono 2 raz ten sam znak
	{
		cout << "Wprowadzono juz wybrany wczesniej znak!" << endl;
		Sleep(2000);
	}
	else if (test == 2)
	{
		cout << "Brak podanej litery w hasle!" << endl;
		zycia--;
		obrazek = WczytajObrazek(3 - zycia);
		Sleep(2000);
	}
	else
	{
		cout << "Gratulacje trafiles!" << endl;
		Sleep(2000);
	}

	int czywyg = TestWygranej();
	if (czywyg != 0)
	{
			Rysuj();
		if (czywyg == 1)
		{
			cout << "Wygrales!" << endl;
			cout << "Udalo Ci sie pokonac Orka, ocaliles caly Swiat!\n\n";
		}
		else if (czywyg == 2)
		{
			cout << "Przegrana!" << endl;
			cout << "Niestety Ork byl sprytniejszy od Ciebie, zostales powieszony!\n\n";
		}

		return true;
	}
	return false;
}

string zad11::WczytajObrazek(int ktory)
{
	ktory--;
	string nplik = "";
		nplik += (char)(ktory+48);
	nplik += ".txt";
	fstream plik(nplik, ios::out | ios::in);

	 string tymczas;
	if (plik.good())
	{

		if (!plik.eof())
		{
			getline(plik, tymczas, '$');
		}
		plik.close();

	}
	else
	{
		cout << "Blad wczytywania pliku!" << endl;

	}
	return tymczas;
}
using namespace zad11;



int zadanie11()
{
	/*
	
	while (!key[KEY_ESC])

	{
		klawisz = readkey();
		clear_to_color(screen, makecol(10, 10, 10));
		textprintf(screen, font, 20, 20, makecol(255, 255, 128), "Score : i+1");

		if (key[KEY_LEFT])
			if (key[KEY_RIGHT])
				if (key[KEY_UP])
					if (key[KEY_DOWN])
						klawisz = readkey();

		rectfill(screen, 90, 95, 80, 110, makecol(128, 30, 30));
	}


		int znak;
		znak = 0;
		while ((znak = getch()) != 27)  // wykonuj dopoki nie nacisnieto ESC
		{
			switch (znak)
			{
			case 77:   // w prawo
				
					break;
			case 75:   // w lewo
				
					break;
			case 72:   // do gory
				
					break;
			case 80:   // w dol
				
					break;
			}
		}
	*/


	cout << "Wedrowcze, spotkales na swojej drodze Orka, aby go pokonac musisz odgadnac jego haslo!\n\n";
	Sleep(5000);
	StartGry("test");
	while (!PrzebiegGry()){ }



	return 0;
}

