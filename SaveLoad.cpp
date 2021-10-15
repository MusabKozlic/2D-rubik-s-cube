#include "SaveLoad.h"
#include <fstream>
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

bool flag = false;

SaveLoad::SaveLoad()
{
}

/* LOAD funkcija radi na principu da prima ime trazenog SAVE fajla od korisnika,
   provjerava da li SAVE file sa tim imenom postoji i ako postoji da li je potpun.
   Zatim, ucitava podatke iz txt fila u privermenu kocku ruby, a to su svi 2D nizovi, broj pokreta 
   i utroseno vrijeme. Na kraju, vraca nazad u glavnu kocku k. */

Kocka SaveLoad::Load()
{
	Kocka ruby;
	std::string tempy;
	int brojac = 0;

	cout << "\t\t\t\t\t\t\t********\n";
	cout << "\t\t\t\t\t\t\t* LOAD *\n";
	cout << "\t\t\t\t\t\t\t********\n\n";
	cout << "\n\t\t\t\t\t\tNames of the saved files:\n" << endl;

	std::ifstream names("AllSaves.txt"); //txt file sa imenima svih SAVE fajlova
	s.changeColor(12);

	while (!names.eof()) { //petlja koja prebrojava broj redova u AllSaves.txt i ispisuje ih na ekran
		std::getline(names, tempy);
		cout << "\t\t\t\t\t\t     " << tempy << endl;
		brojac++;
	}

	names.close();
	cout << endl;
	s.changeColor(7);
	cout << "\t\t\t\t\t\tInsert Save file name: ";

	std::string UserInput;

	bool trig = false;
	//Korisnik unosi ime fajla. Petlja se prekida samo kad se unese tacno ime datoteke
	do {
		cin >> UserInput;
		names.open("AllSaves.txt");
		tempy.clear();

		for (int i = 0; i <= brojac; i++) {
		//Petlja usporedjuje svaki  red datoteke AllSaves.txt i unos
			std::getline(names, tempy);

			if (tempy == UserInput) { //ako postoji uneseno ime datoteke, izlazi se iz petlje
				trig = true;
				break;
			}

			if (i == brojac) { //ako ne postoji petlja se nastavlja izvrsavati
				cout << "\n\t\t\t\t\t      Save file with that name doesn't exist!\n\t\t\t\t\t\t  Insert another: ";
				names.close();
				break;
			}
		}
	} while (trig == false);

	names.close();

	names.open("AllSaves.txt");
	std::ifstream upis;
	upis.open(UserInput); //otvara se trazeni SAVE

	ruby.setKocka(); //ruby se popunjava privremenim vrijednostima
	char temp;

	//Ucitavaju se vrijednosti svakog karaktera u nizove
	for (int i = 0; i < 3; i++) {
		for (int y = 0; y < 3; y++) {
			upis >> temp;
			ruby.A.Niz[i][y] = (int)temp - 48;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int y = 0; y < 3; y++) {
			upis >> temp;
			ruby.B.Niz[i][y] = (int)temp - 48;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int y = 0; y < 3; y++) {
			upis >> temp;
			ruby.C.Niz[i][y] = (int)temp - 48;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int y = 0; y < 3; y++) {
			upis >> temp;
			ruby.D.Niz[i][y] = (int)temp - 48;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int y = 0; y < 3; y++) {
			upis >> temp;
			ruby.E.Niz[i][y] = (int)temp - 48;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int y = 0; y < 3; y++) {
			upis >> temp;
			ruby.F.Niz[i][y] = (int)temp - 48;
		}
	}

	//Try catch provjerava da li je Save file popunjen sa ispravnim vrijednostima.
	//Ako nije, citava funckija se ponovo poziva
	try {
		if (ruby.A.Niz[0][0] < 1 || ruby.A.Niz[0][0] > 6)
		{
			throw ("The save file is missing or corrupted!");
		}
	}
	catch(...){
		system("cls");
		cout << " " << endl;
		cout << " " << endl;
		this->s.changeColor(12);
		cout << "\n\t\t\t\t   The save file " << UserInput << " is missing or corrupted!" << endl;
		this->s.changeColor(7);
		cout << " " << endl;
		cout << " " << endl;

		Load();
	}

	//Ako je kocka pravilno popunjena, vrijednosti pokreta i utrosenog vremena su unesene
	upis >> ruby.pokreti;
	upis >> ruby.time;
	if(!flag) {
		cout << "\n\t\t\t\t\t\tAlright, the cube has been loaded.\n\t\t\t\t\t\t  Choose Let's Play to continue." << endl;
	cout << "\n\t\t\t\t\t\t   ";
	system ("pause");
	}

	flag = true;
	return ruby;
}

