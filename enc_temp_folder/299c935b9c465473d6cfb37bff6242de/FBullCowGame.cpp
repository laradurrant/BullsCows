#include "FBullCowGame.h"



FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTry;
}

FString FBullCowGame::GetHint() const
{
	return FString();
}

int32 FBullCowGame::GetTurnNumber() const
{
	return 0;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrenTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuess(FString)
{
	return false;
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "plain";

	MyCurrenTry = 1;
	MyMaxTry = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;

	return;
}

// Receives a valid guess and increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//Increment turn number
	MyCurrenTry++;
	//set up a return variable
	FBullCowCount BullCowCount;
	//loop through all letters in the guess
		// compare letters against the hidden word

	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		for (int32 j = 0; j < HiddenWordLength; j++)
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
