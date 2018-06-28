#pragma once
#include <string>

class FBullCowGame {

public:
	void Reset(); // To Do: Return a rich value
	int GetMaxTries() const;
	std::string GetHint() const;
	int GetTurnNumber() const;
	int GetCurrentTry() const;
	bool IsGameWon();
	bool CheckGuess(std::string); // To Do: Return a rich value

	//Focus on interface above
private:
	int MyCurrenTry = 1;
	int MyMaxTry = 5;
	int TurnNumber;
	
};
