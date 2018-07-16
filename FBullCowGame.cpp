#include "FBullCowGame.h"
#include <map>
#define TMap std::map


FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTry;
}

FText FBullCowGame::GetHint() const
{
	return FText();
}

int32 FBullCowGame::GetTurnNumber() const
{
	return 0;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrenTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return bGameWon;
}

bool FBullCowGame::IsIsogram(FText Word) const
{
	// treat 0 and 1 letter words as isograms
	if (Word.length() <= 1)
	{
		return true; 
	}

	TMap<char, bool> LetterSeen; 	// set up our map 
	for (auto Letter : Word)        // cycle through the letters of the guess
	{
		Letter = tolower(Letter);
		 
		if (LetterSeen[Letter])  	// if there is a duplicate letter
									// aka if one of the letters of the map is not false
									// then return false (not an isogram)
		{
			return false;
		}
		else
		{
			LetterSeen[Letter] = true; 		// "load up" the map with the letters of the guess
											// setting new letters from false to true	
		}
		
	}

	return true;
}

bool FBullCowGame::IsLowercase(FText Word) const
{

	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FText Guess) const
{
	//TODO: Implement error checking here
	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess))
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Word_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}

	
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	const FText HIDDEN_WORD = "plain";

	bGameWon = false;
	MyCurrenTry = 1;
	MyMaxTry = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;

	return;
}

// Receives a valid guess and increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FText Guess)
{
	
	//Increment turn number
	MyCurrenTry++;
	//set up a return variable
	FBullCowCount BullCowCount;
	//loop through all letters in the guess
		// compare letters against the hidden word



	int32 HiddenWordLength = MyHiddenWord.length();
	int32 GuessLength = Guess.length();

	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		for (int32 j = 0; j < GuessLength; j++)
		{
			if (Guess[i] == MyHiddenWord[j])
			{
				if (i == j)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
				
			}
		}
	}

	if (MyHiddenWord == Guess)
	{
		bGameWon = true;
	}

	return BullCowCount;
}
