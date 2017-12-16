#include "stdafx.h"
#include "BlackJack.h"
#include <iostream>
#include <vector>
#include <string>



using namespace std;

BlackJack::BlackJack()
{
}


BlackJack::~BlackJack()
{
}

void BlackJack::playGame(const int players_num)
{
	BJPlayer dealer("Dealer");
	vector<BJPlayer> players;
	vector<BlackJackState> player_states;
	for (int i = 0; i < players_num; i++)
	{
		int id = i + 1;
		string player_name = "Player-" + to_string(id);
		players.push_back(BJPlayer(player_name));
		player_states.push_back(normal);
	}

	cout << "Blackjack Game Start!" << endl
		<< "Player numbers: " << players_num << endl;

	// create a deck and shuffle it.
	prepareDeck();

	// Initial deal: deal two visible cards to each player
	for (int i = 0; i < players_num; i++)
	{
		dealCard2Player(players[i], true);
		dealCard2Player(players[i], true);
		printPlayerScore(players[i]);
	}
	// deal one visible and one hole cards to dealer 
	dealCard2Player(dealer, true);
	dealCard2Player(dealer, false);

	BlackJackState dealer_state = checkBlackJack(dealer);
	if (dealer_state == exceeded)
	{
		cout << "Players win!" << endl;
		return;
	}
	else if (dealer_state == blackjack)
	{
		for (int i = 0; i < players_num; i++)
		{
			if (checkBlackJack(players[i]) == blackjack)
			{
				cout << "Draw." << endl;
			}
			else
			{
				printPlayerScore(players[i]);
				cout << "Dealer win!" << endl;
			}
		}
		return;
	}

	// hit or stand
	cout << "Players' turn" << endl;
	for (int i = 0; i < players_num; i++)
	{
		cout << "To " << players[i].getPlayerName() << ": " << endl;
		player_states[i] = checkBlackJack(players[i]);
		while (player_states[i] == normal)
		{
			int player_stand;
			cout << "Would you like to hit or stand? (1 - hit, 0 - stand)\n";
			cin >> player_stand;
			if (player_stand == 0) break; // stand
			dealCard2Player(players[i], true);
			printPlayerScore(players[i]);
			player_states[i] = checkBlackJack(players[i]);
		}
	}
	cout << "Dealer's turn" << endl;
	while (dealer.getPlayerScore() < 17)
	{
		dealCard2Player(dealer, false);
		dealer_state = checkBlackJack(dealer);
		if (dealer_state != normal)
			break;
	}

	if (dealer_state == exceeded)
	{
		for (int i = 0; i < players_num; i++)
		{
			if(player_states[i] != exceeded)
				cout << players[i].getPlayerName() << " wins!" << endl;
		}
		return;
	}
	else if (dealer_state == blackjack)
	{
		for (int i = 0; i < players_num; i++)
		{
			if (player_states[i] == blackjack)
			{
				cout << players[i].getPlayerName() << " draws." << endl;
			}
			else
			{
				printPlayerScore(players[i]);
				cout << "Dealer win!" << endl;
			}
		}
		return;
	}
	else 
	{
		printPlayerScore(dealer);
		int dealer_score = dealer.getPlayerScore();
		for (int i = 0; i < players_num; i++)
		{
			if (player_states[i] == blackjack)
			{
				cout << players[i].getPlayerName() << " has blackjack. "
					<< players[i].getPlayerName() << " wins!" << endl;
			}
			else if (player_states[i] == exceeded)
			{
				printPlayerScore(players[i]);
				cout << players[i].getPlayerName() << " busts. Dealer wins!" << endl;
			}
			else
			{
				printPlayerScore(players[i]);
				int player_score = players[i].getPlayerScore();
				if(dealer_score > player_score)
					cout << "Dealer wins!" << endl;
				else if (dealer_score == player_score)
					cout << players[i].getPlayerName() << " draws." << endl;
				else
					cout << players[i].getPlayerName() << " wins!" << endl;
			}
		}
	}

}

void BlackJack::prepareDeck()
{
	BJ_deck_.initialisation();
	cout << "Shuffling the decking...";
	BJ_deck_.shuffleCards();
	cout << "done" << endl;
}

void BlackJack::dealCard2Player(BJPlayer &p, bool is_open)
{
	int card2deal = BJ_deck_.cardToDeal();
	if (card2deal < BJCard::TOTAL_CARDS)
	{
		BJCard& card = BJ_deck_.dealCard();
		p.addCard(card);
		cout << "Deal one card to " << p.getPlayerName();
		if (is_open)
		{ 
			cout << ": "; 
			card.printCard();
		}
		cout << endl;
	}
	else
	{
		cerr << "Cannot deal a card anymore! The deck has run out of card!" << endl;
	}
}

BlackJackState BlackJack::checkBlackJack(BJPlayer & p)
{
	int score = p.getPlayerScore();
	if (score > 21)
	{
		cout << p.getPlayerName() << "'s hand exceeded 21! " 
			<< p.getPlayerName() << " busts!" << endl;
		return exceeded;
	}
	else if (score == 21)
	{ 
		cout << p.getPlayerName() << " has blackjack!" << endl;
		return blackjack;
	}
	return normal;
}

void BlackJack::printPlayerScore(BJPlayer & p)
{
	cout << p.getPlayerName() << "'s score£º " << p.getPlayerScore() << endl;
}
