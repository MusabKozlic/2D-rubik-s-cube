#pragma once
#include "Kocka.h"

//Klasa za ispis seme kocke, mijenjanje boje teksta i pozadine, kao i ispis glavnog menija
class ShemaKocke
{
private:
	Kocka k;
public:
	ShemaKocke();
	void changeColor(int desiredColor);
	void ispisSheme(Kocka);
	void glavniMeni();
	~ShemaKocke();
};