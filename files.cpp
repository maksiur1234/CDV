#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

struct samochod
{
    string model = "", marka = "";
    int pojSilnika = 0;
}s1;

void czytajPlik(string nazwaPliku);//czyta z pliku i dodaje samochody do vectora autka
void dopiszSamochod(string nazwaPliku);//dodaje samochód do vectora i do pliku
void pokazSamochody(string nazwaPliku);//wyświetla samochody z pliku (z vectora)

samochod samochodZLinii(string linia);
void usunSamochod(string nazwaPliku);
void wyszukajWgMarki(string nazwaPliku);//wyświetla samochody wg marki
bool fileexists(string nazwaPliku);  //sparwdza czy istniej w bieżącym katalogu plik 
string liniaZSAmochodu(samochod s);//tworzy zmienną string na podstawie zmiennej typu samochod

samochod wczytajSamochod();//


void menu()
{
    int wybor = 1;
    while (wybor != 0)
    {
        cout << "0. koniec\n";
        cout << "1. dopisz samochód.\n ";
        cout << "2. wyświetl samochody z pliku.\n ";
        cout << "3. usuń samochód\n";
        cout << "4. nowy plik\n";
        cout << "5. wyszukaj wg marki samochodu\n";
        cout << "wybierz pozycję z menu:";
        cin >> wybor;
        switch (wybor)
        {
        case 0: break;
        case 1: dopiszSamochod("autka.csv"); break;
        case 2: pokazSamochody("autka.csv"); break;
        case 3: usunSamochod("autka.csv"); break;
        case 4:  break;
        case 5: wyszukajWgMarki("autka.csv"); break;
        }
    }
}


vector<samochod> autka;  //deklaracja vectora
int main()
{
    setlocale(LC_CTYPE, "Polish");
    menu();
}
samochod wczytajSamochod()//
{
    samochod sam1;
    cout << "podaj markę samochodu: "; cin >> sam1.marka;
    cout << "podaj model samochodu: "; cin >> sam1.model;
    cout << "podaj pojemność silnika: "; cin >> sam1.pojSilnika;
    return sam1;
}
samochod samochodZLinii(string linia)
{
    //samochod s1;
    string str;
    int ind;
    ind=linia.find(";");
    s1.marka = linia.substr(0, ind);
    linia = linia.substr(ind+1, linia.length() - 1);
    ind = linia.find(";");
    s1.model = linia.substr(0, ind);
    linia = linia.substr(ind + 1, linia.length() - 1);
    s1.pojSilnika= stoi(linia);
    
    return s1;
}
void czytajPlik(string nazwaPliku)//
{
    //odczyt z pliku
    int i = 0;
    fstream plik2;
    string linia;
    plik2.open(nazwaPliku, ios::in);  //otworzenie pliku w trybie odczytu
    if (plik2.good()) //jeśli plik został otwraty poprawnie
    {
        getline(plik2, linia);
        cout << linia << endl;
        while (!plik2.eof())
        {
            getline(plik2, linia);
            if (linia.length() > 4)
                autka.push_back(samochodZLinii(linia));//dodanie do vectora zmiennej typu samochod

        }
    }
    else
    {
        cout << "nie można otworzyc pliku!";
    }
}
void pokazSamochody(string nazwaPliku)  //wyświetla samochody 
{
    czytajPlik(nazwaPliku);//czyta z pliku do vectora autka
    for (int i = 0; i < autka.size(); i++)//wyświetla samochody z vectora
    {
        liniaZSAmochodu(autka[i]);
    }
}
void dopiszSamochod(string nazwaPliku)
{
    samochod autko; //deklaracja zmiennej typu strukturalnego samochod
    string koniec = "t";
    //zapis do pliku
    fstream plik;
    if (!fileexists(nazwaPliku))
        plik << "marka;model;pojemność silnika\n"; //zapisanie wiersza nagłówkowego    plik << "marka;model;pojemność silnika\n"; //zapisanie wiersza nagłówkowego
    //plik.open("samochod2.txt", ios::out) //tworzy nowy plik, jeśli istnieje o tej nazwie to nadpisuje
    plik.open(nazwaPliku, ios::out | ios::app); ////tworzy nowy plik, jeśli istnieje o tej nazwie to dopisuje do pliku
    
    while (koniec == "t")
    {
        autko = wczytajSamochod();
        autka.push_back(autko);
        plik << autko.marka << ";" << autko.model << ";" << autko.pojSilnika << endl;
        cout << "czy wprowadzić kolejny samochód ? t/n";
        cin >> koniec;
    }
    plik.close();

}
string liniaZSAmochodu(samochod s)
{
    string str = s.marka + ";" + s.model + ";" + to_string(s.pojSilnika);
    return str;
}
void wyszukajWgMarki(string nazwaPliku)
{
    czytajPlik(nazwaPliku);//czyta z pliku do vectora autka
    string nazwa;
    cout << "jakiej marki samochody wyświetlić ?";
    cin >> nazwa;
    for (int i = 0; i < autka.size();i++)  //przeglądanie vectora autka
    {
        if(autka[i].marka==nazwa)
        cout << (i + 1) << ". " << liniaZSAmochodu(autka[i]) << endl;
    }
    
}
void usunSamochod(string nazwaPliku)
{
    pokazSamochody(nazwaPliku);
    //autka.erase(autka.begin() + 4);
}
bool fileexists(string nazwaPliku)  //sparwdza czy istniej w bieżącym katalogu plik 
{
    fstream plik2;
    string linia;
    plik2.open(nazwaPliku, ios::in);  //otworzenie pliku w trybie odczytu
    if (plik2.good())
    {
        plik2.close();
        return true;
    }
    else
        return false;
}