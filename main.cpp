//Bulls and Cows
#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();

string GetGuess(std::string &Guess);

void PrintGuess(std::string &Guess);

int main() 
{
	string guess;
	PrintIntro();
    
	PlayGame();

	return 0;
}

void PlayGame()
{
	constexpr int NUMBER_OF_TURNS = 5;

	string Guess; 
	// This will get a guess from the player
	for (int i = 0; i < NUMBER_OF_TURNS; i++)
	{
		Guess = GetGuess(Guess);
		PrintGuess(Guess);
	}
}


void PrintIntro() {
	// Sets the maximum word length
	constexpr int WORD_LENGTH = 5;

	// Introduce the player to the game
	cout << "..........................\n";
	cout << "Welcome to Bulls and Cows!\n";
	cout << "..........................\n";
	cout << "This is a fun word game / puzzle game!\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
	return;
}

string GetGuess(std::string &Guess)
{
	cout << "Enter your guess here: \n";
	getline(cin, Guess);
	return Guess;
}

void PrintGuess(std::string &Guess)
{
	cout << "Your guess: " << Guess << "\n";
	cout << endl;
	return;
}
