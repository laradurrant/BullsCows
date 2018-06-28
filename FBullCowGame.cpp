#include "FBullCowGame.h"

void FBullCowGame::Reset()
{
}

int FBullCowGame::GetMaxTries() const
{
	return MyMaxTry;
}

std::string FBullCowGame::GetHint() const
{
	return std::string();
}

int FBullCowGame::GetTurnNumber() const
{
	return 0;
}

int FBullCowGame::GetCurrentTry() const
{
	return MyCurrenTry;
}

bool FBullCowGame::IsGameWon()
{
	return false;
}

bool FBullCowGame::CheckGuess(std::string)
{
	return false;
}
