#include "Pomjeranje.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

int y = 2;
int z = 2;

RandomGenerisanje devedeset;

Pomjeranje::Pomjeranje()
{
}

//Pomjeranje kolona stranice A
Kocka Pomjeranje::AKolone(Kocka kocka, int smjer, int KR)
{
	y = 2;
	switch (KR) {
	case 1:
		z = 2;
		break;
	case 2:
		z = 0;
		break;
	case 3:
		z = -2;
		break;
	}
	if (smjer == 1) {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.A.Niz[x][KR - 1], kocka.B.Niz[x][KR - 1]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.A.Niz[x][KR - 1], kocka.F.Niz[y][KR + z - 1]);
			y--;
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.A.Niz[x][KR - 1], kocka.D.Niz[x][KR - 1]);
		}
	}
	else {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.A.Niz[x][KR - 1], kocka.D.Niz[x][KR - 1]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.A.Niz[x][KR - 1], kocka.F.Niz[y][KR + z - 1]);
			y--;
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.A.Niz[x][KR - 1], kocka.B.Niz[x][KR - 1]);
		}
	}

	if (KR == 1) {
		if (smjer == 1) {
			kocka.E.Niz = devedeset.okreniStranuMinus90stepeni(kocka.E.Niz);
		}
		else {
			kocka.E.Niz = devedeset.okreniStranu90stepeni(kocka.E.Niz);
		}
	}
	else if (KR == 3) {
		if (smjer == 1) {
			kocka.C.Niz = devedeset.okreniStranu90stepeni(kocka.C.Niz);
		}
		else {
			kocka.C.Niz = devedeset.okreniStranuMinus90stepeni(kocka.C.Niz);
		}
	}
	return kocka;
}

//Pomjeranje redova stranice A
Kocka Pomjeranje::ARedovi(Kocka kocka, int smjer, int KR)
{
	if (smjer == 1) {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.A.Niz[KR - 4][x], kocka.C.Niz[KR - 4][x]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.A.Niz[KR - 4][x], kocka.F.Niz[KR - 4][x]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.A.Niz[KR - 4][x], kocka.E.Niz[KR - 4][x]);
		}
	}
	else {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.A.Niz[KR - 4][x], kocka.E.Niz[KR - 4][x]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.A.Niz[KR - 4][x], kocka.F.Niz[KR - 4][x]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.A.Niz[KR - 4][x], kocka.C.Niz[KR - 4][x]);
		}
	}
	if (KR == 4) {
		if (smjer == 1) {
			kocka.B.Niz = devedeset.okreniStranuMinus90stepeni(kocka.B.Niz);
		}
		else {
			kocka.B.Niz = devedeset.okreniStranu90stepeni(kocka.B.Niz);
		}
	}
	else if (KR == 6) {
		if (smjer == 1) {
			kocka.D.Niz = devedeset.okreniStranu90stepeni(kocka.D.Niz);
		}
		else {
			kocka.D.Niz = devedeset.okreniStranuMinus90stepeni(kocka.D.Niz);
		}
	}
	return kocka;
}

/////////////////////////////////////////////////////////////////////////
//Pomjeranje kolona stranice B
Kocka Pomjeranje::BKolone(Kocka kocka, int smjer, int KR)
{
	switch (KR) {
	case 1:
		z = 2;
		break;
	case 2:
		z = 0;
		break;
	case 3:
		z = -2;
		break;
	}
	y = 2;

	if (smjer == 1) {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.B.Niz[x][KR - 1], kocka.F.Niz[y][KR + z - 1]);
			y--;
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.B.Niz[x][KR - 1], kocka.D.Niz[x][KR - 1]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.B.Niz[x][KR - 1], kocka.A.Niz[x][KR - 1]);
		}
	}
	else {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.B.Niz[x][KR - 1], kocka.A.Niz[x][KR - 1]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.B.Niz[x][KR - 1], kocka.D.Niz[x][KR - 1]);
		}
		y = 2;
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.B.Niz[x][KR - 1], kocka.F.Niz[y][KR + z - 1]);
			y--;
		}
	}
	if (KR == 1) {
		if (smjer == 1) {
			kocka.E.Niz = devedeset.okreniStranuMinus90stepeni(kocka.E.Niz);
		}
		else {
			kocka.E.Niz = devedeset.okreniStranu90stepeni(kocka.E.Niz);
		}
	}
	else if (KR == 3) {
		if (smjer == 1) {
			kocka.C.Niz = devedeset.okreniStranu90stepeni(kocka.C.Niz);
		}
		else {
			kocka.C.Niz = devedeset.okreniStranuMinus90stepeni(kocka.C.Niz);
		}
	}
	return kocka;
}

