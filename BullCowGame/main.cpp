#include <iostream>
#include <string>

using namespace std;

//Declare methods
void PrintIntro();
void PlayGame();
string GetGuess();

// Game Entry Point
int main()
{
	PrintIntro();
	PlayGame();
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