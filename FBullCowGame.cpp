#include "FBullCowGame.h"



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
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FText guess) const
{
	//TODO: Implement error checking here
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (guess.length() != GetHiddenWordLength())
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

	return BullCowCount;
}
