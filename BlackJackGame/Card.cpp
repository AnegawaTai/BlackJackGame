#include "stdafx.h"
#include "Card.h"
#include <iostream>

const char* suitNames[] = { "Spade", "Diamond", "Club", "Heart" };

Card::Card(int idx)
{
	if (SetSuitAndValue(idx))
	{
		idx_ = idx;
		score_ = face_value_ + 1;
	}
	else
	{
		cerr << "invalid Card Index!" << endl;
	}
}

Card::~Card()
{
}

void Card::printCard()
{
	cout << suitNames[suit_] << " ";

	switch (face_value_)
	{
		case 0:
			cout << "A ";
			break;
		case 10:
			cout << "J ";
			break;
		case 11:
			cout << "Q ";
			break;
		case 12:
			cout << "K ";
			break;
		default:
			cout << face_value_ + 1 << " ";
	}
}

bool Card::SetSuitAndValue(int idx)
{
	if(idx < 0 || idx > 51)
		return false;

	suit_ = CardSuit(idx / 13);
	face_value_ = idx % 13;
	return true;
}
