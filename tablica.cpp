#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <vector>
#include "tablica.h"
#include <algorithm>
#include <iomanip>

using namespace std;


// metoda na tworzenie obiektu klasy
Wynik::Wynik(string xnick,  int xpunkty) {
	nick = xnick;
	punkty = xpunkty;
	}


//Metody na odczyt danych obiektu
string Wynik::getNick()  {
	return nick;
}


int Wynik::getPunkty() {
	return punkty;
}


// Sort Container by punkty 
bool sortbyPunkty( Wynik &lhs,  Wynik &rhs) { 
	return lhs.punkty > rhs.punkty;
}

//wyswietlanie kontenera
void showVec(vector<Wynik>& xlista) {

	unsigned int vecSize = xlista.size();

	for (unsigned int i = 0; i+1 < vecSize; i++) {

		cout << setw(15)<<xlista[i].getNick()<< setw(25) << xlista[i].getPunkty();
		cout << endl;
		
		
		

	}

}







void tablica_wynikow() {

	fstream plik;

	plik.open("wyniki.txt",ios::in);

	if (plik.good() == false) {
		cout << "plik nie istnieje. Zamykam program";
		Sleep(2000);
		exit(0);
	}
	
	vector <Wynik> lista;
	
	while (true) //petla odczytujaca plik i wczytujaca dane do kontenera lista
	{

		string a; //nick wczytywany z pliku
		int b; // punkty uzytkownika wczytane z pliku
		
		plik >> a >> b;
	
		
		Wynik newWynik(a, b); //tworzenie obiektu Wynik i powiekszenie kontenera
		lista.push_back( newWynik);
	
	
		
		if (!plik.fail());


		else
			break; //zakoñcz wczytywanie danych - wyst¹pi³ jakiœ b³¹d (np. nie ma wiêcej danych w pliku)
		
	} 
	sort(lista.begin(), lista.end(), sortbyPunkty);
	showVec(lista); //wyswietlenie kontenera

	_getch();


}

