/*
Link do treœci zadañ: http://home.agh.edu.pl/~gsmyk/www/materials/PI/zajecia8.pdf

Uwaga!
G³ówn¹ funkcj¹ jest zawsze "int zadanieX ()". Jeœli chcesz skompilowaæ u siebie ca³oœæ musisz mieæ dodatkowo maina, gdzie j¹ wywo³as,
albo po prostu zmienisz jej nazwê na int main (). :)
Dodatkowo ka¿de æwiczenia posiadaj¹ swoj¹ przestrzeñ nazw zadX.

Pozadrawiam MicP :).
*/

#include <iostream>

using namespace std;

namespace zad8
{
	struct Student
	{
		char* imie;
		char* nazwisko;
		char* kierunek;
		char* wydzial;
		void wypisz()
		{
			cout << "Imie:\t" << imie << endl
				<< "Nazwisko:\t" << nazwisko << endl
				<< "Kierunek:\t" << kierunek << endl
				<< "Wydzial:\t" << wydzial << endl;

		}

	};

	struct Okrag
	{
		double x;
		double y;

		double r;

		double Obwod();
		void Rownanie();

	};

	struct Prostokat
	{
		double x;
		double y;
	};

	struct Zespolone
	{
		double re, im;
	};

	struct Prosta
	{
		double A, B, C;
	};

	void Cwiczenie5();

	template <class jakis_typ, class typ2 >
	void Kalkulator(jakis_typ a, typ2 b, int dzialanie);


	Zespolone operator+(Zespolone a, Zespolone b);


	template < class typ1>
	Zespolone operator+(Zespolone a, typ1 b);

	template < class typ1>
	Zespolone operator+(typ1 a, Zespolone b);



	Zespolone operator-(Zespolone a, Zespolone b);
	template < class typ1>
	Zespolone operator-(Zespolone a, typ1 b);

	template < class typ1>
	Zespolone operator-(typ1 a, Zespolone b);

	Zespolone operator*(Zespolone a, Zespolone b);
	template < class typ1>
	Zespolone operator*(Zespolone a, typ1 b);

	template < class typ1>
	Zespolone operator*(typ1 a, Zespolone b);

	Zespolone operator/(Zespolone a, Zespolone b);
	template < class typ1>
	Zespolone operator/(Zespolone a, typ1 b);

	template < class typ1>
	Zespolone operator/(typ1 a, Zespolone b);

	ostream & operator<<(ostream & ekran, Zespolone & zesp);

	template<class jakis_typ>
	void Wyswietl(jakis_typ figura);

	void Cwiczenie4();

	int Cwiczenie1(int argc, char* argv[]);
	void Cwiczenie2();

	void BadajOkregi(Okrag okrag1, Okrag okrag2);

	void BadajProsta(Prosta prost, Okrag okra);
	
}


using namespace zad8;

int zadanie8()
{
	char *parametry[5];
	parametry[0] = "Program";
	parametry[1] = "Michal";
	parametry[2] = "Pozarlik";
	parametry[3] = "IS";
	parametry[4] = "WIMiIP";

	//Cwiczenie1(5,parametry);
	//Cwiczenie2();// 2, 3 i 6
	//Cwiczenie4();
	Cwiczenie5();

	return 0;
}

void zad8::BadajProsta(Prosta prost, Okrag okra)
{
	double modul = prost.A*okra.x + prost.B * okra.y + prost.C;
	if (modul < 0)
		modul = -modul;

	double odleglosc = modul / sqrt(prost.A *prost.A + prost.B*prost.B);

	if (odleglosc > okra.r)
		cout << "Prosta nie ma punktow wspolnych z okregiem." << endl;
	else if (odleglosc < okra.r)
		cout << "Prosta ma 2 punkty styczne z okregiem." << endl;
	else if (odleglosc == okra.r)
		cout << "Prosta ma 1 punkt styczny z okregiem." << endl;


}


void zad8::Cwiczenie5()
{
	Zespolone a;
	a.im = 2;
	a.re = 3;
	Zespolone b;
	b.im = -1;
	b.re = 4;
	
	Kalkulator(a, 1.2 ,1);

	for (int k = 1; k < 6; k++)
	{
		Kalkulator(a, b, k);
		Kalkulator(6, 2, k);
		Kalkulator(8.0, 3.0, k);

		cout << endl;
	}
}
ostream & zad8::operator<<(ostream & ekran, Zespolone & zesp)
{
	ekran << zesp.re;
	ekran << " + " << zesp.im;
	ekran << "i";

	return ekran;

}

template < class typ1>
Zespolone zad8::operator+(Zespolone a, typ1 b)
{
	Zespolone zwrot;
	zwrot.im = a.im;
	zwrot.re = a.re + b;
	return zwrot;

}

template < class typ1>
Zespolone zad8::operator+(typ1 a, Zespolone b)
{
	Zespolone zwrot;
	zwrot.im = b.im;
	zwrot.re = b.re + a;

	return zwrot;
}
Zespolone zad8::operator+(Zespolone a, Zespolone b)
{
	Zespolone zwrot;



		zwrot.im = a.im + b.im;
		zwrot.re = a.re + b.re;

	return zwrot;
}



template < class typ1>
Zespolone zad8::operator-(Zespolone a, typ1 b)
{
	Zespolone zwrot;
	zwrot.im = a.im;
	zwrot.re = a.re - b;
	return zwrot;

}

