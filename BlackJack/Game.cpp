#include "Game.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

Game::Game()
{
	mDeck = {};
	mPlayersHand = {};
	mDealersHand = {};
	mPlayerScore = 0;
	mGameRunning = true;
	mUserInput = "";
	mGameStarted = true;
	mPlayersTurn = true;
	mDealersTurn = false;
	mPlayerWon = false;
}

Game::~Game()
{
}

bool Game::InitGame()
{
	//load deck
	mDeck.LoadDeck();

	//shuffle the deck
	mDeck.ShuffleDeck();

	mDeck.AddCardToHand(mPlayersHand);
	mDeck.AddCardToHand(mDealersHand);
	mDeck.AddCardToHand(mPlayersHand);
	mDeck.AddCardToHand(mDealersHand);

	GetPlayerBet();

	for (auto& card : mPlayersHand) {

		if (card.mValue == "ace") {
			ShowPlayersHand();
			cout << "Will this ace be valued at a 11 or 1? " << endl;
			cin >> mUserInput;
		}

		if (card.mValue == "ace" && mUserInput == "11") {
			card.SetPoints(11);
		}

		mPlayerScore += card.mPoints;
	}

	return true;
}

void Game::GameLoop()
{
	while (mGameRunning) {
		HandleInput();
		UpdateGame();
		GenerateOutput();
	}
}

void Game::EndGame()
{

	if (mPlayerWon) {
		cout << "Congrats you won!" << endl;
	}
	else if(mPlayerScore > 21) {
		cout << "Game over you went over 21" << endl;
	}
	else {
		cout << "Sorry looks like the dealer won!" << endl;
		cout << "Dealers Score: " << mDealersScore << endl;
	}
}

void Game::HandleInput()
{

	if (mUserInput == "hit") {
		mDeck.AddCardToHand(mPlayersHand);
		CalculatePlayerScore();
	}

	if (mUserInput == "stand") {
		mPlayersTurn = false;
		mDealersTurn = true;
	}
}

void Game::UpdateGame()
{
}

void Game::GenerateOutput()
{
	ShowPlayersHand();
	ShowDealersHand();

	if (mPlayerScore <= 21 && mPlayersTurn )
	{
		cout << "Current Score: " << mPlayerScore << endl;
		cout << "Hit or Stand?" << endl;
		cin >> mUserInput;
	}
	else if(mPlayerScore > 21)
	{
		mGameRunning = false;
	}
	else {
		DealersMove();
	}

}

void Game::GetPlayerBet()
{
	cout << "Place your bet:($2 to $500)" << endl;
	cin >> playerBet;
}

void Game::ShowPlayersHand()
{
	cout << "Players hand: [";
	for (auto it = mPlayersHand.begin(); it != mPlayersHand.end(); it++) {
		cout << it->mValue << " " << it->mSuit << " ";
	}
	cout << "]" << endl;
}

void Game::ShowDealersHand()
{
	cout << "Dealers hand: [";
	for (int i = 0; i < mDealersHand.size(); i++) {
		if (mPlayersTurn == true && i == 1) {
			cout << "*****" << " ";
		}
		else {
			cout << mDealersHand[i].mValue << " " << mDealersHand[i].mSuit << " ";
		}
	}
	cout << "]" << endl;
}

void Game::CalculatePlayerScore()
{
	vector<Card>::iterator it = {};

	if (mPlayersHand.size() == 1) {
		it = mPlayersHand.begin();
	}
	else {
		it = mPlayersHand.end() - 1;
	}

	mPlayerScore += it->mPoints;

}

void Game::CalculateDealerScore()
{
	vector<Card>::iterator it = {};

	int score = 0;

	for (auto& card : mDealersHand) {
		score += card.mPoints;
	}

	mDealersScore = score;
}

void Game::DealersMove() {

	CalculateDealerScore();
	cout << "Dealers Score: " << mDealersScore << endl;

	if (mDealersScore >= 17 && mDealersScore <= 21) {
		if (mDealersScore > mPlayerScore) {
			mGameRunning = false;
		}
		else {
			mPlayerWon = true;
			mGameRunning = false;
		}
	}
	else {
		cout << "Dealer is drawing a card..." << endl;
		mDeck.AddCardToHand(mDealersHand);
	}
}
