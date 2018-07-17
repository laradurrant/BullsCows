//Bulls and Cows
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string; 
using int32 = int;

void Printintro();
void PlayGame();
FText GetValidGuess();
void PrintGuess(FText &Guess);
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame;

int main() 
{
	FText guess;

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
	BCGame.Reset();
	int32 NumberOfTurns = BCGame.GetMaxTries();
	


	// This will get a guess from the player
	while(BCGame.GetCurrentTry() < BCGame.GetMaxTries() && !BCGame.IsGameWon())
	{
		FText Guess = GetValidGuess();

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls: " << BullCowCount.Bulls << " Cows: " << BullCowCount.Cows << "\n";
	}

	PrintGameSummary();
}

void PrintGameSummary()
{

	if (BCGame.IsGameWon())
	{
		std::cout << "..........................\n";
		std::cout << "YOU WON! Congratulations!\n";
		std::cout << "..........................\n";
	}
	else if (BCGame.GetCurrentTry() >= BCGame.GetMaxTries() && !BCGame.IsGameWon())
	{
		std::cout << "..........................\n";
		std::cout << "You lose... Better luck next time!\n";
		std::cout << "..........................\n";
	}

}

// loops until we get a valid guess
FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;

	do
	{

	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << BCGame.GetCurrentTry() << " of " << BCGame.GetMaxTries() << ". Enter your guess: \n";
	
	std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);

		switch (Status)
		{
			case EGuessStatus::Word_Length:
				std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
				break;
			case EGuessStatus::Not_Isogram:
				std::cout << "Please enter a word without repeating letters.\n";
				break;
			case EGuessStatus::Not_Lowercase:
				std::cout << "Please make sure your word uses lowercase letter.\n";
				break;
			default:
				break;
		}

	} while (Status != EGuessStatus::OK); // keep looping until we get no errors
	
	return Guess;
}



void Printintro() {
	// Sets the maximum word length
	BCGame.Reset();
	int32 HiddenWordLength = BCGame.GetHiddenWordLength();

	// introduce the player to the game
	std::cout << "..........................\n";
	std::cout << "Welcome to Bulls and Cows!\n";
	std::cout << "..........................\n";
	std::cout << "This is a fun word game / puzzle game!\n";
	std::cout << "Can you guess the " << HiddenWordLength << " letter isogram I'm thinking of?\n";
	return;
}


void PrintGuess(FText &Guess)
{
	std::cout << "Your guess: " << Guess << "\n";
	std::cout << std::endl;
	return;
}

bool AskToPlayAgain()
{
	// Asks to play the game 
	std::cout << "Would you like to play again with the same hidden word? (y/n) \n";
	FText Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;

	return (Response[0] == 'y' || Response[0] == 'Y');
}
