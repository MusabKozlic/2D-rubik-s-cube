#pragma once
#include "Kocka.h"
#include "RandomGenerisanje.h"
#include <vector>

class Pomjeranje
{
private:
	std::vector <std::vector <int>> changeMe; 

public:
	Pomjeranje();
	Kocka AKolone(Kocka, int, int);
	Kocka ARedovi(Kocka, int, int);

	Kocka BKolone(Kocka, int, int);
	Kocka BRedovi(Kocka, int, int);

	Kocka CKolone(Kocka, int, int);
	Kocka CRedovi(Kocka, int, int);

	Kocka DKolone(Kocka, int, int);
	Kocka DRedovi(Kocka, int, int);

	Kocka EKolone(Kocka, int, int);
	Kocka ERedovi(Kocka, int, int);

	Kocka FKolone(Kocka, int, int);
	Kocka FRedovi(Kocka, int, int);
	~Pomjeranje();
};