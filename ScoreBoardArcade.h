#pragma once
#include "ScoreBoard.h"

//Klasa za rangiranje igraca Arkade
class ScoreBoardArcade :
    public ScoreBoard
{
private:
    std::vector<std::string> List;
    int points;
    ScoreBoard Score;
public:
    ScoreBoardArcade() : ScoreBoard(){}
    void upisScoreBoard();
    void ispisScoreBoard();
    void setPoints(int p);
    void ucitavanje();
    int getPoints();
};