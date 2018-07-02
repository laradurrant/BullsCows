//Bulls and Cows
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FString = std::string; 
using int32 = int;

void Printintro();
void PlayGame();
FString GetGuess(FString &Guess);
void PrintGuess(FString &Guess);
bool AskToPlayAgain();

FBullCowGame BCGame;

int main() 
{
	FString guess;

	// Play the game but only while the player wants to
	do
	{
		Printintro();
		PlayGame();
	} while (AskToPlayAgain());

	return 0;
}

void PlayGame()
{
	constexpr int32 NUMBER_OF_TURNS = 5;
	

	FString Guess; 
	// This will get a guess from the player

	for (int32 i = 0; i < NUMBER_OF_TURNS; i++)
	{
		Guess = GetGuess(Guess);
		PrintGuess(Guess);
	}

}


void Printintro() {
	// Sets the maximum word length
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// introduce the player to the game
	std::cout << "..........................\n";
	std::cout << "Welcome to Bulls and Cows!\n";
	std::cout << "..........................\n";
	std::cout << "This is a fun word game / puzzle game!\n";
	std::cout << "Can you guess the " << MaxTries << " letter isogram I'm thinking of?\n";
	return;
}

FString GetGuess(FString &Guess)
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry;
	std::cout << ". Enter your guess here: \n";
	std::getline(std::cin, Guess);
	return Guess;
}

void PrintGuess(FString &Guess)
{
	std::cout << "Your guess: " << Guess << "\n";
	std::cout << std::endl;
	return;
}

bool AskToPlayAgain()
{
	// Asks to play the game 
	std::cout << "Would you like to play again? (y/n) \n";
	FString Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;

	return (Response[0] == 'y' || Response[0] == 'Y');
}
