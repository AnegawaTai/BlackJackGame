#include "stdafx.h"
#include "Hand.h"

template<typename T>
Hand<T>::Hand()
{
	// throw compiler error
	static_assert(is_base_of<Card, T>::value, "The template class of cards mush be a derivatived class of base class Card.");
}

template<typename T>
Hand<T>::~Hand()
{
}

template<typename T>
int Hand<T>::score()
{
	int score_ = 0;
	for (int i = 0; i < cards_.size(); i++)
	{ 
		//cout << cards_[i].getScore() << endl;
		score_ += cards_[i].getScore();
	}
	return score_;
}

template<typename T>
void Hand<T>::addCard(T& card)
{
	if (card.isAvailable())
	{
		card.dealtCard();
		cards_.push_back(card);
	}
}
