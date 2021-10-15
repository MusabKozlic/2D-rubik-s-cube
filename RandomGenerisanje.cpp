#include "RandomGenerisanje.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
#include "ShemaKocke.h"

RandomGenerisanje::RandomGenerisanje()
{
}

Kocka RandomGenerisanje::generisiKocku()
{
	srand(time(NULL));
	Kocka k;
	ShemaKocke prikaz;
	k.setKocka();
	
		////////////////////////////////////////////////////////////////////////////////////
		//1. red stranica A, C, E i F
		int x = 0;
		int y = rand() % 2 + 1;
		while (x < y) {
			std::swap(k.A.Niz[0][0], k.C.Niz[0][0]);
			std::swap(k.A.Niz[0][1], k.C.Niz[0][1]);
			std::swap(k.A.Niz[0][2], k.C.Niz[0][2]);

			std::swap(k.E.Niz[0][0], k.A.Niz[0][0]);
			std::swap(k.E.Niz[0][1], k.A.Niz[0][1]);
			std::swap(k.E.Niz[0][2], k.A.Niz[0][2]);

			std::swap(k.F.Niz[0][0], k.E.Niz[0][0]);
			std::swap(k.F.Niz[0][1], k.E.Niz[0][1]);
			std::swap(k.F.Niz[0][2], k.E.Niz[0][2]);

			x++;
			k.B.Niz = okreniStranu90stepeni(k.B.Niz);
		}

		//2. red stranica A, C, E i F
		x = 0;
		y = rand() % 2 + 1;
		while (x < y) {
			std::swap(k.A.Niz[1][0], k.C.Niz[1][0]);
			std::swap(k.A.Niz[1][1], k.C.Niz[1][1]);
			std::swap(k.A.Niz[1][2], k.C.Niz[1][2]);

			std::swap(k.E.Niz[1][0], k.A.Niz[1][0]);
			std::swap(k.E.Niz[1][1], k.A.Niz[1][1]);
			std::swap(k.E.Niz[1][2], k.A.Niz[1][2]);

			std::swap(k.F.Niz[1][0], k.E.Niz[1][0]);
			std::swap(k.F.Niz[1][1], k.E.Niz[1][1]);
			std::swap(k.F.Niz[1][2], k.E.Niz[1][2]);
			x++;
		}

		//3. red stranica A, C, E i F
		x = 0;
		y = rand() % 2 + 1;
		while (x < y) {
			std::swap(k.A.Niz[2][0], k.C.Niz[2][0]);
			std::swap(k.A.Niz[2][1], k.C.Niz[2][1]);
			std::swap(k.A.Niz[2][2], k.C.Niz[2][2]);

			std::swap(k.E.Niz[2][0], k.A.Niz[2][0]);
			std::swap(k.E.Niz[2][1], k.A.Niz[2][1]);
			std::swap(k.E.Niz[2][2], k.A.Niz[2][2]);

			std::swap(k.F.Niz[2][0], k.E.Niz[2][0]);
			std::swap(k.F.Niz[2][1], k.E.Niz[2][1]);
			std::swap(k.F.Niz[2][2], k.E.Niz[2][2]);
			x++;
			k.D.Niz = okreniStranu90stepeni(k.D.Niz);
		}

		///////////////////////////////////////////////////////////////////
		//Strana B - red 1 - odrazava se na strane C, D i E (B - D; C - E)
		x = 0;
		y = rand() % 2 + 1;
		while (x < y) {
			std::swap(k.B.Niz[0][0], k.C.Niz[0][2]);
			std::swap(k.B.Niz[0][1], k.C.Niz[1][2]);
			std::swap(k.B.Niz[0][2], k.C.Niz[2][2]);

			std::swap(k.D.Niz[2][0], k.E.Niz[0][0]);
			std::swap(k.D.Niz[2][1], k.E.Niz[1][0]);
			std::swap(k.D.Niz[2][2], k.E.Niz[2][0]);

			std::swap(k.B.Niz[0][0], k.D.Niz[2][2]);
			std::swap(k.B.Niz[0][1], k.D.Niz[2][1]);
			std::swap(k.B.Niz[0][2], k.D.Niz[2][0]);

			x++;
			k.F.Niz = okreniStranuMinus90stepeni(k.F.Niz);
		}

		//Strana B - red 2 - odrazava se na strane C, D i E (B - D; C - E)
		x = 0;
		y = rand() % 2 + 1;
		while (x < y) {
			std::swap(k.B.Niz[1][0], k.C.Niz[0][1]);
			std::swap(k.B.Niz[1][1], k.C.Niz[1][1]);
			std::swap(k.B.Niz[1][2], k.C.Niz[2][1]);

			std::swap(k.D.Niz[1][0], k.E.Niz[0][1]);
			std::swap(k.D.Niz[1][1], k.E.Niz[1][1]);
			std::swap(k.D.Niz[1][2], k.E.Niz[2][1]);

			std::swap(k.B.Niz[1][0], k.D.Niz[1][2]);
			std::swap(k.B.Niz[1][1], k.D.Niz[1][1]);
			std::swap(k.B.Niz[1][2], k.D.Niz[1][0]);

			x++;
		}

		//Strana B - red 3 - odrazava se na strane C, D i E (B - D; C - E)
		x = 0;
		y = rand() % 2 + 1;
		while (x < y) {
			std::swap(k.B.Niz[2][0], k.C.Niz[0][0]);
			std::swap(k.B.Niz[2][1], k.C.Niz[1][0]);
			std::swap(k.B.Niz[2][2], k.C.Niz[2][0]);

			std::swap(k.D.Niz[0][0], k.E.Niz[0][2]);
			std::swap(k.D.Niz[0][1], k.E.Niz[1][2]);
			std::swap(k.D.Niz[0][2], k.E.Niz[2][2]);

			std::swap(k.B.Niz[2][0], k.D.Niz[0][2]);
			std::swap(k.B.Niz[2][1], k.D.Niz[0][1]);
			std::swap(k.B.Niz[2][2], k.D.Niz[0][0]);

			x++;
			k.A.Niz = okreniStranu90stepeni(k.A.Niz);
		}

		//////////////////////////////////////////////////////////////////////////
		//Kolona 1 - strane: B, A, D i F - vertikalno
		//Strana F - mijenja lijevu i desnu stranu na osnovu sheme
		x = 0;
		y = rand() % 2 + 1;
		while (x < y) {
			std::swap(k.B.Niz[0][0], k.A.Niz[0][0]);
			std::swap(k.B.Niz[1][0], k.A.Niz[1][0]);
			std::swap(k.B.Niz[2][0], k.A.Niz[2][0]);

			std::swap(k.B.Niz[0][0], k.D.Niz[0][0]);
			std::swap(k.B.Niz[1][0], k.D.Niz[1][0]);
			std::swap(k.B.Niz[2][0], k.D.Niz[2][0]);

			std::swap(k.B.Niz[0][0], k.F.Niz[2][2]);
			std::swap(k.B.Niz[1][0], k.F.Niz[1][2]);
			std::swap(k.B.Niz[2][0], k.F.Niz[0][2]);
			x++;
			k.E.Niz = okreniStranu90stepeni(k.E.Niz);
		}

		//Kolona 2 strane: B, A, D i F
		x = 0;
		y = rand() % 2 + 1;
		while (x < y) {
			std::swap(k.B.Niz[0][1], k.A.Niz[0][1]);
			std::swap(k.B.Niz[1][1], k.A.Niz[1][1]);
			std::swap(k.B.Niz[2][1], k.A.Niz[2][1]);

			std::swap(k.B.Niz[0][1], k.D.Niz[0][1]);
			std::swap(k.B.Niz[1][1], k.D.Niz[1][1]);
			std::swap(k.B.Niz[2][1], k.D.Niz[2][1]);

			std::swap(k.B.Niz[0][1], k.F.Niz[2][1]);
			std::swap(k.B.Niz[1][1], k.F.Niz[1][1]);
			std::swap(k.B.Niz[2][1], k.F.Niz[0][1]);

			x++;
		}

		//Kolona 3 strane B, A, D i F
		x = 0;
		y = rand() % 2 + 1;
		while (x < y) {
			std::swap(k.B.Niz[0][2], k.A.Niz[0][2]);
			std::swap(k.B.Niz[1][2], k.A.Niz[1][2]);
			std::swap(k.B.Niz[2][2], k.A.Niz[2][2]);

			std::swap(k.B.Niz[0][2], k.D.Niz[0][2]);
			std::swap(k.B.Niz[1][2], k.D.Niz[1][2]);
			std::swap(k.B.Niz[2][2], k.D.Niz[2][2]);

			std::swap(k.B.Niz[0][2], k.F.Niz[2][0]);
			std::swap(k.B.Niz[1][2], k.F.Niz[1][0]);
			std::swap(k.B.Niz[2][2], k.F.Niz[0][0]);

			x++;
			k.C.Niz = okreniStranuMinus90stepeni(k.C.Niz);
		}

		////////////////////////////////////////////////////////////////
		//1. red, strane: A C E i F
		 x = 0;
		 y = rand() % 2 + 1;
		while (x < y) {
			std::swap(k.A.Niz[0][0], k.C.Niz[0][0]);
			std::swap(k.A.Niz[0][1], k.C.Niz[0][1]);
			std::swap(k.A.Niz[0][2], k.C.Niz[0][2]);

			std::swap(k.E.Niz[0][0], k.A.Niz[0][0]);
			std::swap(k.E.Niz[0][1], k.A.Niz[0][1]);
			std::swap(k.E.Niz[0][2], k.A.Niz[0][2]);

			std::swap(k.F.Niz[0][0], k.E.Niz[0][0]);
			std::swap(k.F.Niz[0][1], k.E.Niz[0][1]);
			std::swap(k.F.Niz[0][2], k.E.Niz[0][2]);

			x++;
			k.B.Niz = okreniStranu90stepeni(k.B.Niz);
		}

		//Strana B - red 1 - odrazava se na strane C, D i E 
		//(B - D; C - E)
		x = 0;
		y = rand() % 2 + 1;
		while (x < y) {
			std::swap(k.B.Niz[0][0], k.C.Niz[0][2]);
			std::swap(k.B.Niz[0][1], k.C.Niz[1][2]);
			std::swap(k.B.Niz[0][2], k.C.Niz[2][2]);

			std::swap(k.D.Niz[2][0], k.E.Niz[0][0]);
			std::swap(k.D.Niz[2][1], k.E.Niz[1][0]);
			std::swap(k.D.Niz[2][2], k.E.Niz[2][0]);

			std::swap(k.B.Niz[0][0], k.D.Niz[2][2]);
			std::swap(k.B.Niz[0][1], k.D.Niz[2][1]);
			std::swap(k.B.Niz[0][2], k.D.Niz[2][0]);

			x++;
			k.F.Niz = okreniStranuMinus90stepeni(k.F.Niz);
		}

		//Kolona 1 - strane: B, A, D i F - vertikalno
		//Strana F - mijenja lijevu i desnu stranu na osnovu sheme
		x = 0;
		y = rand() % 2 + 1;
		while (x < y) {
			std::swap(k.B.Niz[0][0], k.A.Niz[0][0]);
			std::swap(k.B.Niz[1][0], k.A.Niz[1][0]);
			std::swap(k.B.Niz[2][0], k.A.Niz[2][0]);

			std::swap(k.B.Niz[0][0], k.D.Niz[0][0]);
			std::swap(k.B.Niz[1][0], k.D.Niz[1][0]);
			std::swap(k.B.Niz[2][0], k.D.Niz[2][0]);

			std::swap(k.B.Niz[0][0], k.F.Niz[2][2]);
			std::swap(k.B.Niz[1][0], k.F.Niz[1][2]);
			std::swap(k.B.Niz[2][0], k.F.Niz[0][2]);
			x++;
			k.E.Niz = okreniStranu90stepeni(k.E.Niz);
		}

		//2. red, strane: A, C, E i F
		x = 0;
		y = rand() % 2 + 1;
		while (x < y) {
			std::swap(k.A.Niz[1][0], k.C.Niz[1][0]);
			std::swap(k.A.Niz[1][1], k.C.Niz[1][1]);
			std::swap(k.A.Niz[1][2], k.C.Niz[1][2]);

			std::swap(k.E.Niz[1][0], k.A.Niz[1][0]);
			std::swap(k.E.Niz[1][1], k.A.Niz[1][1]);
			std::swap(k.E.Niz[1][2], k.A.Niz[1][2]);

			std::swap(k.F.Niz[1][0], k.E.Niz[1][0]);
			std::swap(k.F.Niz[1][1], k.E.Niz[1][1]);
			std::swap(k.F.Niz[1][2], k.E.Niz[1][2]);
			x++;
		}

		//Strana B - red 2 - odrazava se na strane C, D i E
		//(B - D; C - E)
		x = 0;
		y = rand() % 2 + 1;
		while (x < y) {
			std::swap(k.B.Niz[1][0], k.C.Niz[0][1]);
			std::swap(k.B.Niz[1][1], k.C.Niz[1][1]);
			std::swap(k.B.Niz[1][2], k.C.Niz[2][1]);

			std::swap(k.D.Niz[1][0], k.E.Niz[0][1]);
			std::swap(k.D.Niz[1][1], k.E.Niz[1][1]);
			std::swap(k.D.Niz[1][2], k.E.Niz[2][1]);

			std::swap(k.B.Niz[1][0], k.D.Niz[1][2]);
			std::swap(k.B.Niz[1][1], k.D.Niz[1][1]);
			std::swap(k.B.Niz[1][2], k.D.Niz[1][0]);

			x++;
		}

		//Kolona 2 strane: B, A, D i F
		x = 0;
		y = rand() % 2 + 1;
		while (x < y) {
			std::swap(k.B.Niz[0][1], k.A.Niz[0][1]);
			std::swap(k.B.Niz[1][1], k.A.Niz[1][1]);
			std::swap(k.B.Niz[2][1], k.A.Niz[2][1]);

			std::swap(k.B.Niz[0][1], k.D.Niz[0][1]);
			std::swap(k.B.Niz[1][1], k.D.Niz[1][1]);
			std::swap(k.B.Niz[2][1], k.D.Niz[2][1]);

			std::swap(k.B.Niz[0][1], k.F.Niz[2][1]);
			std::swap(k.B.Niz[1][1], k.F.Niz[1][1]);
			std::swap(k.B.Niz[2][1], k.F.Niz[0][1]);

			x++;
		}
	return k;
}

std::vector<std::vector<int>> RandomGenerisanje::okreniStranu90stepeni(std::vector<std::vector<int>> Arr)
{
	std::swap(Arr[0][0], Arr[0][2]);
	std::swap(Arr[0][0], Arr[2][2]);
	std::swap(Arr[0][0], Arr[2][0]);

	std::swap(Arr[0][1], Arr[1][2]);
	std::swap(Arr[0][1], Arr[2][1]);
	std::swap(Arr[0][1], Arr[1][0]);

	return Arr;
}

std::vector<std::vector<int>> RandomGenerisanje::okreniStranuMinus90stepeni(std::vector<std::vector<int>> Arr)
{
	std::swap(Arr[0][0], Arr[2][0]);
	std::swap(Arr[0][0], Arr[2][2]);
	std::swap(Arr[0][0], Arr[0][2]);

	std::swap(Arr[0][1], Arr[1][0]);
	std::swap(Arr[0][1], Arr[2][1]);
	std::swap(Arr[0][1], Arr[1][2]);

	return Arr;
}

RandomGenerisanje::~RandomGenerisanje()
{
}