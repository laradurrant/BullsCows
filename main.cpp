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
	int32 NumberOfTurns = BCGame.GetMaxTries();
	
	FString Guess; 

	// This will get a guess from the player
	for (int32 i = 0; i < NumberOfTurns; i++)
	{
		Guess = GetGuess(Guess);

		EGuessStatus guess_status;
		guess_status = BCGame.CheckGuessValidity(Guess);

		if (guess_status == EGuessStatus::OK)
		{
			FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
			std::cout << "Bulls: " << BullCowCount.Bulls << " Cows: " << BullCowCount.Cows << "\n";

			PrintGuess(Guess);
		}
		else
		{
			std::cout << "Something went wrong!" << std::endl;
		}

		
	}

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

FString GetGuess(FString &Guess)
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << BCGame.GetCurrentTry();
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
