#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using std::cout;
using std::endl;

//Klasa koja sadrzi osnovne elemente za svaku stranu kocke
class Strana
{
public:
	Strana();
	std::vector<std::vector<int>> Boje;
	std::vector<std::vector<int>> Niz;
	std::vector<std::vector<int>> Popuni(int x,int y, std::vector<int> sveKockice);

	~Strana();
};