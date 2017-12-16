#pragma once

#include "Hand.h"
#include "Hand.cpp"

template<typename T>
class BasePlayer
{
public:
	BasePlayer(string name = "");
	~BasePlayer();

	void addCard(T& card);
	string getPlayerName() { return player_name_; }
	int getPlayerScore() { return hand.score(); }
	
private:
	string player_name_;
	Hand<T> hand;
};

