/*
Link do treœci zadañ: http://home.agh.edu.pl/~gsmyk/www/materials/PI/zajecia7.pdf

Uwaga!
G³ówn¹ funkcj¹ jest zawsze "int zadanieX ()". Jeœli chcesz skompilowaæ u siebie ca³oœæ musisz mieæ dodatkowo maina, gdzie j¹ wywo³as,
albo po prostu zmienisz jej nazwê na int main (). :)
Dodatkowo ka¿de æwiczenia posiadaj¹ swoj¹ przestrzeñ nazw zadX.

Pozadrawiam MicP :).
*/

#include <iostream>
#include <string>
#include <fstream>

#include <cstdlib>
#include <ctime>
#include <time.h>


#include "windows.h" 

using namespace std;

namespace zad7
{
	int Cwiczenie1(int argc, char* argv []);


	int Cwiczenie2(int argc, char* argv[]);
	void Kasuj(int ** wskaznik, int ilosc, int argument);


	int Cwiczenie3(int argc, char* argv[]);
	void wyswietl(int** tablica, int rozmiar);
	void Zamien(int** tablica, int rozmiar);


	void Cwiczenie4();

	int start();
	int Menu();
	void WyswietlPlansze();
	char pozycje[9];

	void VGracz();
	void VKomputer();
	void KomputerVKomputer();

	bool ruch(int pole, char gracz);
	bool testpola(int pole, char gracz);
	char TestWygranej();

	void RuchKomputera(char znak, int zaczyna);
	void RuchKomputeraLosowy (char znak);
	void RuchGracz(char znak);

	int* WczytanaBaza;
	int* WczytanaBazaP;
	int RWczytanejBazy;

	void Zapis(int liczba, int liczba2);
	void Wczytywanie();
	void DopiszWynik(int rozwiazanie, int dwa);

	int ruchy1;
	int ruchy2;

	int dlugosc(int liczba);
	int potega(int liczba, int ile);
	int ktory_ruch;

	bool SprawdzenieRuchu(int ruch_1, int ruch_2);
	int priorytet(char znak);

}


using namespace zad7;

char zad7::TestWygranej()
{



	char nowa[3][3];
	int tymczas = 0;

	for (int k = 0; k < 3; k++)
	{
		for (int p = 0; p < 3; p++)
		{
			nowa[k][p] = pozycje[tymczas++];
		}
	}

	for (int k = 0; k < 3; k++)
	{
		if ((nowa[k][0] == nowa[k][1]) && (nowa[k][1] == nowa[k][2]))
		{
			if (nowa[k][0] != ' ')
				return nowa[k][0];
		}
	}

	for (int k = 0; k < 3; k++)
	{
		if ((nowa[0][k] == nowa[1][k]) && (nowa[0][k] == nowa[2][k]))
		{
			if (nowa[0][k] != ' ')
				return nowa[0][k];
		}
	}

	if ((nowa[0][0] == nowa[1][1]) && (nowa[1][1] == nowa[2][2]))
		if (nowa[1][1] != ' ')
		return nowa[1][1];

	if ((nowa[0][2] == nowa[1][1]) && (nowa[1][1] == nowa[2][0] ))
		if (nowa[1][1] != ' ')
			return nowa[1][1];

	bool czy_remis = true;
	for (int k = 0; k < 9; k ++)
		if (pozycje[k] == ' ')
		{
			czy_remis = false;
			break;
		}
	if (czy_remis == true)
		return 'R';

	return ' ';
}

void zad7::VGracz()
{
	char test = ' ';
	do
	{
	//	system("cls");
	//	WyswietlPlansze();
		cout << "Ruch Gracza X." << endl;
		RuchGracz('X');

		test = TestWygranej();

		if (test != ' ')
			break;
		else
		{
			cout << "Ruch Gracza O." << endl;
			RuchGracz('O');

			test = TestWygranej();
		}

	} while (test == ' ');

	cout << "\n\nKoniec.\n";
	if (test == 'R')
		cout << "Remis\n"<<endl;
	else
		cout << "Wygral gracz: " << test << "!" << endl;

	string testcos;
	cin >> testcos;
}