/* SAVE radi na principu da se vrijednosti glavne kocke k upisuju u novi txt file koji korisnik imenuje po zelji.
  Program provjerava da li je ime datoteke slobodno
  Ako je slobodno, upisuju se vrijednosti svakog niza u txt file po redosljedu stranica A, B, C, D, E i F
  Zatim se upisuje broj pokreta koje je korisnik napravio, a onda i korisnikovo utroseno vrijeme. */

void SaveLoad::Save(Kocka ruby)
{
	cout << "\t\t\t\t\t\t      ********\n";
	cout << "\t\t\t\t\t\t      * SAVE *\n";
	cout << "\t\t\t\t\t\t      ********\n\n";
	int brojac = 0;
	cout << "\n\t\t\t\t\t\tInsert Save file name!\n\t\t\t\t\t\t\t";
	std::string ext = ".txt";
	std::string temp;
	std::ifstream names;

	names.open("AllSaves.txt");
	std::string UserInput;
	cin >> UserInput;
	UserInput.append(ext);

	while (!names.eof()) {
		std::getline(names, temp);
		brojac++;
	}
	names.close();
	names.open("AllSaves.txt");

	int z = 0;
	
	do { //provjera imena
		for (int i = 0; i < brojac; i++) {
			z++;
			std::getline(names, temp);
			if (temp == UserInput) {
				this->s.changeColor(12);
				cout << "\n\t\t\t\t\tSave file with this name already exists!" << endl;
				cout << "\t\t\t\t\t        Insert new name: ";
				this->s.changeColor(7);
				cin >> UserInput;
				UserInput.append(ext);
				break;
			}
		}
	} while (z == brojac);
	names.close();

	std::ofstream save;
	save.open("AllSaves.txt", std::ios::app);
	save << UserInput << endl;
	save.close();

	save.open(UserInput); //otvaranje novog txt fajla
	for (int i = 0; i < 3; i++) {
		for (int y = 0; y < 3; y++) {
			save << ruby.A.Niz[i][y];
		}
	}
	cout << endl;

	//Zapis vrijednosti u txt file
	for (int i = 0; i < 3; i++) {
		for (int y = 0; y < 3; y++) {
			save << ruby.B.Niz[i][y];
		}
	}
	cout << endl;

	for (int i = 0; i < 3; i++) {
		for (int y = 0; y < 3; y++) {
			save << ruby.C.Niz[i][y];
		}
	}
	cout << endl;

	for (int i = 0; i < 3; i++) {
		for (int y = 0; y < 3; y++) {
			save << ruby.D.Niz[i][y];
		}
	}
	cout << endl;

	for (int i = 0; i < 3; i++) {
		for (int y = 0; y < 3; y++) {
			save << ruby.E.Niz[i][y];
		}
	}
	cout << endl;

	for (int i = 0; i < 3; i++) {
		for (int y = 0; y < 3; y++) {
			save << ruby.F.Niz[i][y];
		}
	}
	cout << endl;
	save << endl << ruby.pokreti;
	save << endl << ruby.time;
	save.close();
}

SaveLoad::~SaveLoad()
{
}