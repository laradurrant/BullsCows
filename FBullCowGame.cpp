#include "FBullCowGame.h"



FBullCowGame::FBullCowGame()
{
	Reset();
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

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuess(std::string)
{
	return false;
}

void FBullCowGame::Reset()
{
	constexpr int MY_MAX_TRIES = 8;
	MyCurrenTry = 1;
	MyMaxTry = MY_MAX_TRIES;
	return;
}