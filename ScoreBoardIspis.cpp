#include "ScoreBoardIspis.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <memory>

//Funkcija za uzimanje podataka iz fajla kako bi se mogli sortirati
void ScoreBoardSort::Results()
{
	std::ifstream rez;
	rez.open("Scoreboard.txt");
	std::string Output;
	while (!rez.eof()) {
		getline(rez, Output);
		this->List.push_back(Output);
	}
	rez.close();
}

//Funkcija za sortiranje preko nasljedene funkcije
void ScoreBoardSort::ispisScoreBoard()
{
	Results();
	std::cout << "\t\t\t\t\t\t**************\n";
	std::cout << "\t\t\t\t\t\t* SCOREBOARD *\n";
	std::cout << "\t\t\t\t\t\t**************\n\n";
	std::shared_ptr<std::string> temp(new std::string);
	for (int i = 0; i < this->List.size(); i++) {
		for (int j = i+1; j < this->List.size(); j++) {

			std::string temp1 = this->List[i].substr(0, this->List[i].find(' '));
			std::string temp2 = this->List[j].substr(0, this->List[j].find(' '));
			double t1 = atof(temp1.c_str());
			double t2 = atof(temp2.c_str());
			if (t1 > t2) {
				*temp = this->List[i];
				this->List[i] = this->List[j];
				this->List[j] = *temp;
			}
		}
	}
	for (int i = 0; i < this->List.size(); i++) {
		this->s.changeColor(14);

		std::cout << "\t\t\t\t\t\t ";
		std::cout << this->List[i] << std::endl;
	}
	std::cout << std::endl;
	this->s.changeColor(7);
	this->List.clear();
}

ScoreBoardSort::~ScoreBoardSort()
{
}