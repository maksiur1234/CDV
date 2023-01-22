#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

void wyswietlSamochody(string nazwaPliku);
void dopiszSamochod(string nazwaPliku);

void menu()
{
	int wybor = 1;
	while(wybor != 0)
	{
		//Menu wyboru
		cout << "0. koniec\n";
		cout << "1. wyswietl samochody z pliku.\n ";
        cout << "2. dopisz samochod.\n ";
        cout << "3. usun samochod\n";
        cout << "4. nowy plik\n";
        cout << "5. wyszukaj wg marki samochodu\n";
        cout << "wybierz pozycje z menu:";
        cin >> wybor;
		switch(wybor)
		{
		//w zaleznosci od wyboru wywolaj funkcje
			case 1:	
				break;
			case 2:
				wyswietlSamochody("samochody.csv");
					break;
			case 3:
				dopiszSamochod("samochody.csv");
					break;
//			case 4:
//				usunSamochod("samochody.csv");
//			case 5:
//				wyszukajWgMarki("samochody.csv");
		}	
	}
}

int main()
{
	setlocale(LC_CTYPE, "Polish");
	menu();
}


void wyswietlSamochody(string nazwaPliku)
{
;
}

void dopiszSamochod(string NazwaPliku)
{
	string koniec = "t";
	string marka, model;
	int poj;
	cout << "Podaj marke: " << endl;
	cin >> marka;
	cout << "Podaj model: " << endl;
	cin >> model;
	cout << "Podaj pojemnosc: " << endl;
	cin >> poj;
	
	fstream plik;
	plik.open("samochody.csv", ios::out | ios::app);
	cout << "Chcesz dodac wiecej samochodow? t/n";

	
	plik.close();
}