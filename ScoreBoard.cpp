#include "ScoreBoard.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

ScoreBoard::ScoreBoard()
{
	strcpy_s(this->ime, "Unknown");
	this->finalTime = 0;
}

void ScoreBoard::setIme()
{
	s.changeColor(13);
	std::cout << "    Enter first name: ";
	s.changeColor(7);
	std::cin.getline(this->ime, 30);
}

char* ScoreBoard::getIme()
{
	return this->ime;
}

void ScoreBoard::setFinalTime(double time)
{
	this->finalTime = time;
}

double ScoreBoard::getFinalTime()
{
	return this->finalTime;
}

//Funkcija za zapisivanje u datoteku ScoreBoard.txt
void ScoreBoard::upisScoreboarda()
{
	std::string red;
	std::ofstream file;
	file.open("Scoreboard.txt", std::ios_base::app);
	file << std::setw(6) << std::setprecision(2) << std::fixed << std::setfill('0') << std::right << this->getFinalTime();
	file << " "  << std::left << this->getIme() << "\n";
	file.close();
}

//Preoptereceni operatori
std::ostream& operator<<(std::ostream& stream, ScoreBoard& s)
{
	s.s.changeColor(14);
	std::cout << "\n\t\t\t\tCongratulations! " << s.getIme() << " finished the cube in " << s.getFinalTime() << "s\n";
	s.s.changeColor(7);
	return stream;
}

std::istream& operator>>(std::istream& stream, ScoreBoard& s)
{
	s.setIme();
	return stream;
}