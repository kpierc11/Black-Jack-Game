#pragma once
#include <string>

class Card
{
public:
	Card();
	~Card();

	std::string GetValue();
	std::string GetSuit();
	int GetPoints();
	void SetPoints(int points);

	std::string mValue;
	std::string mSuit; 
	int mPoints;
};