void zad7::RuchGracz(char znak)
{
	bool blad = false;
	int wybor;

	//system("cls");
	WyswietlPlansze();

	do
	{
		if (blad == true)
		{
			system("cls");
			WyswietlPlansze();
		}

		cout << "\n\nWybierz pole: ";
		blad = false;
		cin >> wybor;
		
		if (cin.fail())
		{
			blad = true;
			cin.clear(cin.rdstate() & ~(ios::failbit | ios::eofbit));
			string slowo;
			cin >> slowo;
		}
		else if (wybor < 1 && wybor > 9)
			blad = true;

		
		if (ruch(wybor, znak) == true)
			blad = false;
		else
			blad = true;
		

	} while (blad);

	if (ruchy2 == 0)
		ruchy2 = wybor;
	else
		ruchy2 = ruchy2 * 10 + wybor;

//	system("cls");
	WyswietlPlansze();
}

void zad7::RuchKomputeraLosowy(char znak)
{
	bool udany_ruch = false;
	int losowa;
	do
	{
		udany_ruch = false;

		losowa = (rand() % 9 ) + 1;

		udany_ruch = ruch(losowa, znak);

	} while (!udany_ruch);

	if (ruchy2 == 0)
		ruchy2 = losowa;
	else
		ruchy2 = ruchy2 * 10 + losowa;

}

int zad7::dlugosc(int liczba)
{
	int zwrot = 0;
	while (liczba > 0)
	{
		liczba = liczba / 10;
		zwrot++;
	}
	return zwrot;
}
int zad7::potega(int liczba, int ile)
{
	ile--;
	int zwrot = 1;
	for (int k = 0; k < ile; k++)
	{
		zwrot = zwrot*liczba;
	}
	return zwrot;
}


int zad7::priorytet(char znak)
{
	char nowa[3][3];
	int tymczas = 0;

	for (int k = 0; k < 3; k++)
	{
		for (int p = 0; p < 3; p++)
		{
			nowa[k][p] = pozycje[tymczas++];
		}
	}

	for (int k = 0; k < 3; k++)
	{
		if ((nowa[k][0] == nowa[k][1]) && (nowa[k][0] == znak) && (nowa[k][2] == ' '))
		{
			return k*3 + 2;
		}

		if ((nowa[k][1] == nowa[k][2]) && (nowa[k][1] == znak) && (nowa[k][0] == ' '))
		{
			return k * 3 + 0;
		}

		if ((nowa[k][0] == nowa[k][2]) && (nowa[k][0] == znak) && (nowa[k][1] == ' '))
		{
			return k * 3 + 1;
		}
	}

	for (int k = 0; k < 3; k++)
	{
		if ((nowa[0][k] == nowa[1][k]) && (nowa[0][k] == znak) && (nowa[2][k] == ' '))
		{
			return 2 * 3 + k;
		}

		if ((nowa[1][k] == nowa[2][k]) && (nowa[1][k] == znak) && (nowa[0][k] == ' '))
		{
			return 0 * 3 + k;
		}

		if ((nowa[0][k] == nowa[2][k]) && (nowa[0][k] == znak) && (nowa[1][k] == ' '))
		{
			return 1 * 3 + k;
		}
	}

	if ((nowa[0][0] == nowa[1][1]) && (nowa[1][1] == znak  && (nowa[2][2] == ' ')))
		return 2 * 3 + 2;
	if ((nowa[0][0] == nowa[2][2]) && (nowa[0][0] == znak) && (nowa[1][1] == ' '))
		return 1 * 3 + 1;
	if ((nowa[2][2] == nowa[1][1]) && (nowa[1][1] == znak) && (nowa[0][0] == ' '))
		return 0;


	if ((nowa[0][2] == nowa[1][1]) && (nowa[1][1] == znak && (nowa[2][0] == ' ')))
		return 2 * 3 ;
	if ((nowa[1][1] == nowa[2][0]) && (nowa[2][0] == znak) && (nowa[0][2] == ' '))
		return 0 * 3 + 2;
	if ((nowa[0][2] == nowa[2][0]) && (nowa[2][0] == znak) && (nowa[1][1] == ' '))
		return 1 * 3 + 1;

	return -1;

}

