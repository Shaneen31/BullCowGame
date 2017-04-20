#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

//Declare methods
void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayagain();

FBullCowGame BCGame;

// Game Entry Point
int main()
{
	bool bPlayAgain = false;

	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayagain();
	}
	while (bPlayAgain);
	return 0;
}

// Game Methods
void PrintIntro()
{
	std::cout << "\nWelcome to Bulls and Cows\n";
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLenght() << " letters isogram I'm thinking of?\n";
	std::cout << std::endl;
	return;
}

FText GetValidGuess()
{
	FText Guess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();
	EGuessStatus Status = EGuessStatus::Invalid;

	do
	{
		// Ask player for a Guess
		std::cout << "Try " << CurrentTry <<  " of " << BCGame.GetMaxTries() <<" - Enter your guess: ";
		getline(std::cin, Guess);

		// Validate Player's Guess before submiting to handle errors.
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Lenght:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLenght() << " letters long word.\n\n";
			break;

		case EGuessStatus::Not_Lower_Case:
			std::cout << "Please type in lower case.\n\n";
			break;

		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram.\n\n";
			break;

		default:
			break;
		}
		//std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
	return Guess;
}

bool AskToPlayagain()
{
	FText Response = "";
	std::cout << "Do you want to play again (y/n)? ";
	getline(std::cin, Response);
	if ( Response[0] == 'y' || Response[0] == 'Y' )
	{
		BCGame.reset();
		return true;
	}
	return false;
}

void PlayGame()
{
	int32 MaxTries = BCGame.GetMaxTries();

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() < MaxTries)
	{
		FText Guess = GetValidGuess();

		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;;
		std::cout << std::endl;
	}

	if (BCGame.IsGameWon())
	{
		std::cout << "Well done, you won!\n";
		return;
	}
	else
	{
		std::cout << "Bad luck, you'll do better next time!\n";
		return;
	}
}