#pragma once
#include <string>

class FBullCowGame {

public:
	void Reset(); // To Do: Return a rich value
	int GetMaxTries();
	std::string GetHint();
	int GetTurnNumber();
	int CurrentTry();
	bool IsGameWon();
	bool CheckGuess(std::string); // To Do: Return a rich value

	//Focus on interface above
private:
	int MyCurrenTry;
	int MyMaxTry;
	int TurnNumber;
	
};
