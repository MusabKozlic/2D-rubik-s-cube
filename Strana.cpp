#pragma once
#include "Strana.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

inline Strana::Strana() 
{ 
}

//Funkcija za popunjavanje strana odredjenim brojevima
inline std::vector<std::vector<int>> Strana::Popuni(int x,int y, std::vector<int> sveKockice) {
	for (int i = 0; i < 3; i++) {
		Boje.push_back(std::vector<int>());
	}
	for (int i = 0; i < 3; i++) {
		Boje[0].push_back(sveKockice[x]);
		x++;
	}

	Boje[1].push_back(sveKockice[x]);
	Boje[1].push_back(y);
	x++;
	Boje[1].push_back(sveKockice[x]);
	x++;
	for (int i = 0; i < 3; i++) {
		Boje[2].push_back(sveKockice[x]);
		x++;
	}
	return Boje;
}

inline Strana::~Strana() 
{
}