//Pomjeranje redova stranice B
Kocka Pomjeranje::BRedovi(Kocka kocka, int smjer, int KR)
{
	y = 2;
	switch (KR) {
	case 4:
		z = 2;
		break;
	case 5:
		z = 0;
		break;
	case 6:
		z = -2;
		break;
	}
	if (smjer == 1) {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.B.Niz[KR - 4][x], kocka.C.Niz[x][KR - 4 + z]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.B.Niz[KR - 4][x], kocka.D.Niz[KR - 4 + z][y]);
			y--;
		}
		y = 2;
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.B.Niz[KR - 4][x], kocka.E.Niz[y][KR - 4]);
			y--;
		}
	}
	else {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.B.Niz[KR - 4][x], kocka.E.Niz[y][KR - 4]);
			y--;
		}
		y = 2;
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.B.Niz[KR - 4][x], kocka.D.Niz[KR - 4 + z][y]);
			y--;
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.B.Niz[KR - 4][x], kocka.C.Niz[x][KR - 4 + z]);
		}
	}

	if (KR == 4) {
		if (smjer == 1) {
			kocka.F.Niz = devedeset.okreniStranuMinus90stepeni(kocka.F.Niz);
		}
		else {
			kocka.F.Niz = devedeset.okreniStranu90stepeni(kocka.F.Niz);
		}
	}
	else if (KR == 6) {
		if (smjer == 1) {
			kocka.A.Niz = devedeset.okreniStranu90stepeni(kocka.A.Niz);
		}
		else {
			kocka.A.Niz = devedeset.okreniStranuMinus90stepeni(kocka.A.Niz);
		}
	}
	return kocka;
}

/////////////////////////////////////////////////////////////////////////
//Pomjeranje kolona stranice C
Kocka Pomjeranje::CKolone(Kocka kocka, int smjer, int KR)
{
	y = 2;

	switch (KR) {
	case 1:
		z = 2;
		break;
	case 2:
		z = 0;
		break;
	case 3:
		z = -2;
		break;
	}

	if (smjer == 1) {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.C.Niz[x][KR - 1], kocka.B.Niz[KR + z - 1][x]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.C.Niz[x][KR - 1], kocka.E.Niz[y][KR + z - 1]);
			y--;
		}
		y = 2;
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.C.Niz[x][KR - 1], kocka.D.Niz[KR - 1][y]);
			y--;
		}
	}
	else {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.C.Niz[x][KR - 1], kocka.D.Niz[KR - 1][y]);
			y--;
		}
		y = 2;
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.C.Niz[x][KR - 1], kocka.E.Niz[y][KR + z - 1]);
			y--;
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.C.Niz[x][KR - 1], kocka.B.Niz[KR + z - 1][x]);
		}
	}

	if (KR == 1) {
		if (smjer == 1) {
			kocka.A.Niz = devedeset.okreniStranuMinus90stepeni(kocka.A.Niz);
		}
		else {
			kocka.A.Niz = devedeset.okreniStranu90stepeni(kocka.A.Niz);
		}
	}
	else if (KR == 3) {
		if (smjer == 1) {
			kocka.F.Niz = devedeset.okreniStranu90stepeni(kocka.F.Niz);
		}
		else {
			kocka.F.Niz = devedeset.okreniStranuMinus90stepeni(kocka.F.Niz);
		}
	}
	return kocka;
}

