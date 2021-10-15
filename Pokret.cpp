#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <windows.h>
#include <chrono>
#include "Pokret.h"

using std::cout;
using std::cin;
using std::endl;

char stranica = 'N';
bool meni = false;
int KR = 0;
char unos;
char first;
int Arcade::smjer = 0;
int Pokret::smjer = 0;

 Pokret::Pokret()
{
	this->smjerovi = (EnumyDirection) NONE;
}

Pomjeranje User;

//Virtualna funkcija
Kocka Pokret::pokret(Kocka kocka,int move)
{
	meni = false;
	cout << "\t\t\t\t ***** GRID VIEW OF CUBE! *****\n\n";
	cout << "\t\t\t    ~ To open menu at end of turn enter M! ~\n" << endl;
	
	do { //petlja u kojoj igrac bira stranicu koju zeli pomjeriti
		this->s.changeColor(11);
		cout << "\t\t\tInsert which side you want to move (From A to F): ";
		this->s.changeColor(7);
		cin >> stranica;
		if (stranica == 'M') {
			meni = true;
			cout << " " << endl;
			this->s.changeColor(12);
		    cout << "\t\t\t\tAlright, finish the move.\n";
			this->s.changeColor(7);
			cout << " " << endl;
		}
	} while (stranica != 65 && stranica != 66 && stranica != 67 && stranica != 68 && stranica != 69 && stranica != 70 && stranica != 97 && stranica != 98 && stranica != 99 && stranica != 100 && stranica != 101 && stranica != 102);

	this->s.changeColor(11);
	cout << "\n\t\t\t\t    Choose a column or a row!\n\n";
	this->s.changeColor(5);
	
	do { //petlja u kojoj igrac bira red ili kolonu koju zeli pomjeriti
		Sleep(100);
		cout << "\t\t\t        1. COLUMN 1" << "\t\t" << "4. ROW 1" << endl;
		Sleep(100);
		cout << "\t\t\t        2. COLUMN 2" << "\t\t" << "5. ROW 2" << endl;
		Sleep(100);
		cout << "\t\t\t        3. COLUMN 3" << "\t\t" << "6. ROW 3" << endl;
		Sleep(200);
		this->s.changeColor(7);
		cout << "\n\t\t\t\t\t    1.   2.   3.\n";
		this->s.changeColor(5);
		cout << "\t\t\t\t\t   _____________\n";

		this->s.changeColor(7);
		cout << "\t\t\t\t\t4.";
		this->s.changeColor(5);
		cout << "|    |    |   |\n";
		cout << "\t\t\t\t\t  |____|____|___|\n";
		Sleep(100);
		this->s.changeColor(7);
		cout << "\t\t\t\t\t5.";
		this->s.changeColor(5);
		cout << "|    |    |   |\n";
		cout << "\t\t\t\t\t  |____|____|___|\n";
		Sleep(100);
		this->s.changeColor(7);
		cout << "\t\t\t\t\t6.";
		this->s.changeColor(5);
		cout << "|    |    |   |\n";
		cout << "\t\t\t\t\t  |____|____|___|\n";
		Sleep(100);
		this->s.changeColor(7);
		cout << "\n\t\t\t\t\t     Choice: ";
		cin >> unos;
		KR = (int)unos - 48;
		if (unos == 'M') {
			meni = true;
			cout << " " << endl;
			this->s.changeColor(12);
			cout << "\t\t\t\tAlright, finish the move.\n";
			this->s.changeColor(7);
			cout << " " << endl;
		}
	} while (KR < 1 || KR > 6);

	this->s.changeColor(11);
	cout << "\n\n\t\t\t\t   ** CHOOSE THE DIRECTION **" << endl;
	do {
		if (KR > 3) {
		//Ukoliko se prethodno odabere jedan od redova, igrac odbire smjer pomjeranja: lijevo ili desno
			this->s.changeColor(5);
			cout << "\n\t\t\t\t\t    1. RIGHT" << endl;
			cout << "\t\t\t\t\t    2. LEFT" << endl;
			this->s.changeColor(7);
			cout << "\t\t\t\t\t    Choice: ";
		}
		//Ukoliko se prethodno odabere jedna od kolona, igrac odabire smjer pomjeranja iste,  gore ili dole
		else if (KR < 4)
		{
			this->s.changeColor(5);
			cout << "\n\t\t\t\t\t     1. UP" << endl;
			cout << "\t\t\t\t\t     2. DOWN" << endl;
			this->s.changeColor(7);
			cout << "\t\t\t\t\t     Choice: ";
		}
		cin >> unos;
		Pokret::smjer = (int)unos - 48;
		if (unos == 'M') {
			meni = true;
			cout << " " << endl;
			this->s.changeColor(12);
			cout << "\t\t\t\t   Alright, finish the move.\n";
		}
	} while (Pokret::smjer < 1 || Pokret::smjer > 2);

	//Ispis odabira igraca i smjestanje u varijable
	cout << " " << endl;
	this->s.changeColor(14);
	cout << "\t\t\t    You chose SIDE " << char(toupper(stranica));
	if (KR < 4) {
		cout << ", column " << KR;
	}
	else {
		cout << ", row " << KR-3;
	}
	cout<< ", direction ";

	//Ispis smjera okretanja upotrebom enumeracije
	if (KR < 4) {
		if (Pokret::smjer == 1) {
			this->smjerovi = UP;
		}
		else if (Pokret::smjer == 2) {
			this->smjerovi = DOWN;
		}
		if (this->smjerovi == 3) {
			cout << "UP." << endl;
		}
		else if (this->smjerovi == 4) {
			cout << "DOWN." << endl;
		}
	}
	if (KR > 3) {
		if (Pokret::smjer == 1) {
			this->smjerovi = RIGHT;
		}
		else if (Pokret::smjer == 2) {
			this->smjerovi = LEFT;
		}
		if (this->smjerovi == 1) {
			cout << "RIGHT." << endl;
		}
		else if(this->smjerovi==2) {
			cout << "LEFT." << endl;
		}
	}
	this->s.changeColor(7);
	cout << "\n\t\t\t\t    ";
	system ("pause");
	//'Pokreti' se proslijedjuju u klasu za pomjeranje
	switch (stranica) {
	case 'a':
	case 'A':
		if (KR < 4) {
			kocka = User.AKolone(kocka, smjer, KR);
		}
		else {
			kocka = User.ARedovi(kocka, smjer, KR);
		}
        break;

	case 'b':
	case 'B':
		if (KR < 4) {
			kocka = User.BKolone(kocka, smjer, KR);
		}
		else {
			kocka = User.BRedovi(kocka, smjer, KR);
		}
        break;

	case 'c':
	case 'C':
		if (KR < 4) {
			kocka = User.CKolone(kocka, smjer, KR);
		}
		else {
			kocka = User.CRedovi(kocka, smjer, KR);
		}
	    break;

	case 'd':
	case 'D':
		if (KR < 4) {
			kocka = User.DKolone(kocka, smjer, KR);
		}
		else {
			kocka = User.DRedovi(kocka, smjer, KR);
		}
        break;

	case 'e':
	case 'E':
		if (KR < 4) {
			kocka = User.EKolone(kocka, smjer, KR);
		}
		else {
			kocka = User.ERedovi(kocka, smjer, KR);
		}
		break;

	case 'f':
	case 'F':
		if (KR < 4) {
			kocka = User.FKolone(kocka, smjer, KR);
		}
		else {
			kocka = User.FRedovi(kocka, smjer, KR);
		}
		break;
	}
	if (meni) {
		kocka.meni = true;
	}
	return kocka;
}

