//Bulls and Cows
#include <iostream>
#include <string>

using namespace std;

int main() 
{
	// Sets the maximum word length
	constexpr int WORD_LENGTH = 5;
	
	// Introduce the player to the game
	cout << "..........................\n";
    cout << "Welcome to Bulls and Cows!\n";
	cout << "..........................\n";
	cout << "This is a fun word game / puzzle game!\n";
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
    
	// This will get a guess from the player
	string Guess = "";
	
	cout << "Enter your guess here: \n";
	cin >> Guess;
	cout << "I think you wrote: " << Guess << ".\n";
	cout << "Is that correct?\n";
	cout << endl;
	
	return 0;
}