//Pomjeranje redova stranice C
Kocka Pomjeranje::CRedovi(Kocka kocka, int smjer, int KR)
{
	if (smjer == 1) {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.C.Niz[KR - 4][x], kocka.F.Niz[KR - 4][x]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.C.Niz[KR - 4][x], kocka.E.Niz[KR - 4][x]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.C.Niz[KR - 4][x], kocka.A.Niz[KR - 4][x]);
		}
	}
	else {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.C.Niz[KR - 4][x], kocka.A.Niz[KR - 4][x]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.C.Niz[KR - 4][x], kocka.E.Niz[KR - 4][x]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.C.Niz[KR - 4][x], kocka.F.Niz[KR - 4][x]);
		}
	}

	if (KR == 4) {
		if (smjer == 1) {
			kocka.B.Niz = devedeset.okreniStranuMinus90stepeni(kocka.B.Niz);
		}
		else {
			kocka.B.Niz = devedeset.okreniStranu90stepeni(kocka.B.Niz);
		}
	}
	else if (KR == 6) {
		if (smjer == 1) {
			kocka.D.Niz = devedeset.okreniStranu90stepeni(kocka.D.Niz);
		}
		else {
			kocka.D.Niz = devedeset.okreniStranuMinus90stepeni(kocka.D.Niz);
		}
	}
	return kocka;
}
/////////////////////////////////////////////////////////////////////////
//Pomjeranje kolona stranice D
Kocka Pomjeranje::DKolone(Kocka kocka, int smjer, int KR)
{
	y = 2;
	switch (KR) {
	case 1:
		z = 2;
		break;
	case 2:
		z = 0;
		break;
	case 3:
		z = -2;
		break;
	}
	if (smjer == 1) {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.D.Niz[x][KR - 1], kocka.A.Niz[x][KR - 1]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.D.Niz[x][KR - 1], kocka.B.Niz[x][KR - 1]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.D.Niz[x][KR - 1], kocka.F.Niz[y][KR - 1 + z]);
			y--;
		}
	}
	else {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.D.Niz[x][KR - 1], kocka.F.Niz[y][KR + z - 1]);
			y--;
		}
		y = 2;
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.D.Niz[x][KR - 1], kocka.B.Niz[x][KR - 1]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.D.Niz[x][KR - 1], kocka.A.Niz[x][KR - 1]);
		}
	}
	if (KR == 1) {
		if (smjer == 1) {
			kocka.E.Niz = devedeset.okreniStranuMinus90stepeni(kocka.E.Niz);
		}
		else {
			kocka.E.Niz = devedeset.okreniStranu90stepeni(kocka.E.Niz);
		}
	}
	else if (KR == 3) {
		if (smjer == 1) {
			kocka.C.Niz = devedeset.okreniStranu90stepeni(kocka.C.Niz);
		}
		else {
			kocka.C.Niz = devedeset.okreniStranuMinus90stepeni(kocka.C.Niz);
		}
	}
	return kocka;
}

