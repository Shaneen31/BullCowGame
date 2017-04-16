#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

//Declare methods
void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayagain();

FBullCowGame BCGame;

// Game Entry Point
int main()
{
	bool bPlayAgain = false;

	PrintIntro();
	do
	{
		PlayGame();
		bPlayAgain = AskToPlayagain();
	}
	while (bPlayAgain);
	return 0;
}

// Game Methods
void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLenght() << " letters word I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	int32 MaxTries = BCGame.GetMaxTries();

	for (int32 Try = 0; Try < MaxTries; Try++)
	{
		FText Guess = GetGuess();
		
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;;
		std::cout << std::endl;
	}
}

FText GetGuess()
{
	FText Guess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << " - Enter your guess: ";
	getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayagain()
{
	FText Response = "";
	std::cout << "Do you want to play again (y/n)? ";
	getline(std::cin, Response);
	if ( Response[0] == 'y' || Response[0] == 'Y' )
	{
		return true;
	}
	return false;
}
