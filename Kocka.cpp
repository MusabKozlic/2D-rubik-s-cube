#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "SaveLoad.h"

using std::cout;
using std::cin;
using std::endl;

inline Kocka::Kocka()
{
}

//Funkcija koja postavlja gotovu kocku
inline void Kocka::setKocka() {

	std::vector<int> Kockice = { 1, 1, 1, 1, 1, 1, 1, 1,
	                             2, 2, 2, 2, 2, 2, 2, 2,
	                             3, 3, 3, 3, 3, 3, 3, 3,
                                 4, 4, 4, 4, 4, 4, 4, 4,
	                             5, 5, 5, 5, 5, 5, 5, 5,
	                             6, 6, 6, 6, 6, 6, 6, 6 };

	int x = 0;

	A.Niz=A.Popuni(x,1, Kockice);
	x += 8;

	B.Niz=B.Popuni(x,2, Kockice);
	x += 8;

	C.Niz=C.Popuni(x,3, Kockice);
	x += 8;

	D.Niz=D.Popuni(x,4, Kockice);
	x += 8;

	E.Niz=E.Popuni(x,5, Kockice);
	x += 8;

	F.Niz=F.Popuni(x,6, Kockice);
}

inline Kocka::~Kocka()
{
}