#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <string>
#include <windows.h>
#include <fstream>
#include <chrono>
#include <cmath>
#include <sstream>
#include <stdlib.h>

#include "Pokret.h"
#include "Pobjednik.h"
#include "ShemaKocke.h"
#include "Kocka.h"
#include "RandomGenerisanje.h"
#include "SaveLoad.h"
#include "ScoreBoard.h"
#include "ScoreBoardIspis.h"
#include "ScoreBoardArcade.h"

using std::cout;
using std::cin;
using std::endl;


//Globalno
Kocka k; //Glavna kocka na koju ce korisnik utjecati
Kocka perfect;   //slozena kocka za usporedbu

Pokret korisnik;
RandomGenerisanje r;
Pokret igrac;
SaveLoad SpasiMe;
ShemaKocke prikaz;
Pobjednik p;
ScoreBoard Score;
ScoreBoardSort score1;
Arcade arkada;
ScoreBoardArcade sc;
std::chrono::time_point<std::chrono::system_clock> start, end;

bool check();   //Funkcija za provjeru da li je ostvarena slozena kocka
void help();    //Funkcija za pozivanje i ispis uputa
void credits(); //Funkcija za pozivanje i ispis zasluga

bool endgame;

Pokret* vrstaIgre; //Pokazivac za pozivanje virtuelne funckcije

int main() {

	int pokreti = 0;
	int choice = 0;
	std::string first;
	double T;
	double time;
	bool isUnos;
	std::chrono::duration<double> elapsed_seconds;

	//Generisanje random poslozene kocke
	k = r.generisiKocku();

	//Slaganje savrsene kocke
	perfect.setKocka();

	//Glavna do while petlja pokrece i trazi korisnikov izbor, jedino se prekida izlaskom iz igrice
	do {
		system("cls");
		prikaz.glavniMeni();
		//Ova petlja osigurava preciznost korisnikovog unosa, prekida se kada je validan izbor unesen
		do{
			cout << "\t\t  Input: ";
			cin >> first;
			isUnos = (first == "1") || (first == "2") || (first == "3") || (first == "4") || (first == "5") || (first == "6") || (first == "7") || (first == "8") || (first == "9");
			if (!isUnos) {
				cout << "\t\t\t\t\t  Whoops, wrong entry. Try again!" << endl;
			}
			cout << "\n\t\t\t\t";
		} while (!isUnos);

		//Unesen je string kako unos simbola koji nisu brojevi ne naprave glitch
		//Sada taj string konvertujemo u int kako bi se mogao iskoristiti preko switch-a
		std::stringstream digit(first);
		digit >> choice;

    cin.ignore();
	system("cls");

	//Odabir menija je predstavljen pomocu switch-a
	switch (choice) {

	//Izbor 1 = Glavni metod igranja
	case 1:
		k.meni = false;
		//Petlja koja poziva funckiju za okretanje redova ili kolona sve dok korisnik ne slozi kocku ili pozove glavni meni
		do {
			start = std::chrono::system_clock::now();
			prikaz.ispisSheme(k);

			k = igrac.pokret(k,k.pokreti);
			k.pokreti++;
			end = std::chrono::system_clock::now();
			std::chrono::duration<double> elapsed_seconds = end - start;
			T = (double)elapsed_seconds.count();

			k.time += T;

			if (k.meni) {
				k.meni = false;
				break;
			}

			endgame = check();
		} while (endgame != true);

		//Ako je korisnik uspjesno zavrsio kocku, poziva se Victory screen i upis na tabelu pobjednika
		if(endgame){
			system("cls");
		    p.ispisPobjednik();
			cin.ignore();
		    cin >> Score;
		    Score.setFinalTime(k.time);
		    Score.upisScoreboarda();
		    cout << Score;
		    cout << "\n\t\t\t\t\t    ";
		    system("pause");
		}
		break;

		//Izbor 2 je pozivanje spasene kocke koju imamo od prijasnjih sesija
	case 2:
		k = SpasiMe.Load();
		break;

		//Izbor 3 je spasavanje trenutacne kocke kako bi se moglo nastaviti igrati kasnije
	case 3:
		SpasiMe.Save(k);
		break;

		//Izbor 4 je pozivanje ispisa tabele pobjednika
	case 4:
		score1.ispisScoreBoard();
		cout << "\t\t\t\t\t  ";
		system("pause");
		break;

		//Izbor 5 je pozivanje ispisa uputa
	case 5:
		help();
		cout << "\t\t\t\t\t  ";
		system("pause");
		break;

		//Izbor 6 je pozivanje Arkade metode igranja preko pokazivaca za virtuelnu funkciju
	case 6:
		k = r.generisiKocku();

		vrstaIgre = &arkada;
		k.points = 0;
		k.pokreti = 0;

		//Korisnikovi pokreti se unose sve dok se ne slozi kocka ili korisnik napravi 20 pokreta
		do {
			prikaz.ispisSheme(k);
			k = vrstaIgre->pokret(k, k.pokreti);
			k.pokreti++;

			endgame = check();
			if(endgame){
				k.points += 500;
				break;
			}
		} while (k.pokreti < 20);

		if (k.pokreti >= 19) {
			system("cls");
			if(endgame){
				p.ispisPobjednik();
			}
			prikaz.changeColor(11);
			cout << "\n\t\t\t\t\t      Broj poena je " << k.points << "!" << endl;
			prikaz.changeColor(7);
			cout << "\n\t\t\t\t\t  ";
			std::cin.ignore();
			sc.setPoints(k.points);
			sc.upisScoreBoard();
			system("pause");
		}
		break;

		//Ispis tabele rezultata Arkade
	case 7:
		sc.ispisScoreBoard();
		std::cout << "\t\t\t\t\t       ";
		system("pause");
		break;

		//Ispis zasluga
	case 8:
		credits();
		cout << "\t\t\t\t  ";
		prikaz.changeColor(7);
		system("pause");
		break;

		//Izlazak iz igrice
	case 9:
		cout << " \n\n\n" << endl;
		prikaz.changeColor(10);
		cout << "\n\t\t\t\t  Thank you for playing!" << endl;
		prikaz.changeColor(7);
		cout << " \n\n\n\t\t\t        ";
		system("pause");
		exit(0);

		//Defaultni izbor u slucaju neocekivanog unosa
	default:
		cout << "\n\t\t\t\t\t  Choose one of the mentioned options!" << endl;
		cout << "\t\t\t\t\t    ";
		system("pause");
		break;
	}
	} while (1 != 0);
}