void zad7::RuchKomputera(char znak, int zaczyna = 1)
{
	cout << "1" << endl;

	char przeciwnik;
	if (znak == 'X')
		przeciwnik = 'O';
	else
		przeciwnik = 'X';

	int potencjalne_pole = priorytet(znak);
	if (potencjalne_pole != -1)
	{
		ruch(potencjalne_pole+1, znak);
		ruchy1 = ruchy1 * 10 + potencjalne_pole;
		ktory_ruch++;
		//cout << "Ruch konczacy: " << potencjalne_pole+1 << endl;
		return;
	}

	potencjalne_pole = priorytet(przeciwnik);
	if (potencjalne_pole != -1)
	{
		ruch(potencjalne_pole+1, znak);
		ruchy1 = ruchy1 * 10 + potencjalne_pole;
		ktory_ruch++;
	//	cout << "Ruch blokujacy: " << potencjalne_pole+1 << endl;

		return;
	}
	cout << "2" << endl;


	int wybrany_algorytm = 10;
	int dlugosc_algorytmu = 10;

	bool udany_ruch = false;
	if (ktory_ruch == 0)
	{
		int losowa;
		do
		{
			udany_ruch = false;
			losowa = (rand() % 9) + 1;
			udany_ruch = ruch(losowa, znak);

		} while (!udany_ruch);
		ruchy1 = losowa;
	//	cout << "Ruch losowy (poczatek): " << losowa << endl;

	}
	else
	{
		for (int k = 0; k < RWczytanejBazy; k++)
		{

			int algorytm = WczytanaBaza[k];
			int algorytm2 = WczytanaBazaP[k];


			if (dlugosc(algorytm) < (ktory_ruch+1))
				continue;

			bool test = true;
			for (int p = 0; p < ktory_ruch; p++)
			{
				if ((algorytm / potega(10, dlugosc(algorytm) - p) == (ruchy1 / potega(10, dlugosc(ruchy1) - p))))
				{
					if ((algorytm2 / potega(10, dlugosc(algorytm2) - p) == (ruchy2 / potega(10, dlugosc(ruchy2) - p - zaczyna))))
					{
				if (test != false )
				cout << endl << "    test_dobry : " << algorytm << " " << algorytm2 << " | " << (algorytm / potega(10, dlugosc(algorytm) - p)) << " " << (ruchy1 / potega(10, dlugosc(ruchy1) - p)) << " || " << (algorytm2 / potega(10, dlugosc(algorytm2) - p)) << "  " << ((ruchy2 / potega(10, dlugosc(ruchy2) - p - 2))) <<"  r "<<ruchy2 << endl;
						test = false ;
						break;
					}
				}
			}

			if (test == true)
			{

				//	cout << "git  "<<algorytm <<endl;
				if (testpola(algorytm / potega(10, dlugosc(algorytm) - ktory_ruch),znak ) )
				{
					//udany_ruch = true;
					//ruchy1 = ruchy1 * 10 + (algorytm / potega(10, dlugosc(algorytm) - ktory_ruch));
					if (dlugosc_algorytmu > dlugosc(algorytm))
					{
						wybrany_algorytm = (algorytm / potega(10, dlugosc(algorytm) - ktory_ruch));
						dlugosc_algorytmu = dlugosc(algorytm);
						cout << endl << " d : " << wybrany_algorytm << "  " << dlugosc_algorytmu << "  " << algorytm << " " << algorytm2 << " | " << (algorytm / potega(10, dlugosc(algorytm) - ktory_ruch)) << endl;
					}

				//	break;
				}
			}
		}

		if (wybrany_algorytm == 10)
		{
			int losowa;
			do
			{
				udany_ruch = false;
				losowa = (rand() % 9) + 1;
				udany_ruch = ruch(losowa, znak);

			} while (!udany_ruch);
			ruchy1 = ruchy1 * 10+ losowa;
		//	cout << "Ruch losowy (brak algorytmu): " << losowa << endl;

			//cout << "3 " << wybrany_algorytm << endl;

		}
		else
		{
			ruch(wybrany_algorytm, znak);
			ruchy1 = ruchy1 * 10 + wybrany_algorytm;
		//	cout << "Ruch z algorytmu: " << wybrany_algorytm << endl;
//	cout << "4 " <<wybrany_algorytm << endl;

		}

	}


	ktory_ruch++;
}

