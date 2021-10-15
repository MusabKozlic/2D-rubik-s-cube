#pragma once
#include "Strana.h"
class Kocka
{
public:
	Kocka();
	
	//6 objekata koji prestavljaju 6 strana kocke
	Strana A;
	Strana B;
	Strana C;
	Strana D;
	Strana E;
	Strana F;

	double time=0.0;
	int pokreti = 0;
	char smjer = 'n';
	int points = 0;
	bool meni = false;
	void setKocka();

	~Kocka();
};