#pragma once
#include "Card.h"
#include "Deck.h"
#include<string>
#include<vector>
#include<iostream>

class Game
{
public:
	Game();
	~Game();

	bool InitGame();
	void GameLoop();
	void EndGame();

private:
	void HandleInput();
	void UpdateGame();
	void GenerateOutput();
	void GetPlayerBet();
	void ShowPlayersHand();
	void ShowDealersHand();
	void CalculatePlayerScore();
	void CalculateDealerScore();
	void DealersMove();

	Deck mDeck;
	std::vector<Card> mPlayersHand;
	std::vector<Card> mDealersHand;
	bool mPlayersTurn;
	bool mDealersTurn;
	int playerBet; 
	int mPlayerScore;
	int mDealersScore;
	bool mPlayerWon; 
	bool mGameRunning;
	std::string mUserInput;
	bool mGameStarted;

};

