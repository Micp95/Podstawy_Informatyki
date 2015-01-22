#include <iostream>
#include "spis.h"


using namespace std;

int main()
{

<<<<<<< HEAD
	int numer_cwiczen = 11;
=======
	int numer_cwiczen = 9;
>>>>>>> parent of 98fbc80... Revert "Podstawy"


	int zwrot = 0;


	switch (numer_cwiczen)
	{
	case 1:
		zwrot = zadanie1();
		break;
	case 2:
		zwrot = zadanie2();
		break;
	case 3:
		zwrot = zadanie3();
		break;
	case 4:
		zwrot = zadanie4();
		break;
	case 5:
		zwrot = zadanie5();
		break;
	case 6:
		zwrot = zadanie6();
		break;
	case 7:
		zwrot = zadanie7();
		break;
	case 8:
		zwrot = zadanie8();
		break;
	case 9:
		zwrot = zadanie9();
		break;
<<<<<<< HEAD
	case 10:
		zwrot = zadanie10();
		break;
	case 11:
		zwrot = zadanie11();
		break;
=======
>>>>>>> parent of 98fbc80... Revert "Podstawy"
	default:
		cout << "\n\nBrak podanego pliku æwiczeniowego!" << endl;
		break;
	}

	if (zwrot != 0)
		cout << "\n\n-------------\n\nBlad wykonywania zadania. Kod b³êdu to:\t" << zwrot;
	


	system("pause");
	return 0;
}


#include <iostream>
using namespace std;

int main2()
{
	int n;
	int m;
	int t;
	cout << "podaj rozmiar jednowymierowej tablicy" << endl;
	cin >> n;
	cout << "podaj wysokosc dwuwymiarowej" << endl;
	cin >> m;
	cout << "podaj szerokosc dwuwymiarowej" << endl;
	cin >> t;
	int* tab = new int[n];
	for (int i = 0; i<n; i++)
	{
		tab[i] = 0;
		cout << tab[i] << endl;
	}
	int** tab1 = new int*[m];
	for (int r = 0; r<m; r++)
		tab1[r] = new int[t];
	for (int j = 0; j<m; j++)
	{
		for (int k = 0; k < t; k++)
		{
			tab1[j][k] = 0;
			cout << tab1[j][k] << endl;
		}
	}

	return 0;
}