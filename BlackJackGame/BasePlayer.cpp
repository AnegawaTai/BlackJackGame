#include "stdafx.h"
#include "BasePlayer.h"

template<typename T>
BasePlayer<T>::BasePlayer(string name)
{
	// throw compiler error
	static_assert(is_base_of<Card, T>::value, "The template class of cards mush be a derivatived class of base class Card.");
	player_name_ = name;
}

template<typename T>
BasePlayer<T>::~BasePlayer()
{
}

template<typename T>
void BasePlayer<T>::addCard(T& card)
{
	hand.addCard(card);
}