bool zad7::SprawdzenieRuchu(int ruch_1, int ruch_2)
{
	for (int k = 0; k < RWczytanejBazy; k++)
	{
		if (WczytanaBaza[k] == ruch_1 && WczytanaBazaP[k] == ruch_2)
		{
			return false;
		}
	}
	return true;
}

void zad7::DopiszWynik(int rozwiazanie, int dwa)
{
	Zapis(rozwiazanie,dwa);
	int* tymczas = new int[RWczytanejBazy+1];
	int* tymczas2 = new int[RWczytanejBazy + 1];

	for (int k = 0; k < RWczytanejBazy; k++)
	{
		tymczas[k] = WczytanaBaza[k];
		tymczas2[k] = WczytanaBazaP[k];

	}
	tymczas[RWczytanejBazy] = rozwiazanie;

	RWczytanejBazy++;
	delete WczytanaBaza;
	delete WczytanaBazaP;


	WczytanaBaza = new int[RWczytanejBazy];
	WczytanaBazaP = new int[RWczytanejBazy];


	for (int k = 0; k < RWczytanejBazy; k++)
	{
		WczytanaBaza[k] = tymczas[k];
		WczytanaBazaP[k] = tymczas2[k];

	}
	delete tymczas;
	delete tymczas2;

}

void zad7::Wczytywanie() {


	ifstream analiza("baza.txt", ios::in);
	analiza.seekg(0);

	int tymczas = 0;
	string tekst = "pusto";


	RWczytanejBazy = 0;

	//Liczenie danych!
	while (true ) 
	{
		analiza >> tymczas;
		analiza >> tymczas;

		RWczytanejBazy++;

		if (!analiza && analiza.eof())
			break;
	}
	//analiza.close();

	RWczytanejBazy--;
	WczytanaBaza = new int[RWczytanejBazy];
	WczytanaBazaP = new int[RWczytanejBazy];



//	analiza = ifstream("baza.txt", ios::in);
	if ( !analiza )
		analiza.clear(cin.rdstate() & ~(ios::failbit | ios::eofbit));
	analiza.seekg(0);
	int k = 0;
	for (int k = 0; k < RWczytanejBazy; k++)
	{

		analiza >> tymczas;
		WczytanaBaza[k] = tymczas;


		analiza >> tymczas;
		WczytanaBazaP[k] = tymczas;

	}
	/*
	while (true)
	{

		if (!analiza && analiza.eof())
			break;
	}
	*/
	analiza.close();
}

void zad7::Zapis(int liczba, int liczba2)
{
	ofstream analiza("baza.txt", ios::out | ios::app);

	if (!analiza)
		cout << "\n\nBlad strumienia !" << endl;

	analiza << liczba <<" " <<liczba2 << " ";

	analiza.close();


}


