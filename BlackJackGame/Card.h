#pragma once

using namespace std;

extern const char* suitNames[];

enum CardSuit
{
	Spade,
	Diamond,
	Club,
	Heart
};

class Card
{
public:
	static const int TOTAL_CARDS = 52;
	Card(int idx);
	~Card();

	bool isAvailable() { return is_available_; }
	void dealtCard() { is_available_ = false; }

	void printCard();

	int getScore() { return score_; }

protected:
	int score_;
private:
	int idx_ = -1; // 0 - 51
	CardSuit suit_;
	int face_value_;

	bool is_available_ = true;

	bool SetSuitAndValue(int idx);
};

