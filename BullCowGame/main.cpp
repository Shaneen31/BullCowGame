#include <iostream>
#include <string>

using namespace std;

//Declare methods
void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayagain();

// Game Entry Point
int main()
{
	PrintIntro();
	do
	{
		PlayGame();
	}
	while (AskToPlayagain());
	return 0;
}

// Game Methods
void PrintIntro()
{
	constexpr int WordLenght = 5;
	cout << "Welcome to Bulls and Cows\n";
	cout << "Can you guess the " << WordLenght << " letters word I'm thinking of?\n";
	cout << endl;
	return;
}

void PlayGame()
{
	constexpr int Turns = 5;

	for (int Turn = 0; Turn < Turns; Turn++)
	{
		string Guess = GetGuess();
		cout << "Your guess was: " << Guess << endl;
		cout << endl;
	}
}

string GetGuess()
{
	string Guess = "";
	cout << "Enter your guess: ";
	getline(cin, Guess);
	cout << endl;
	return Guess;
}

bool AskToPlayagain()
{
	string Response = "";
	cout << "Do you want to play again? ";
	getline(cin, Response);
	if ( Response[0] == 'y' || Response[0] == 'Y' )
	{
		return true;
	}
	return false;
}
