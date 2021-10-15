#pragma once
#include "Kocka.h"
#include "Pomjeranje.h"
#include "Strana.cpp"
#include "ShemaKocke.h"
#include "RandomGenerisanje.h"

enum EnumyDirection {NONE = 0, RIGHT, LEFT, UP, DOWN};

//Klasa koja sluzi za pokretanje redova u kolona
class Pokret
{
private:
	ShemaKocke s;
public:
	Pokret();
	virtual Kocka pokret(Kocka,int);
    static int smjer;
	EnumyDirection smjerovi;
	~Pokret();
};

class Arcade :
	public Pokret 
{
private:
	ShemaKocke s;
public:
	Arcade() : Pokret() {};
	Kocka pokret(Kocka,int);
	static int smjer;
	~Arcade();
};