//Pomjeranje redova stranice D
Kocka Pomjeranje::DRedovi(Kocka kocka, int smjer, int KR)
{
	y = 2;
	switch (KR) {
	case 4:
		z = 2;
		break;
	case 5:
		z = 0;
		break;
	case 6:
		z = -2;
		break;
	}
	if (smjer == 1) {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.D.Niz[KR - 4][x], kocka.C.Niz[y][KR - 4]);
			y--;
		}
		y = 2;
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.D.Niz[KR - 4][x], kocka.B.Niz[KR - 4 + z][y]);
			y--;
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.D.Niz[KR - 4][x], kocka.E.Niz[x][KR - 4 + z]);
		}
	}
	else {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.D.Niz[KR - 4][x], kocka.E.Niz[x][KR - 4 + z]);
		}
		y = 2;
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.D.Niz[KR - 4][x], kocka.B.Niz[KR - 4 + z][y]);
			y--;
		}
		y = 2;
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.D.Niz[KR - 4][x], kocka.C.Niz[y][KR - 4]);
			y--;
		}
	}
	if (KR == 4) {
		if (smjer == 1) {
			kocka.A.Niz = devedeset.okreniStranuMinus90stepeni(kocka.A.Niz);
		}
		else {
			kocka.A.Niz = devedeset.okreniStranu90stepeni(kocka.A.Niz);
		}
	}
	else if (KR == 6) {
		if (smjer == 1) {
			kocka.F.Niz = devedeset.okreniStranu90stepeni(kocka.F.Niz);
		}
		else {
			kocka.F.Niz = devedeset.okreniStranuMinus90stepeni(kocka.F.Niz);
		}
	}
	return kocka;
}

/////////////////////////////////////////////////////////////////////////
//Pomjeranje kolona stranice E
Kocka Pomjeranje::EKolone(Kocka kocka, int smjer, int KR)
{
	y = 2;

	switch (KR) {
	case 1:
		z = 2;
		break;
	case 2:
		z = 0;
		break;
	case 3:
		z = -2;
		break;
	}
	if (smjer == 1) {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.E.Niz[x][KR - 1], kocka.B.Niz[KR - 1][y]);
			y--;
		}
		y = 2;
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.E.Niz[x][KR - 1], kocka.C.Niz[y][KR + z - 1]);
			y--;
		}
		y = 2;
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.E.Niz[x][KR - 1], kocka.D.Niz[KR - 1 + z][x]);
		}
	}
	else {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.E.Niz[x][KR - 1], kocka.D.Niz[KR - 1 + z][x]);
		}
		y = 2;
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.E.Niz[x][KR - 1], kocka.C.Niz[y][KR + z - 1]);
			y--;
		}

		y = 2;
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.E.Niz[x][KR - 1], kocka.B.Niz[KR - 1][y]);
			y--;
		}
	}

	if (KR == 1) {
		if (smjer == 1) {
			kocka.F.Niz = devedeset.okreniStranuMinus90stepeni(kocka.F.Niz);
		}
		else {
			kocka.F.Niz = devedeset.okreniStranu90stepeni(kocka.F.Niz);
		}
	}
	else if (KR == 3) {
		if (smjer == 1) {
			kocka.A.Niz = devedeset.okreniStranu90stepeni(kocka.A.Niz);
		}
		else {
			kocka.A.Niz = devedeset.okreniStranuMinus90stepeni(kocka.A.Niz);
		}
	}
	return kocka;
}

//Pomjeranje redova stranice E
Kocka Pomjeranje::ERedovi(Kocka kocka, int smjer, int KR)
{
	if (smjer == 1) {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.E.Niz[KR - 4][x], kocka.A.Niz[KR - 4][x]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.E.Niz[KR - 4][x], kocka.C.Niz[KR - 4][x]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.E.Niz[KR - 4][x], kocka.F.Niz[KR - 4][x]);
		}
	}
	else {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.E.Niz[KR - 4][x], kocka.F.Niz[KR - 4][x]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.E.Niz[KR - 4][x], kocka.C.Niz[KR - 4][x]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.E.Niz[KR - 4][x], kocka.A.Niz[KR - 4][x]);
		}
	}

		if (KR == 4) {
		if (smjer == 1) {
			kocka.B.Niz = devedeset.okreniStranuMinus90stepeni(kocka.B.Niz);
		}
		else {
			kocka.B.Niz = devedeset.okreniStranu90stepeni(kocka.B.Niz);
		}
	}
	else if (KR == 6) {
		if (smjer == 1) {
			kocka.D.Niz = devedeset.okreniStranu90stepeni(kocka.D.Niz);
		}
		else {
			kocka.D.Niz = devedeset.okreniStranuMinus90stepeni(kocka.D.Niz);
		}
	}
		if (KR == 4) {
			if (smjer == 1) {
				kocka.B.Niz = devedeset.okreniStranuMinus90stepeni(kocka.B.Niz);
			}
			else {
				kocka.B.Niz = devedeset.okreniStranu90stepeni(kocka.B.Niz);
			}
		}
		else if (KR == 6) {
			if (smjer == 1) {
				kocka.D.Niz = devedeset.okreniStranu90stepeni(kocka.D.Niz);
			}
			else {
				kocka.D.Niz = devedeset.okreniStranuMinus90stepeni(kocka.D.Niz);
			}
		}
	return kocka;
}

