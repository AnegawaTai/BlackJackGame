#pragma once

#include "BasePlayer.h"
#include "BasePlayer.cpp"
#include "Deck.h"
#include "Deck.cpp"
#include "BJCard.h"

typedef BasePlayer<BJCard> BJPlayer;
typedef Deck<BJCard> BJDeck;

enum BlackJackState {normal, blackjack, exceeded};

class BlackJack
{
public:
	BlackJack();
	~BlackJack();

	void playGame(const int players_num = 1);
private:
	void prepareDeck();	
	void dealCard2Player(BJPlayer &p, bool is_open);
	BlackJackState checkBlackJack(BJPlayer &p);
	void printPlayerScore(BJPlayer &p);

	BJDeck BJ_deck_;


};

