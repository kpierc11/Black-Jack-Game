#include "Deck.h"
#include "Card.h"
#include <algorithm>
#include <random>
#include <chrono> 
#include <iostream>


using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;

Deck::Deck()
{
}

Deck::~Deck()
{
}

void Deck::LoadDeck()
{
	for (int i = 0; i <= 3; i++) {

		string suit = "spades";

		if (i == 1) {
			suit = "clubs";
		}
		else if (i == 2) {
			suit = "hearts";
		}
		else if (i == 3) {
			suit = "diamonds";
		}

		Card ace;
		ace.mPoints = 1;
		ace.mSuit = suit;
		ace.mValue = "ace";
		mDeck.push_back(ace);

		Card two;
		two.mPoints = 2;
		two.mSuit = suit;
		two.mValue = "two";
		mDeck.push_back(two);

		Card three;
		three.mPoints = 3;
		three.mSuit = suit;
		three.mValue = "three";
		mDeck.push_back(three);

		Card four;
		four.mPoints = 4;
		four.mSuit = suit;
		four.mValue = "four";
		mDeck.push_back(four);

		Card five;
		five.mPoints = 5;
		five.mSuit = suit;
		five.mValue = "five";
		mDeck.push_back(five);

		Card six;
		six.mPoints = 6;
		six.mSuit = suit;
		six.mValue = "six";
		mDeck.push_back(six);

		Card seven;
		seven.mPoints = 7;
		seven.mSuit = suit;
		seven.mValue = "seven";
		mDeck.push_back(seven);

		Card eight;
		eight.mPoints = 8;
		eight.mSuit = suit;
		eight.mValue = "eight";
		mDeck.push_back(eight);

		Card nine;
		nine.mPoints = 9;
		nine.mSuit = suit;
		nine.mValue = "nine";
		mDeck.push_back(nine);

		Card ten;
		ten.mPoints = 10;
		ten.mSuit = suit;
		ten.mValue = "ten";
		mDeck.push_back(ten);

		Card jack;
		jack.mPoints = 10;
		jack.mSuit = suit;
		jack.mValue = "jack";
		mDeck.push_back(jack);

		Card queen;
		queen.mPoints = 10;
		queen.mSuit = suit;
		queen.mValue = "queen";
		mDeck.push_back(queen);

		Card king;
		king.mPoints = 10;
		king.mSuit = suit;
		king.mValue = "king";
		mDeck.push_back(king);

	}
}

vector<Card> Deck::GetDeck()
{
	return mDeck;
}

void Deck::ShuffleDeck()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(begin(mDeck), end(mDeck), std::default_random_engine(seed));
}

void Deck::ShowDeck()
{
	for (Card& card : mDeck) {
		cout << card.mValue << " " << card.mSuit << endl;
	}
}


void Deck::AddCardToHand(vector<Card>& playersHand)
{
	playersHand.push_back(mDeck[0]);

	auto it = mDeck.begin();

	mDeck.erase(it);
}

void Deck::SetDealerHand(vector<Card>& dealersDeck, vector<Card>& playersHand)
{
}