void zad7::KomputerVKomputer()
{
	char test = ' ';

	do
	{
		RuchKomputera('X');
		//system("cls");
	//	WyswietlPlansze();
	//	cout << "\n\n";
		//Sleep(1000);
		test = TestWygranej();
		if (test != ' ')
			break;


		RuchKomputeraLosowy('O');
		//RuchKomputera('O');
		test = TestWygranej();

		//system("cls");
		//WyswietlPlansze();
		//Sleep(1000);

	} while (test == ' ');

	if (test == 'X')
		if (SprawdzenieRuchu(ruchy1,ruchy2))
			DopiszWynik(ruchy1,ruchy2);

	if (test == 'O')
		if (SprawdzenieRuchu(ruchy2,ruchy1))
			DopiszWynik(ruchy2,ruchy1);


}

void zad7::VKomputer()
{
	char test = ' ';

	do
	{
		cout << "\n\n--Komputerpro-- " << endl;
		RuchKomputera('X');
		test = TestWygranej();
		if (test != ' ')
			break;

		cout << "Ruch Gracza O." << endl;
		RuchGracz('O');

		test = TestWygranej();

	} while (test == ' ');

	if (test == 'X')
		if (SprawdzenieRuchu(ruchy1,ruchy2))
			DopiszWynik(ruchy1,ruchy2);

	system("cls");
	WyswietlPlansze();

	cout << "\n\nKoniec.\n";
	if (test == 'R')
		cout << "Remis\n" << endl;
	else
		cout << "Wygral gracz: " << test << "!" << endl;

	string testcos;
	cin >> testcos;

}

bool zad7::testpola(int pole, char gracz)
{
	pole++;
	if (pole > 9 || pole < 0)
		return false;

	if (pozycje[pole] == ' ' && pozycje[pole] != gracz)
		return true;
	else
		return false;

}

bool zad7::ruch(int pole, char gracz)
{
	pole--;

	if (pole > 9 || pole < 0)
		return false;

	if (pozycje[pole] == ' ')
	{
		pozycje[pole] = gracz;
		return true;
	}
	else
		return false;
}

int zad7::start()
{

	int wybor = Menu();

	ruchy1 = 0;
	ruchy2 = 0;
	ktory_ruch = 0;
	Wczytywanie();

	if (wybor != 3)
	{
		for (int k = 0; k < 9; k++)
		{
			pozycje[k] = ' ';

		}
		WyswietlPlansze();
	}

	return wybor;
}
/*
1. PvP
2. PvC
3. Exit
4. KvK
*/
int zad7::Menu()
{
	bool blad = false;
	int wybor;

	do
	{
		blad = false;
		system("cls");
		cout << "Menu!\n" << endl
			<< "1. Gracz vs Gracz." << endl
			<< "2. Gracz vs Komputer." << endl
			<< "3. Wyjscie z gry." << endl<<endl
			<< "4. Komputer vs Komputer" <<endl;
		cin >> wybor;
		if (cin.fail())
		{
			blad = true;
			cin.clear(cin.rdstate() & ~(ios::failbit | ios::eofbit));
			string slowo;
			cin >> slowo;
		}
		else if (wybor < 1 && wybor > 4 )
			blad = true;


	} while (blad);

	system("cls");

	return wybor;
}

void zad7::WyswietlPlansze()
{
	int ktore_pole = 0;
	for (int k = 0; k < 5;k++)
	{
		if (k % 2 == 0)
		{
			for (int p = 0; p < 5;p++)
			{
				if (p % 2 == 0)
					cout << pozycje[ktore_pole++];
				else
					cout << "|";
			}

		}
		else
		{
			for (int k = 0; k < 5; k++)
				cout << "-";

		}
		cout << endl;
	}
	cout << endl;
}

