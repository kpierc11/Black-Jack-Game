#pragma once
#include "Card.h"
#include<vector>

class Deck
{
public:
	Deck();
	~Deck();

	void LoadDeck();
	std::vector<Card> GetDeck();
	void ShuffleDeck();
	void ShowDeck();
	void AddCardToHand(std::vector<Card>& playersHand);
	void SetDealerHand(std::vector<Card>& dealersDeck, std::vector<Card>& playersHand);

private:
	std::vector<Card> mDeck;
	std::vector<Card> mPlayersHand;

};

