#include "ShemaKocke.h"
#include <windows.h>
using std::cout;
using std::cin;

ShemaKocke::ShemaKocke()
{
}

//Funkcija za promjenu boje teksta i pozadine
void ShemaKocke::changeColor(int desiredColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

void ShemaKocke::ispisSheme(Kocka k){
	this->changeColor(5);
	cout << "\n\t\t\t        -----\n";
	cout << "\t\t\t\t| B |\n";
	cout << "\t\t        -----------------\n";
	cout << "\t\t\t| F | E | A |" << " C |\n";
	cout << "\t\t        -----------------\n";
	cout << "\t\t\t\t| D |\n";
	cout << "\t\t\t        -----\n";
	this->changeColor(7);

	this->changeColor(12);
	cout << "\t\t\t\t\t        ---------\n";
	for (int i = 0; i < 3; i++){
		this->changeColor(9);
		cout << "\t\t\t\t\t\t| ";
		for (int j = 0; j < 3; j++) {
			this->changeColor(7);
			cout << k.B.Niz[i][j] << " ";
		}
		this->changeColor(9);
		cout << "| ";
		this->changeColor(7);
		cout << endl;
	}
	this->changeColor(12);
	cout << "\t\t\t        --------";
	this->changeColor(9);
	cout << "--------";
	this->changeColor(12);
	cout << "---------";
	this->changeColor(9);
	cout <<	"--------";
	this->changeColor(7);
	cout << "\n";
	for (int i = 0; i < 3; i++) {
		this->changeColor(14);
		cout << "\t                        | ";
		this->changeColor(7);
		for (int j = 0; j < 3; j++) {
			cout << k.F.Niz[i][j] << " ";
		}
		this->changeColor(14);
		cout << "| ";
		this->changeColor(7);
		for (int j = 0; j < 3; j++) {
			cout << k.E.Niz[i][j] << " ";
		}
		this->changeColor(14);
		cout << "| ";
		this->changeColor(7);
		for (int j = 0; j < 3; j++) {
			cout << k.A.Niz[i][j] << " ";
		}
		this->changeColor(14);
		cout << "| ";
		this->changeColor(7);
		for (int j = 0; j < 3; j++) {
			cout << k.C.Niz[i][j] << " ";
		}
		this->changeColor(14);
		cout << "| ";
		this->changeColor(7);
		cout << endl;
	}

	this->changeColor(12);
	cout << "\t\t\t        --------";
	this->changeColor(9);
	cout << "--------";
	this->changeColor(12);
	cout << "---------";
	this->changeColor(9);
	cout << "--------\n";
	this->changeColor(7);
	for (int i = 0; i < 3; i++) {
		this->changeColor(1);
		cout << "\t\t\t\t\t\t| ";
		this->changeColor(7);
		for (int j = 0; j < 3; j++) {
			cout << k.D.Niz[i][j] << " ";
		}
		this->changeColor(9);
		cout << "|";
		cout << endl;
		this->changeColor(7);
	}
	this->changeColor(12);
	cout << "\t\t\t\t\t        ---------\n";
	cout << endl << endl;
	this->changeColor(7);
}

void ShemaKocke::glavniMeni()
{
	this->changeColor(544);
	cout << "\n\t\t\t\t                  ";
	this->changeColor(432);
	cout << "                  ";
	this->changeColor(80);
	cout <<	"                  " << endl;
	this->changeColor(544);
	cout << "\t\t\t\t                  ";
	this->changeColor(432);
	cout <<	"                  ";
	this->changeColor(80);
	cout << "                  " << endl;
	this->changeColor(544);
	cout << "\t\t\t\t                  ";
	this->changeColor(432);
	cout <<"                  ";
	this->changeColor(80);
	cout << "                  " << endl;
	this->changeColor(544);
	cout << "\t\t\t\t  1. Let's play   ";
	this->changeColor(432);
	cout <<"   2. Load Game   ";
	this->changeColor(80);
	cout << "   3. Save Game   " << endl;
	this->changeColor(544);
	cout << "\t\t\t\t                  ";
	this->changeColor(432);
	cout <<"                  ";
	this->changeColor(80);
	cout << "                  " << endl;
	this->changeColor(544);
	cout << "\t\t\t\t                  ";
	this->changeColor(432);
	cout << "                  ";
	this->changeColor(80);
	cout << "                  " <<endl;
	this->changeColor(208);
	cout << "\t\t\t\t                  ";
	this->changeColor(224);
	cout <<	"                  ";
	this->changeColor(416);
	cout << "                  " << endl;
	this->changeColor(208);
	cout << "\t\t\t\t                  ";
	this->changeColor(224);
	cout << "                  ";
	this->changeColor(416);
	cout << "                  " << endl;
	this->changeColor(208);
	cout << "\t\t\t\t                  ";
	this->changeColor(224);
	cout <<	"                  ";
	this->changeColor(416);
	cout << "                  " << endl;
	this->changeColor(208);
	cout << "\t\t\t\t    6. Arcade     ";
	this->changeColor(224);
	cout << " 5. Instructions  ";
	this->changeColor(416);
	cout << "  4. Score Board  " << endl;
	this->changeColor(208);
	cout << "\t\t\t\t                  ";
	this->changeColor(224);
	cout << "                  ";
	this->changeColor(416);
	cout << "                  " << endl;
	this->changeColor(208);
	cout << "\t\t\t\t                  ";
	this->changeColor(224);
	cout << "                  ";
	this->changeColor(416);
	cout << "                  " << endl;
	this->changeColor(128);
	cout << "\t\t\t\t                  ";
	this->changeColor(368);
	cout << "                  ";
	this->changeColor(560);
	cout << "                  " << endl;
	this->changeColor(128);
	cout << "\t\t\t\t                  ";
	this->changeColor(368);
	cout << "                  ";
	this->changeColor(560);
	cout << "                  " << endl;
	this->changeColor(128);
	cout << "\t\t\t\t                  ";
	this->changeColor(368);
	cout << "                  ";
	this->changeColor(560);
	cout << "                  " << endl;
	this->changeColor(128);
	cout << "\t\t\t\t 7. Arcade Board  ";
	this->changeColor(368);
	cout << "    8. Credits    ";
	this->changeColor(560);
	cout << "     9. Exit      " << endl;
	this->changeColor(128);
	cout << "\t\t\t\t                  ";
	this->changeColor(368);
	cout << "                  ";
	this->changeColor(560);
	cout << "                  " << endl;
	this->changeColor(128);
	cout << "\t\t\t\t                  ";
	this->changeColor(368);
	cout << "                  ";
	this->changeColor(560);
	cout << "                  " << endl << "\n\t\t\t\t";
	this->changeColor(07);
}

ShemaKocke::~ShemaKocke()
{
}