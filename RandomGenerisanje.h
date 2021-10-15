#pragma once
#include "Kocka.cpp"
#include "Strana.cpp"
#include <vector>
 
class RandomGenerisanje
{
public:
	RandomGenerisanje();
	Kocka generisiKocku();
	std::vector<std::vector<int>> okreniStranu90stepeni(std::vector<std::vector<int>> Arr);
	std::vector<std::vector<int>> okreniStranuMinus90stepeni(std::vector<std::vector<int>> Arr);
	~RandomGenerisanje();
};