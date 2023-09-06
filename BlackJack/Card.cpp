#include "Card.h"

Card::Card()
{
	mPoints = 0;
	mValue = "";
	mSuit = "";
}

Card::~Card()
{
}

std::string Card::GetValue()
{
	return std::string();
}

std::string Card::GetSuit()
{
	return std::string();
}

int Card::GetPoints()
{
	return 0;
}

void Card::SetPoints(int points) {
	mPoints = points;
}