//Funkcija koja provjerava da li su strane kocke slozene kao kod Perfect kocke
//Svaka strana se provjerava sa svakom stranom jer se ne zna kako je korisnik odlucio da slozi strane
bool check() {
	endgame = (k.A.Niz == perfect.A.Niz || k.A.Niz == perfect.B.Niz || k.A.Niz == perfect.C.Niz
		|| k.A.Niz == perfect.D.Niz || k.A.Niz == perfect.E.Niz || k.A.Niz == perfect.F.Niz) &&
		(k.B.Niz == perfect.A.Niz || k.B.Niz == perfect.B.Niz || k.B.Niz == perfect.C.Niz
			|| k.B.Niz == perfect.D.Niz || k.B.Niz == perfect.E.Niz || k.B.Niz == perfect.F.Niz) &&
		(k.C.Niz == perfect.A.Niz || k.C.Niz == perfect.B.Niz || k.C.Niz == perfect.C.Niz
			|| k.C.Niz == perfect.D.Niz || k.C.Niz == perfect.E.Niz || k.C.Niz == perfect.F.Niz) &&
		(k.D.Niz == perfect.A.Niz || k.D.Niz == perfect.B.Niz || k.D.Niz == perfect.C.Niz
			|| k.D.Niz == perfect.D.Niz || k.D.Niz == perfect.E.Niz || k.D.Niz == perfect.F.Niz) &&
		(k.E.Niz == perfect.A.Niz || k.E.Niz == perfect.B.Niz || k.E.Niz == perfect.C.Niz
			|| k.E.Niz == perfect.D.Niz || k.E.Niz == perfect.E.Niz || k.E.Niz == perfect.F.Niz) &&
		(k.F.Niz == perfect.A.Niz || k.F.Niz == perfect.B.Niz || k.F.Niz == perfect.C.Niz
			|| k.F.Niz == perfect.D.Niz || k.F.Niz == perfect.E.Niz || k.F.Niz == perfect.F.Niz);
	return endgame;
}

//Ispis txt file Help s efektima
void help() {
	int main = 15;
	system("cls");
	std::string tempy;
	std::ifstream help;
	help.open("Help.txt");
	int i = 0;
	prikaz.changeColor(31);
	cout << "\t                                                                                                         \n";
	while (!help.eof()) {
		std::getline(help, tempy);
		prikaz.changeColor(31);
		cout << "\t ";
		prikaz.changeColor(7);
		if (i == 3) {
			prikaz.changeColor(14);
		}
		if (i > 2 && i < 7) {
			prikaz.changeColor(main);
		}
		else if (i >= 7 && i < 15) {
			prikaz.changeColor(9);
		}
		else if (i >= 15 && i < 19) {
			prikaz.changeColor(main);
		}
		else if (i >= 19 && i < 24) {
			prikaz.changeColor(12);
		}
		else if (i >= 24 && i < 26) {
			prikaz.changeColor(main);
		}
		else if (i == 26) {
			prikaz.changeColor(9);
		}
		else if (i == 28) {
			prikaz.changeColor(12);
		}
		else if (i == 29) {
			prikaz.changeColor(15);
		}
		else if (i > 29 && i < 50) {
			prikaz.changeColor(main);
		}
		else if (i >= 50 && i < 71) {
			prikaz.changeColor(12);
		}
		else if (i == 57) {
			prikaz.changeColor(main);
		}
		else if (i >= 74 && i < 79) {
			prikaz.changeColor(11);
		}
		cout << tempy;
		prikaz.changeColor(31);
		cout << "\t ";
		prikaz.changeColor(7);
		cout << endl;
		Sleep(300);
		i++;
	}
	prikaz.changeColor(31);
	cout << "\t                                                                                                         ";
	prikaz.changeColor(07);
	cout << endl << endl;
	help.close();
}

//Ispis Credits txt file s efektima
void credits() {
	int main = 15;
	system("cls");
	std::string tempy;
	std::ifstream help;
	help.open("Credits.txt");
	int i = 0;

	cout << "\t                                                                                                         \n";
	while (!help.eof()) {
		std::getline(help, tempy);

		if (i > 3 && i < 24) {
			prikaz.changeColor(13);
		}
		else if (i > 25 && i < 49) {
			prikaz.changeColor(10);
		}
		else if (i >= 51 && i < 75) {
			prikaz.changeColor(11);
		}
		else {
			prikaz.changeColor(15);
		}
		cout << tempy;

		cout << endl;
		Sleep(300);
		i++;
	}

	cout << endl << endl;
	help.close();
}