/////////////////////////////////////////////////////////////////////////
//Pomjeranje kolona stranice F
Kocka Pomjeranje::FKolone(Kocka kocka, int smjer, int KR)
{
	y = 2;
	switch (KR) {
	case 1:
		z = 2;
		break;
	case 2:
		z = 0;
		break;
	case 3:
		z = -2;
		break;
	}
	if (smjer == 1) {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.F.Niz[x][KR - 1], kocka.B.Niz[y][KR + z - 1]);
			y--;
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.F.Niz[x][KR - 1], kocka.A.Niz[x][KR + z - 1]);
		}
		y = 2;
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.F.Niz[x][KR - 1], kocka.D.Niz[x][KR + z - 1]);
		}
		std::swap(kocka.F.Niz[0][KR - 1], kocka.F.Niz[2][KR - 1]);
	}
	else {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.F.Niz[x][KR - 1], kocka.D.Niz[y][KR - 1 + z]);
			y--;
		}
		y = 2;
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.F.Niz[x][KR - 1], kocka.A.Niz[y][KR + z - 1]);
			y--;
		}
		y = 2;
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.F.Niz[x][KR - 1], kocka.B.Niz[y][KR - 1 + z]);
			y--;
		}
	}

	if (KR == 1) {
		if (smjer == 1) {
			kocka.C.Niz = devedeset.okreniStranuMinus90stepeni(kocka.C.Niz);
		}
		else {
			kocka.C.Niz = devedeset.okreniStranu90stepeni(kocka.C.Niz);
		}
	}
	else if (KR == 3) {
		if (smjer == 1) {
			kocka.E.Niz = devedeset.okreniStranu90stepeni(kocka.E.Niz);
		}
		else {
			kocka.E.Niz = devedeset.okreniStranuMinus90stepeni(kocka.E.Niz);
		}
	}
	return kocka;
}

//Pomjeranje redova stranice F
Kocka Pomjeranje::FRedovi(Kocka kocka, int smjer, int KR)
{
	if (smjer == 1) {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.F.Niz[KR - 4][x], kocka.E.Niz[KR - 4][x]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.F.Niz[KR - 4][x], kocka.A.Niz[KR - 4][x]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.F.Niz[KR - 4][x], kocka.C.Niz[KR - 4][x]);
		}
	}
	else {
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.F.Niz[KR - 4][x], kocka.C.Niz[KR - 4][x]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.F.Niz[KR - 4][x], kocka.A.Niz[KR - 4][x]);
		}
		for (int x = 0; x < 3; x++) {
			std::swap(kocka.F.Niz[KR - 4][x], kocka.E.Niz[KR - 4][x]);
		}
	}

	if (KR == 4) {
		if (smjer == 1) {
			kocka.B.Niz = devedeset.okreniStranuMinus90stepeni(kocka.B.Niz);
		}
		else {
			kocka.B.Niz = devedeset.okreniStranu90stepeni(kocka.B.Niz);
		}
	}
	else if (KR == 6) {
		if (smjer == 1) {
			kocka.D.Niz = devedeset.okreniStranu90stepeni(kocka.D.Niz);
		}
		else {
			kocka.D.Niz = devedeset.okreniStranuMinus90stepeni(kocka.D.Niz);
		}
	}
	return kocka;
}

Pomjeranje::~Pomjeranje()
{
}