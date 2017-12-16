#pragma once
#include <vector>
#include <type_traits>
#include "Deck.h"

template<typename T>
class Hand
{
public:
	Hand();
	~Hand();

	int score();
	void addCard(T& card);

private:
	vector<T> cards_;

};

