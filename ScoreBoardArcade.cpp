#include "ScoreBoardArcade.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include "ScoreBoard.h"
#include <string>
#include <sstream>

//Funkcija za upis imena i utrosenog vremena u datoteku ScoreBoard.txt
void ScoreBoardArcade::upisScoreBoard()
{
	if (this->getPoints() > 0) {
		this->Score.setIme();
		std::string red;
		std::ofstream file;
		file.open("ScoreboardArcade.txt", std::ios_base::app);
		file <<"\n" << this->getPoints();
		file << std::setw(6) << std::right;
		file << "-  " << this->Score.getIme();
		file.close();
	}
}

//Funkcija za ispis txt fajla sa efektima
//Upotreba nasljedivanja u ScoreBoardIspis.cpp
void ScoreBoardArcade::ispisScoreBoard()
{
	this->ucitavanje();
	std::cout << "\t\t\t\t\t\t  *********************\n";
	std::cout << "\t\t\t\t\t\t  * SCOREBOARD ARCADE *\n";
	std::cout << "\t\t\t\t\t\t  *********************\n\n";
	std::shared_ptr<std::string> temp(new std::string);
	for (int i = 0; i < this->List.size(); i++) {
		for (int j = i + 1; j < this->List.size(); j++) {

			std::string temp1 = this->List[i].substr(0, this->List[i].find('-'));
			std::string temp2 = this->List[j].substr(0, this->List[j].find('-'));
			int t1;
			std::istringstream(temp1) >> t1;
			int t2;
			std::istringstream(temp2) >> t2;
			if (t1 < t2) {
				*temp = this->List[j];
				this->List[j] = this->List[i];
				List[i] = *temp;
			}
		}
	}
	for (int i = 0; i < this->List.size(); i++) {
		this->s.changeColor(13);
		std::cout << "\t\t\t\t\t\t     ";
		std::cout << std::setw(4) << std::setprecision(3) << std::fixed << std::setfill(' ') << std::right;
		std::cout << this->List[i] << std::endl;
	}
	std::cout << std::endl;
	this->s.changeColor(7);
	this->List.clear();
}

void ScoreBoardArcade::setPoints(int p)
{
	this->points = p;
}

void ScoreBoardArcade::ucitavanje()
{
	std::ifstream rez;
	rez.open("ScoreboardArcade.txt");
	std::string Output;
	while (!rez.eof()) {
		getline(rez, Output);
		this->List.push_back(Output);
	}
	rez.close();
}

int ScoreBoardArcade::getPoints()
{
	return this->points;
}