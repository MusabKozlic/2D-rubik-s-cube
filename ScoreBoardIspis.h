#pragma once
#include <iostream>
#include "ScoreBoard.h"
#include <fstream>
#include <vector>

//Klasa za sortiranje ranga igraca
class ScoreBoardSort : 
	public ScoreBoard
{	
private:
	std::vector<std::string> List;
public:

	ScoreBoardSort() : ScoreBoard() {}
	void Results();
	void ispisScoreBoard();
	~ScoreBoardSort();
};