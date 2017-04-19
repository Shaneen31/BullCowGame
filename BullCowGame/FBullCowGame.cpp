#pragma once

#include "FBullCowGame.h"
#include <map>
#define TMap std::map

// Contrutor
FBullCowGame::FBullCowGame() { reset(); }

// Getters
int32 FBullCowGame::GetCurrentTry() const { return CurrentTry; }

int32 FBullCowGame::GetHiddenWordLenght() const { return HiddenWord.length(); }

bool FBullCowGame::IsGameWon() const { return bIsWon; }

int32 FBullCowGame::GetMaxTries() const
{
	TMap <int32, int32> WordLenghtToMaxTries{ { 3, 4 }, { 4, 5 }, { 5, 5 }, { 6 , 7 }, { 7 , 8 }, { 8, 9 }, { 9 , 10 }, { 10 , 11 }, { 12 , 13 }, { 13 , 14 }, { 14 , 15 }, { 16 , 17 }, { 17 , 18 } };
	return WordLenghtToMaxTries[GetHiddenWordLenght()];
}

// Validate player's Guess
EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (Guess.length() != GetHiddenWordLenght())
	{
		return EGuessStatus::Wrong_Lenght;
	}
	else if (!IsLowercase(Guess))
	{
		return EGuessStatus::Not_Lower_Case;
	}
	else if (!isIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

void FBullCowGame::reset()
{
	bIsWon = false;
	CurrentTry = 1;
	HiddenWord = "planet";
	return;
}

// Receive Validated Guess then Count bulls and cows, and increase Try count.
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	FBullCowCount BullCowCount;
	int32 HiddenWordLenght = HiddenWord.length();

	CurrentTry++;

	for (int32 i = 0; i < HiddenWordLenght; i++)
	{
		for (int32 j = 0; j < HiddenWordLenght; j++)
		{
			if (Guess[j]  == HiddenWord[i])
			{
				if (i == j) { BullCowCount.Bulls++; }
				else { BullCowCount.Cows++; }
			}
		}
	}
	if (BullCowCount.Bulls == GetHiddenWordLenght()) { bIsWon = true; }
	return BullCowCount;
}

bool FBullCowGame::isIsogram(FString Guess) const
{
	if (Guess.length() <= 1  ){ return true; }

	TMap <char, bool> LetterSeen;

	for (auto Letter : Guess)
	{
		Letter = tolower(Letter);

		if (LetterSeen[Letter]) { return false; }
		else { LetterSeen[Letter] = true; }
	}
	return true;
}

bool FBullCowGame::IsLowercase(FString Guess) const
{
	for (auto Letter : Guess)
	{
		if (!islower(Letter)) { return false; }
	}
	return true;
}