Pokret::~Pokret()
{
}

//Pozivanje virtuelne funkcije u funckiji za Arkadu
Kocka Arcade::pokret(Kocka kocka, int move)
{
	meni = false;
	if (move == 0) {
		first = 'N';
	}

	cout << "\t\t\t\t ***** GRID VIEW OF CUBE! *****\n\n";
	do {
		this->s.changeColor(11);
		cout << "\t\t\tInsert which side you want to move (From A to F): ";
		this->s.changeColor(7);
		cin >> stranica;

		//Try catch osigurava da korisnik nece birati istu stranicu dva puta za redom

		try {
			if (stranica == toupper(first) || stranica == tolower(first)) {
				throw("Same side!");
			}
		}
		catch (...) {
			while(stranica == toupper(first) || stranica == tolower(first)){
			cout << " " << endl;
			this->s.changeColor(12);
			cout << "\t\t\tSame side as the previous one! Choose a diffrent one: ";
			this->s.changeColor(7);
			cin >> stranica;
		}

		}

	} while (stranica != 65 && stranica != 66 && stranica != 67 && stranica != 68 && stranica != 69 && stranica != 70 && stranica != 97 && stranica != 98 && stranica != 99 && stranica != 100 && stranica != 101 && stranica != 102);
		first = stranica;

		//Korisnik odabire kolonu, ako je pokret paran ili nulti pokret
		if (move % 2 == 0) {
			this->s.changeColor(11);
			cout << "\n\t\t\t\t          Choose a column!\n\n";
			this->s.changeColor(5);
			do {
				cout << "\t\t\t                    1. COLUMN 1" << endl;
				cout << "\t\t\t                    2. COLUMN 2" << endl;
				cout << "\t\t\t                    3. COLUMN 3" << endl;
				Sleep(100);
				this->s.changeColor(7);
				cout << "\n\t\t\t\t\t    1.   2.   3.\n";
				this->s.changeColor(5);
				cout << "\t\t\t\t\t   _____________\n";

				this->s.changeColor(7);
				cout << "\t\t\t\t\t";
				this->s.changeColor(5);
				cout << "  |    |    |   |\n";
				cout << "\t\t\t\t\t  |____|____|___|\n";
				Sleep(100);
				this->s.changeColor(7);
				cout << "\t\t\t\t\t";
				this->s.changeColor(5);
				cout << "  |    |    |   |\n";
				cout << "\t\t\t\t\t  |____|____|___|\n";
				Sleep(100);
				this->s.changeColor(7);
				cout << "\t\t\t\t\t";
				this->s.changeColor(5);
				cout << "  |    |    |   |\n";
				cout << "\t\t\t\t\t  |____|____|___|\n";
				Sleep(100);
				this->s.changeColor(7);
				cout << "\n\t\t\t\t\t     Choice: ";
				cin >> unos;

				KR = (int)unos - 48;

			} while (KR < 1 || KR > 3);
		}
		//Ako je pokret neparan, korisnik odabire red
		else {
			this->s.changeColor(11);
			cout << "\n\t\t\t\t\t    Choose a row!\n\n";
			this->s.changeColor(5);
			do {
				cout << "\t\t\t\t\t       4. ROW 1" << endl;
				cout << "\t\t\t\t\t       5. ROW 2" << endl;
				cout << "\t\t\t\t\t       6. ROW 3";
				Sleep(100);
				this->s.changeColor(7);
				cout << "\t\t\t\t\t \n";
				this->s.changeColor(5);
				cout << "\t\t\t\t\t     _____________\n";
				Sleep(100);
				this->s.changeColor(7);
				cout << "\t\t\t\t\t 4.";
				this->s.changeColor(5);
				cout << " |    |    |   |\n";
				cout << "\t\t\t\t\t    |____|____|___|\n";
				Sleep(100);
				this->s.changeColor(7);
				cout << "\t\t\t\t\t 5.";
				this->s.changeColor(5);
				cout << " |    |    |   |\n";
				cout << "\t\t\t\t\t    |____|____|___|\n";
				Sleep(100);
				this->s.changeColor(7);
				cout << "\t\t\t\t\t 6.";
				this->s.changeColor(5);
				cout << " |    |    |   |\n";
				cout << "\t\t\t\t\t    |____|____|___|\n";
				Sleep(100);
				this->s.changeColor(7);
				cout << "\n\t\t\t\t\t\tChoice: ";
				cin >> unos;
				cout << endl;

				KR = (int)unos - 48;

			} while (KR < 4 || KR > 6);
		}

		//Izbor smjera pomjeranja
		this->s.changeColor(11);
		cout << "\n\n\t\t\t\t   ** CHOOSE THE DIRECTION **" << endl;
		do {
			if (KR > 3) {
				this->s.changeColor(5);
				cout << "\n\t\t\t\t\t    1. RIGHT" << endl;
				cout << "\t\t\t\t\t    2. LEFT" << endl;
				this->s.changeColor(7);
				cout << "\t\t\t\t\t    Choice: ";
			}
			else if (KR < 4)
			{
				this->s.changeColor(5);
				cout << "\n\t\t\t\t\t     1. UP" << endl;
				cout << "\t\t\t\t\t     2. DOWN" << endl;
				this->s.changeColor(7);
				cout << "\t\t\t\t\t     Choice: ";
			}
			cin >> unos;
			Arcade::smjer = (int)unos - 48;

		} while (Arcade::smjer < 1 || Arcade::smjer > 2);

		cout << " " << endl;
		this->s.changeColor(14);
		cout << "\t\t\t    You chose SIDE " << char(toupper(stranica));
		if (KR < 4) {
			cout << ", column " << KR;
		}
		else {
			cout << ", row " << KR - 3;
		}
		cout << ", direction ";

		//Ispis smjera upotrebom enumeracije
		if (KR < 4) {
			if (Arcade::smjer == 1) {
				this->smjerovi = UP;
			}
			else if (Arcade::smjer == 2) {
				this->smjerovi = DOWN;
			}
			if (this->smjerovi == 3) {
				cout << "UP." << endl;
			}
			else if (this->smjerovi == 4) {
				cout << "DOWN." << endl;
			}
		}
		if (KR > 3) {
			if (Arcade::smjer == 1) {
				this->smjerovi = RIGHT;
			}
			else if (Arcade::smjer == 2) {
				this->smjerovi = LEFT;
			}
			if (this->smjerovi == 1) {
				cout << "RIGHT." << endl;
			}
			else if (this->smjerovi == 2) {
				cout << "LEFT." << endl;
			}
		}
		this->s.changeColor(7);
		cout << "\n\t\t\t\t    ";
		system ("pause");

		//Pozivanje odgovarajuce funkcije, na osnovu korisnikovog izbora
		switch (stranica) {
		case 'a':
		case 'A':
			if (KR < 4) {
				kocka = User.AKolone(kocka, smjer, KR);
			}
			else {
				kocka = User.ARedovi(kocka, smjer, KR);
			}

			for (int i = 0; i < 3; i++) {
				if (kocka.A.Niz[i][0] == kocka.A.Niz[i][1] && kocka.A.Niz[i][0] == kocka.A.Niz[i][2])
				{
					kocka.points += 10;
				}
			}

			for (int y = 0; y < 3; y++) {
				if (kocka.A.Niz[0][y] == kocka.A.Niz[1][y] && kocka.A.Niz[0][y] == kocka.A.Niz[2][y]) {
					kocka.points += 10;
				}
			}
			break;

		case 'b':
		case 'B':
			if (KR < 4) {
				kocka = User.BKolone(kocka, smjer, KR);
			}
			else {
				kocka = User.BRedovi(kocka, smjer, KR);
			}

			for (int i = 0; i < 3; i++) {
				if (kocka.B.Niz[i][0] == kocka.B.Niz[i][1] && kocka.B.Niz[i][0] == kocka.B.Niz[i][2])
				{
					kocka.points += 10;
				}
			}

			for (int y = 0; y < 3; y++) {
				if (kocka.B.Niz[0][y] == kocka.B.Niz[1][y] && kocka.B.Niz[0][y] == kocka.B.Niz[2][y]) {
					kocka.points += 10;
				}
			}
			break;

		case 'c':
		case 'C':
			if (KR < 4) {
				kocka = User.CKolone(kocka, smjer, KR);
			}
			else {
				kocka = User.CRedovi(kocka, smjer, KR);
			}

			for (int i = 0; i < 3; i++) {
				if (kocka.C.Niz[i][0] == kocka.C.Niz[i][1] && kocka.C.Niz[i][0] == kocka.C.Niz[i][2])
				{
					kocka.points += 10;
				}
			}

			for (int y = 0; y < 3; y++) {
				if (kocka.C.Niz[0][y] == kocka.C.Niz[1][y] && kocka.C.Niz[0][y] == kocka.C.Niz[2][y]) {
					kocka.points += 10;
				}
			}
			break;

		case 'd':
		case 'D':
			if (KR < 4) {
				kocka = User.DKolone(kocka, smjer, KR);
			}
			else {
				kocka = User.DRedovi(kocka, smjer, KR);
			}

			for (int i = 0; i < 3; i++) {
				if (kocka.D.Niz[i][0] == kocka.D.Niz[i][1] && kocka.D.Niz[i][0] == kocka.D.Niz[i][2])
				{
					kocka.points += 10;
				}
			}

			for (int y = 0; y < 3; y++) {
				if (kocka.D.Niz[0][y] == kocka.D.Niz[1][y] && kocka.D.Niz[0][y] == kocka.D.Niz[2][y]) {
					kocka.points += 10;
				}
			}
			break;

		case 'e':
		case 'E':
			if (KR < 4) {
				kocka = User.EKolone(kocka, smjer, KR);
			}
			else {
				kocka = User.ERedovi(kocka, smjer, KR);
			}

			for (int i = 0; i < 3; i++) {
				if (kocka.E.Niz[i][0] == kocka.E.Niz[i][1] && kocka.E.Niz[i][0] == kocka.E.Niz[i][2])
				{
					kocka.points += 10;
				}
			}

			for (int y = 0; y < 3; y++) {
				if (kocka.E.Niz[0][y] == kocka.E.Niz[1][y] && kocka.E.Niz[0][y] == kocka.E.Niz[2][y]) {
					kocka.points += 10;
				}
			}
			break;

		case 'f':
		case 'F':
			if (KR < 4) {
				kocka = User.FKolone(kocka, smjer, KR);
			}
			else {
				kocka = User.FRedovi(kocka, smjer, KR);
			}

			for (int i = 0; i < 3; i++) {
				if (kocka.F.Niz[i][0] == kocka.F.Niz[i][1] && kocka.F.Niz[i][0] == kocka.F.Niz[i][2])
				{
					kocka.points += 10;
				}
			}

			for (int y = 0; y < 3; y++) {
				if (kocka.F.Niz[0][y] == kocka.F.Niz[1][y] && kocka.F.Niz[0][y] == kocka.F.Niz[2][y]) {
					kocka.points += 10;
				}
			}
			break;
		}
return kocka;
}

Arcade::~Arcade()
{
}