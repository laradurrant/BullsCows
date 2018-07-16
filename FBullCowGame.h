#pragma once
#include <string>

using FText = std::string;
using int32 = int;

//Initializes all values to zero
struct FBullCowCount {
	int32 Cows = 0;
	int32 Bulls = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Word_Length,
	Not_Lowercase
};

class FBullCowGame {

public:
	FBullCowGame(); // constructor

	int32 GetMaxTries() const;
	FText GetHint() const;
	int32 GetTurnNumber() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FText) const;
	
	//counts bulls and cows, and increases try # assuming valid guess 
	FBullCowCount SubmitValidGuess(FText);

	void Reset(); 

private:
	// see constructor for initialization
	int32 MyCurrenTry;
	int32 MyMaxTry;
	int32 TurnNumber;
	bool bGameWon;

	FText MyHiddenWord;
	
};