//Kolko i krzyzyk !
void zad7::Cwiczenie4()
{
	bool koniec = false;
	string smiec;
	do
	{
		int wybor = start();
		int ilosc = 0;
		switch (wybor)
		{
		case 1:
			VGracz();
			break;
		case 2:
			VKomputer();
			break;
		case 3:
			koniec = true;
			break;
		case 4:
			cout << "Podaj liczbe powtorzen: ";
			cin >> ilosc;

			while (ilosc>0)
			{
				ruchy1 = 0;
				ruchy2 = 0;
				ktory_ruch = 0;

				for (int k = 0; k < 9; k++)
				{
					pozycje[k] = ' ';

				}
				
			//	cout << "\n\n\n\nNowa kolejka !!\n\n";
				KomputerVKomputer();
				ilosc--;
				cout << ilosc <<endl;
			//	cin >> smiec;
			}
			break;
		default:
			break;
		}


	} while (!koniec);




}




int zadanie7()
{
	char *parametry[3];
	parametry[0] = "Program";
	parametry[1] = "Michal";
	parametry[2] = "Pozarlik";

	//Cwiczenie1(3,parametry);

	parametry[0] = "Program";
	parametry[1] = "5";
	parametry[2] = "4";
//	Cwiczenie2(3, parametry);

	//Cwiczenie3(2, parametry);

	Cwiczenie4();

	return 0;
}

bool dsdtest()
{
	bool test = 1;
	return 2;
}



int zad7::Cwiczenie1(int argc, char* argv[])
{

	if (argc != 1)
	{
		cout << "Witam Pana!" << endl;

		cout << "Imie: " << argv[1] << endl;
		cout << "Nazwisko: " << argv[2] << endl;


	}
	else
		cout << "Brak odpowiedniej ilosci argumentow!" << endl;


	return 0;
}


void zad7::Kasuj(int ** wskaznik, int ilosc, int argument)
{

	for (int k = 0; k < ilosc; k++)
	{
		for (int p = 0; p < ilosc; p++)
		{
			if (wskaznik[k][p] % argument == 0)
			{
				wskaznik[k][p] = 0;
			}
		}
	}
}

int zad7::Cwiczenie2(int argc, char* argv[])
{

	if (argc != 1)
	{
		int a = atoi(argv[1]);

		int ** tablica = new int*[a];
		for (int k = 0; k < a; k++)
			tablica[k] = new int[a];

		for (int k = 0; k < a; k++)
		{
			for (int p = 0; p < a; p++)
			{
				tablica[k][p] = (rand() % 1000) + 1;
			}
		}

		Kasuj(tablica, a, atoi(argv[2]));
	}
	else
		cout << "Brak odpowiedniej ilosci argumentow!" << endl;


	return 0;
}


void zad7::wyswietl(int** tablica, int rozmiar)
{
	cout << "Tablica: \n\n";
	for (int k = 0; k < rozmiar; k++)
	{
		for (int p = 0; p < rozmiar; p++)
		{
			cout << tablica[k][p] << "\t";
		}
		cout << endl;
	}

}

void zad7::Zamien(int** tablica, int rozmiar)
{
	int ** nowa = new int*[rozmiar];
	for (int k = 0; k < rozmiar; k++)
		nowa[k] = new int[rozmiar];

	for (int k = 0; k < rozmiar; k++)
	{
		for (int p = 0; p < rozmiar; p++)
		{
			nowa[k][p] = tablica[p][k];
		}
	}
	wyswietl(nowa, rozmiar);
}

int zad7::Cwiczenie3(int argc, char* argv[])
{

	if (argc != 1)
	{
		int a = atoi(argv[1]);

		int ** tablica = new int*[a];
		for (int k = 0; k < a; k++)
			tablica[k] = new int[a];

		for (int k = 0; k < a; k++)
		{
			for (int p = 0; p < a; p++)
			{
				if (p > k)
					tablica[k][p] = 0;
				else
					tablica[k][p] = (rand() % 100);

			}
		}
		
		wyswietl(tablica, a);
		Zamien(tablica, a);

	}
	else
		cout << "Brak odpowiedniej ilosci argumentow!" << endl;


	return 0;
}