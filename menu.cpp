#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include "NOWAGRA.hpp"
#include <conio.h>
#include "tablica.h"
#include <string>



using namespace std;

void(zapis_wynikow)(string nick, float punkty);

int main() {

	char wybor = 0;
	float score1 = 0, score2=0;
	while (true) {
		cout << endl;
		cout << "------------------------------------------------------" << endl;
		cout << "1. NOWA GRA" << endl;
		cout << "2. DWOCH GRACZY" << endl;
		cout << "3. TABLICA WYNIKOW" << endl;
		cout << "4. WYJSCIE" << endl;
		
		cout << endl;
		wybor = _getch();
		Sleep(1000);

		switch (wybor) {
			
			//TRYB SINGLE PLAYER
		case '1': {
			//wczytanie nicku gracza
			string pseud;
			cout << endl;
			cout << "PODAJ SWOJ NICK:" << endl;
			cin>>pseud;

			char y = 0; //zmienna do wczytania poziomu trudnosci
			cout << "WYBIERZ POZIOM TRUDNOSCI:" << endl << endl;
			cout << "1. LAIK" << endl;
			cout << "2. KOSZYKASZ	(punkty razy 2)" << endl;
			cout << "3. ZAWODNIK NBA (punkty razy 5)" << endl;
			y = _getch();

			switch (y) {
			case '1': {
				cout << endl; cout << endl; cout << endl;
				Sleep(400);
				score1=GRA(pseud, 0);
				cout << endl << "ZDOBYLES " << score1 << " PUNKTOW" << endl;
				zapis_wynikow(pseud, score1);
				Sleep(3000);
			}
					break;
			case '2': {
				cout << endl; cout << endl; cout << endl;
				Sleep(400);
				score1=GRA(pseud, 5);
				cout << endl << "ZDOBYLES " << score1*2 << " PUNKTOW" << endl;
				zapis_wynikow(pseud, score1*2);
				Sleep(3000);
			}
					break;
			case '3': {
				cout << endl; cout << endl; cout << endl;
				Sleep(400);
				score1=GRA(pseud, 20);
				cout << endl << "ZDOBYLES " << score1*5 << " PUNKTOW" << endl;
				zapis_wynikow(pseud, score1*5);
				Sleep(3000);
			}
					break;
			default: {
				cout << "NIE MA TAKIEGO POZIOMU!";
				_getch(); }
			}
			_getch();
		}
				  break;
				  
			//MULTIPLAYER
		case '2': {
			//wczytanie nicku gracza1
			string pseud1, pseud2;
			cout << endl;
			cout << "PODAJ NICK PIERWSZEGO GRACZA:" << endl;
			cin >> pseud1;

			//wczytanie nicku gracza2
			cout << endl;
			cout << "PODAJ NICK DRUGIEGO GRACZA:" << endl;
			cin >> pseud2;
			cout << endl;


			char y = 0; //zmienna do wczytania poziomu trudnosci
			cout << "WYBIERZ POZIOM TRUDNOSCI:" << endl << endl;
			cout << "1. LAIK" << endl;
			cout << "2. KOSZYKASZ	(punkty razy 2)" << endl;
			cout << "3. ZAWODNIK NBA	(punkty razy 5)" << endl;
			y = _getch();

			switch (y) {
			case '1': {
				cout << endl; cout << endl; cout << endl;
				cout << "------------- GRACZ 1 ------------" << endl << endl; //uruchamia gre dla pierwszego gracza
				Sleep(400);
				
				score1 = GRA(pseud1, 0);
				cout << endl << endl << endl;
				_getch();
				cout << "------------- GRACZ 2 ------------" << endl << endl; //uruchamia gre dla drugiego gracza
				score2 = GRA(pseud2, 0);

				if (score1 > score2) { //jezeli pierwszy wygral
					zapis_wynikow(pseud1, score1);
					cout << pseud1 << " WYGRAL!" << endl;
					cout << endl << "ZDOBYLES " << score1 << " PUNKTOW" << endl;
				}

				if (score1 < score2) { //jezeli drugi wygral
					zapis_wynikow(pseud2, score2);
					cout << pseud2 << " WYGRAL!" << endl;
					cout << endl << "ZDOBYLES " << score2 << " PUNKTOW" << endl;
				}

				if (score1 == score2) { //jezeli remis

					zapis_wynikow(pseud1, score1);
					zapis_wynikow(pseud2, score2);
					cout << "REMIS" << endl;
					cout << endl << "ZDOBYLISCIE PO " << score1 << " PUNKTOW" << endl;
				}
			}

					  break;


			case '2': {
				cout << endl; cout << endl; cout << endl;
				cout << "------------- GRACZ 1 ------------" << endl << endl; //gra pierwszy gracz
				Sleep(400);

				score1 = GRA(pseud1, 5);
				cout << endl << endl << endl;
				_getch();
				cout << "------------- GRACZ 2 ------------" << endl << endl; //gra drugi gracz
				score2 = GRA(pseud2, 5);

				if (score1 > score2) {  //jezeli pierwszy wygral
					zapis_wynikow(pseud1, score1 * 2);
					cout << pseud1 << " WYGRAL!" << endl;  
					cout << endl << "ZDOBYLES " << score1 * 2 << " PUNKTOW" << endl;
				}

				if (score1 < score2) {   //jezeli drugi wygral
					zapis_wynikow(pseud2, score2 * 2);
					cout << pseud2 << " WYGRAL!" << endl;
					cout << endl << "ZDOBYLES " << score2 * 2 << " PUNKTOW" << endl;
				}

				if (score1 == score2) {  //jezeli remis

					zapis_wynikow(pseud1, score1 * 2);
					zapis_wynikow(pseud2, score2 * 2);
					cout << "REMIS" << endl;
					cout << endl << "ZDOBYLISCIE PO " << score1 * 2 << " PUNKTOW" << endl;
				}
			}

					  break;

					  //
			case '3': {
				cout << endl; cout << endl; cout << endl;
				cout << "------------- GRACZ 1 ------------" << endl << endl;		//gra pierwszy gracz
				Sleep(400);
				score1 = GRA(pseud1, 20);
				cout << endl << endl << endl;
				_getch();
				cout << "------------- GRACZ 2 ------------" << endl << endl;		//gra drugi gracz
				score2 = GRA(pseud2, 20);

				if (score1 > score2) {		//jezeli pierwszy wygral
					zapis_wynikow(pseud1, score1 * 5);
					cout << pseud1 << " WYGRAL!" << endl;
					cout << endl << "ZDOBYLES " << score1 * 5 << " PUNKTOW" << endl;
				}

				if (score1 < score2) {		//jezeli wygral drugi gracz
					zapis_wynikow(pseud2, score2 * 2);
					cout << pseud2 << " WYGRAL!" << endl;
					cout << endl << "ZDOBYLES " << score2 * 5 << " PUNKTOW" << endl;
				}

				if (score1 == score2) {			//remis

					zapis_wynikow(pseud1, score1 * 5);
					zapis_wynikow(pseud2, score2 * 5);
					cout << "REMIS" << endl;
					cout << endl << "ZDOBYLISCIE PO " << score1 * 5 << " PUNKTOW" << endl;
				}
			}
					  break;

			default: {
				cout << "NIE MA TAKIEGO POZIOMU!";
				_getch(); }
			}
			Sleep(3000); //czas na wyswietlenie wyniku
			_getch();
		}
				  break;

				  
			//TABLICA WYNIKOW
		case '3': {
			cout << endl;
			cout << "TABLICA WYNIKOW" << endl << endl;

			Sleep(1000);

			tablica_wynikow();
		}
				  break;

				  //WYJSCIE
		case '4': {
			cout << endl;
			cout << "WYCHODZE Z GRY";
			Sleep(2000);
			exit(0);
		}

		

		

		default: {
			cout << "NIE MA TAKIEJ OPCJI W MENU!";
			Sleep(2000); }
		}

		//czyszczenie ekranu
		system("cls");

	}
	return 0;
}

//zapis wynikow do pliku
void(zapis_wynikow)(string nick, float punkty) {
	fstream plik;

	plik.open("wyniki.txt", ios::out | ios::app);

	plik << nick << " " << punkty << endl;

	plik.close();

}
