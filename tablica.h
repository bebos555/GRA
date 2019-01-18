#ifndef tablica_hpp
#define tablica_hpp

#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <iomanip>


using namespace std;
void tablica_wynikow();

class Wynik {
public:
	
	//Overloaded Constructor:
	Wynik(string, int);

	
	
	string getNick();

	int getPunkty();






	string nick;
	
	int punkty;
};
//bool sortbyPunkty(Wynik &lhs, Wynik &rhs);

#endif 