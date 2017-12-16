#pragma once
#include <vector>
#include <type_traits>
//#include <boost/utility/enable_if.hpp>
//#include <boost/type_traits/is_arithmetic.hpp>

#include "Card.h"

using namespace std;

template<typename T>
class Deck
{
public:
	Deck();
	~Deck();
	void initialisation();
	void shuffleCards();
	T dealCard();
	void printDeck();

	int cardToDeal() { return card_to_deal_; }

private:
	vector<T> cards_;
	int card_to_deal_ = 0;
};