template < class typ1>
Zespolone zad8::operator-(typ1 a, Zespolone b)
{
	Zespolone zwrot;
	zwrot.im = b.im;
	zwrot.re = b.re - a;

	return zwrot;

}



template < class typ1>
Zespolone zad8::operator*(Zespolone a, typ1 b)
{
	Zespolone zwrot;
	zwrot.im = a.im;
	zwrot.re = a.re * b;
	return zwrot;

}

template < class typ1>
Zespolone zad8::operator*(typ1 a, Zespolone b)
{
	Zespolone zwrot;
	zwrot.im = b.im;
	zwrot.re = b.re * a;

	return zwrot;

}



template < class typ1>
Zespolone zad8::operator/(Zespolone a, typ1 b)
{
	Zespolone zwrot;
	zwrot.im = a.im;
	zwrot.re = a.re / b;
	return zwrot;

}

template < class typ1>
Zespolone zad8::operator/(typ1 a, Zespolone b)
{
	Zespolone zwrot;
	zwrot.im = b.im;
	zwrot.re = b.re / a;

	return zwrot;

}


Zespolone zad8::operator-(Zespolone a, Zespolone b)
{
	Zespolone zwrot;
	zwrot.im = a.im - b.im;
	zwrot.re = a.re - b.re;

	return zwrot;
}
Zespolone zad8::operator*(Zespolone a, Zespolone b)
{
	Zespolone zwrot;
	zwrot.im = a.im * b.im - a.re * b.re;
	zwrot.re = a.re *b.im + a.im *b.re;

	return zwrot;

}
Zespolone zad8::operator/(Zespolone a, Zespolone b)
{
	Zespolone zwrot;
	double mianownik = b.re*b.re - b.im*b.im;

	zwrot.re = (a.re *b.re - a.im*b.im) / mianownik;
	zwrot.im = (a.im *b.re - a.re*b.im) / mianownik;

	return zwrot;
}


template <class jakis_typ, class typ2 >
void zad8::Kalkulator(jakis_typ a, typ2 b, int dzialanie)
{
	switch (dzialanie)
	{
	case 1:
		cout << a << " + " << b << " = " << a + b<<endl;
		break;
	case 2:
		cout << a << " - " << b << " = " << a - b<<endl;
		break;
	case 3:
		cout << a << " * " << b << " = " << a * b << endl;
		break;
	case 4:
		cout << a << " / " << b << " = " << a / b << endl;
		break;
	default:
		break;
	}

}

void zad8::Cwiczenie4(){
	Prostokat nowy;
	nowy.x = 4;
	nowy.y = 2;

	Wyswietl(nowy);

}

template<class jakis_typ>
void zad8::Wyswietl(jakis_typ figura)
{
	cout << "Obwod:\t" << 2 * figura.x + 2 * figura.y<<endl;
	cout << "Pole:\t" << figura.x*figura.y << endl;
}

void zad8::Cwiczenie2()
{
	Okrag A;
	A.x = 1;
	A.y = 2;
	A.r = 3;

	Okrag B;
	B.x = -1;
	B.y = 0;
	B.r = 2;

	Prosta C;
	C.A = 1;
	C.B = 2;
	C.C = 5;

	BadajOkregi(A, B);
	BadajProsta(C, A);
	BadajProsta(C, B);
}

void zad8::BadajOkregi(Okrag okrag1, Okrag okrag2)
{
	double roznicax = okrag1.x - okrag2.x;
	double roznicay = okrag1.y - okrag2.y;

	double odleglosc = sqrt(roznicax * roznicax + roznicay*roznicay);

	double modul = okrag1.r - okrag2.r;
	if (modul < 0)
		modul = -modul;
	
	if (odleglosc > okrag1.r + okrag2.r)
	{
		cout << "Okregi rozdzielne."<<endl;
		return;
	}
	else if (odleglosc == okrag1.r + okrag2.r)
	{
		cout << "Okregi stycznie zewnetrznie." << endl;
		return;
	}	
	else if (odleglosc > modul && odleglosc < okrag1.r + okrag2.r)
	{
		cout << "Okregi przecinaja sie." << endl;
		return;
	}
	else if (odleglosc == modul )
	{
		cout << "Okregi styczne wewnetrznie." << endl;
		return;
	}
	else if (odleglosc < modul )
	{
		cout << "Okregi rozloczne wewnetrznie." << endl;
		return;
	}
	else if (roznicax == 0 && roznicay == 0)
	{
		cout << "Okregi wspolsrodkowe" << endl;

	}

}

double zad8::Okrag::Obwod()
{
	double pi = 3.14;

	return 2*pi*r;
}
void zad8::Okrag::Rownanie()
{
	cout << endl;
	cout << "(x - " << x << ")^2 + (y - " << y << ")^2 = " << r*r << endl;
}

int zad8::Cwiczenie1(int argc, char* argv[])
{
	Student ktos;
	if (argc > 4)
	{
		int kolejna = 1;
		ktos.imie = argv[kolejna++];

		ktos.nazwisko = argv[kolejna++];
		ktos.kierunek = argv[kolejna++];
		ktos.wydzial = argv[kolejna++];

	}

	ktos.wypisz();
	return 0;
}