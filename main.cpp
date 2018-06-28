//Bulls and Cows
#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess(std::string &Guess);
void PrintGuess(std::string &Guess);
bool AskToPlayAgain();

FBullCowGame BCGame;

int main() 
{
	std::string guess;

	// Play the game but only while the player wants to
	do
	{
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());

	return 0;
}

void PlayGame()
{
	constexpr int NUMBER_OF_TURNS = 5;
	

	std::string Guess; 
	// This will get a guess from the player

	for (int i = 0; i < NUMBER_OF_TURNS; i++)
	{
		Guess = GetGuess(Guess);
		PrintGuess(Guess);
	}

}


void PrintIntro() {
	// Sets the maximum word length
	int MaxTries = BCGame.GetMaxTries();

	// Introduce the player to the game
	std::cout << "..........................\n";
	std::cout << "Welcome to Bulls and Cows!\n";
	std::cout << "..........................\n";
	std::cout << "This is a fun word game / puzzle game!\n";
	std::cout << "Can you guess the " << MaxTries << " letter isogram I'm thinking of?\n";
	return;
}

std::string GetGuess(std::string &Guess)
{
	int CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry;
	std::cout << ". Enter your guess here: \n";
	std::getline(std::cin, Guess);
	return Guess;
}

void PrintGuess(std::string &Guess)
{
	std::cout << "Your guess: " << Guess << "\n";
	std::cout << std::endl;
	return;
}

bool AskToPlayAgain()
{
	// Asks to play the game 
	std::cout << "Would you like to play again? (y/n) \n";
	std::string Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;

	return (Response[0] == 'y' || Response[0] == 'Y');
}
