#include "stdafx.h"
#include "Deck.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

template<typename T>
Deck<T>::Deck()
{
	// throw compiler error
	static_assert(is_base_of<Card, T>::value, "The template class of cards mush be a derivatived class of base class Card.");
}


template<typename T>
Deck<T>::~Deck()
{
}

template<typename T>
void Deck<T>::initialisation()
{
	for (int i = 0; i < T::TOTAL_CARDS; i++)
	{
		cards_.push_back(T(i));
	}
}

template<typename T>
void Deck<T>::shuffleCards()
{
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();

	shuffle(cards_.begin(), cards_.end(), default_random_engine(seed));
}

// TODO:exception handling 
template<typename T>
T Deck<T>::dealCard()
{
	return cards_[card_to_deal_++];
}

template<typename T>
void Deck<T>::printDeck()
{
	vector<T>::iterator it = cards_.begin();
	for (; it != cards_.end(); it++)
	{
		it->printCard();
		cout << endl;
	}
}
