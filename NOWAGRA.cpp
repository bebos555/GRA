#include "NOWAGRA.hpp"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <string>
#include <fstream>

using namespace std;

int sila_wiatru(int o);
int kat_rzutu(int p);
float zasieg(int sila, float kat, int wiatr);
float zamiana_stopni_na_radiany(int stopnie);
int odleglosc_kosza(int u);
int predkosc_rzutu(int k);
void grafika_kosza(int o, int r);
float wynik(float e, int r, int t);





int GRA(string nick,int poziom) {
	

	float k_rzutu_radiany = 0;  //zmienne do ktorych zostana wczytane parametry obliczone w funkcjach
	int s_wiatru, o_kosza,r_kosza=5, p_rzutu = 0, k_rzutu_stopnie = 0;


	//Wywolanie funkcji obliczajacej sile wiatru i przekazanie do zmiennej
	s_wiatru = sila_wiatru(poziom);

	cout << "sila wiatru wynosi: " << s_wiatru << endl;
	cout << endl;

	Sleep(2000);

	//losowanie odleglosci rzutu
	o_kosza = odleglosc_kosza(0);
	cout << "Odleglosc rzutu to: " << o_kosza << endl;

	cout << endl; cout << endl; cout << endl; cout << endl;
	

	Sleep(1000);
	//Wstawianie grafiki kosza
	grafika_kosza(o_kosza,r_kosza);

	cout << endl; cout << endl; cout << endl; cout << endl;

	Sleep(1000);


	//Wywolanie funkcji i przypisanie predkosci rzutu do zmiennej
	cout << "PRZYTRZYMAJ KLAWISZ ABY ZADAC PREDKOSC" << endl << endl;
	p_rzutu = predkosc_rzutu(0);
	cout << "Predkosc pilki: " << p_rzutu;

	cout << endl;
	cout << endl;
	Sleep(1000);

	cout << "PRZYTRZYMAJ KLAWISZ ABY USTALIC KAT RZUTU" << endl << endl;
	//Wywolanie funkcji i przypisanie kata (w stopniach) rzutu do zmiennej
	k_rzutu_stopnie = kat_rzutu(0);


	//Zamiana na radiany
	k_rzutu_radiany = zamiana_stopni_na_radiany(k_rzutu_stopnie);


	cout << endl;
	cout << "kat rzutu w stopniach: " << k_rzutu_stopnie << endl;
	cout << endl;
	
	Sleep(1000);


	//obliczanie zasiegu rzutu - przekazanie parametrow rzutu do funkcji
	
	float z = 0;
	z= zasieg(p_rzutu, k_rzutu_radiany, s_wiatru);
	cout << "Pilka wyrzucona na odleglosc: ";
	printf("%2.1f", z);
	cout << endl; cout << endl;


	
	

	//ilsoc zdobytych punktow
	float z_punkty= wynik(z, o_kosza, r_kosza);

	//zwraca ilosc punktow do zapisu
	return z_punkty;
	
}







//funkcja sprawdza warunek wygranej i zwraca ilosc zdobytych punktow
float wynik(float e, int r, int t) {

	//e - zasieg pilki
	//r - odleglosc do kosza
	//t - szerokosc kosza


	if (e > (r + t)) {
		cout << "Za daleko"<<endl;
		return 0;
	}

	else if (e < r) {
		cout << "Za blisko" << endl;
		return 0;
	}
	

	else if ((e >= r) && (e <= r + t)) {
		cout << "Trafione!"<<endl;
		return r; //zdobyte punkty to odleglosc do kosza
	}
}

void grafika_kosza (int o, int r) {

	//Grafika przedstawiajaca odleglosc do kosza
	char zasieg_max[50];

	//Wpisanie na pocz¹tku tablicy X (ludzik)
	zasieg_max[0] = 'X';

	//Wypelnienie tablicy "grunetem"
	for (int i = 1; i < 50; i++) {
		zasieg_max[i] = '_';
	}

	//Wpisanie do tablicy symbolu kosza
	//Tworzenie rozmiaru kosza
	

	for (int k = 1; k <= r; k++) {
		zasieg_max[o + k] = 'V';
	}


	//Wyswietlanie grafiki kosza
	cout << "   		";
	for (int p = 0; p < 50; p++) {
		cout << zasieg_max[p];
	}

}


//losowanie odleglosci do kosza
int odleglosc_kosza(int u) {

	//odleglosc do kosza ma przyjmowac wartosci od 1 do 40
	int odleglosc = rand() % 39 + 1;

	return odleglosc;

}

//losowanie si³y i kierunku wiatru
int sila_wiatru(int o ) {
	if (o == 0) return 0; //jezeli poziom trudnosci wynosi 1 to wiatr wybosi 0

	else {
		//losowanie kierunku wiatru
		srand(time(NULL));
		int k = rand() % 3 - 1;
		int kierunek = 0;
		if (((k == 1) || (k == -1))) kierunek = k;
		else kierunek = -1;


		
		//losowanie sily wiatru w zaleznosci od poziomu trudnosci (5 lub 20)
		int sila = rand() % o;

		
		return sila * kierunek;
	}
}


//funkcja do konwersji stopni na radiany
float zamiana_stopni_na_radiany(int stopnie) {

	const float Pi = (float)3.14;
	float radiany = (stopnie * Pi) / 180;
	return radiany;
}



float zasieg(int predkosc, float kat, int wiatr) {
	//wzor na rzut poziomy
	float z = (float)(pow((predkosc + wiatr), 2) *sin(2 * kat) / 9.81);
	return z;
}


//Predkosc pilki zadana przez uzytkownika
int predkosc_rzutu(int k) {

	cout << "MAX		||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "PREDKOSC	";
	char znak;
	znak = _getch();
	int licznik = 0;



	while ((znak = _getch()) & (licznik <= 89)) {
		licznik++;
		cout << "|";
		Sleep(50);

		if (_kbhit() == true) continue;
		else break;

	}
	cout << endl;
	cout << endl;
	return licznik;
}



//KAT RZUTU zadany przez uzytkownika
int kat_rzutu(int p) {

	cout << "MAX		||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl;
	cout << "KAT		";

	char znak;
	znak = _getch();
	int licznik2 = 0;


	while ((znak = _getch()) & (licznik2 <= 89)) {
		licznik2++;

		cout << "|";
		Sleep(50);

		if (_kbhit() == true) continue;
		else break;
	}

	cout << endl;
	

	//Wartosc zadana przez uzytkownika jest w stopniach
	//wiec trzeba ja przeliczyc na radiany 


	return licznik2;
}