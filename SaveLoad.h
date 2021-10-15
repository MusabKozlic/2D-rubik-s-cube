#pragma once
#include "Kocka.h"
#include "ShemaKocke.h"

class SaveLoad
{
private:
	ShemaKocke s;
public:
	SaveLoad(); 
	Kocka Load();
	void Save(Kocka);
	~SaveLoad();
};