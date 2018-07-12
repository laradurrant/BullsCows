#pragma once
#include <string>

using FString = std::string;
using int32 = int;

//Initializes all values to zero
struct FBullCowCount {
	int32 Cows = 0;
	int32 Bulls = 0;
};

class FBullCowGame {

public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	FString GetHint() const;
	int32 GetTurnNumber() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuess(FString); // TODO: Return a rich value
	void Reset(); // To Do: Return a rich value

	//counts bulls and cows, and increases try # assuming valid guess 
	FBullCowCount SubmitGuess(FString);

	//Focus on interface above
private:
	// see constructor for initialization
	int32 MyCurrenTry;
	int32 MyMaxTry;
	int32 TurnNumber;

	FString MyHiddenWord;
	
};
