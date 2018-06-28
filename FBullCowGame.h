#pragma once
#include <string>

class FBullCowGame {

public:
	FBullCowGame(); // constructor

	int GetMaxTries() const;
	std::string GetHint() const;
	int GetTurnNumber() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuess(std::string); // To Do: Return a rich value
	void Reset(); // To Do: Return a rich value

	//Focus on interface above
private:
	// see constructor for initialization
	int MyCurrenTry;
	int MyMaxTry;
	int TurnNumber;
	
};
