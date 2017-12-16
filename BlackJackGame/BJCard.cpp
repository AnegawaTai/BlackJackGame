#include "stdafx.h"
#include "BJCard.h"


BJCard::BJCard(int idx) : Card(idx)
{
	switch (score_)
	{
	case 1:
		score_ = 11;	// Ace scroes 11
		break;
	case 11:
	case 12:
	case 13:
		score_ = 10;	// Face cards score 10
		break;
	default:
		break;
	}
}


BJCard::~BJCard()
{
}
