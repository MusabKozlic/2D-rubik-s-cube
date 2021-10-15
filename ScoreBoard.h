#pragma once
#include <istream>
#include "ShemaKocke.h"

//Klasa za spremanje podataka u rang listu
class ScoreBoard
{
private: 
	char ime[30];
	double finalTime;
public:
	ShemaKocke s;
	ScoreBoard();
	void setIme();
	char* getIme();
	void setFinalTime(double time);
	double getFinalTime();
	void upisScoreboarda();
	friend std::ostream& operator<<(std::ostream& stream, ScoreBoard& s);
	friend std::istream& operator>>(std::istream& stream, ScoreBoard& s);
	~ScoreBoard() {};
};