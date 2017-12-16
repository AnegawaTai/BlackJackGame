#pragma once
#include "Card.h"
class BJCard :
	public Card
{
public:
	BJCard(int idx);
	~BJCard();

private:
	bool open_hand_;
};

