#include "FBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame()
{
	reset();
}

int32 FBullCowGame::GetMaxTries() const { return MaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return CurrentTry; }

int32 FBullCowGame::GetHiddenWordLenght() const { return HiddenWord.length(); }

bool FBullCowGame::IsGameWon() const { return bIsWon; }

// TODO Validate player's Guess
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
	MaxTries = 8;
	CurrentTry = 1;
	HiddenWord = "planet";
	return;
}

// Receive Validated Guess then Count bulls and cows, and increase Try count.
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// Declare local variables
	FBullCowCount BullCowCount;
	int32 HiddenWordLenght = HiddenWord.length();

	// Increment Try Count
	CurrentTry++;

	//Loop through guess's letters and compare with hidden word
	for (int32 i = 0; i < HiddenWordLenght; i++)
	{
		for (int32 j = 0; j < HiddenWordLenght; j++)
		{
			if (Guess[j]  == HiddenWord[i])
			{
				if (i == j)
				{
					BullCowCount.Bulls++;
				}
				else
				{
				BullCowCount.Cows++;
				}
			}
			if (BullCowCount.Bulls == GetHiddenWordLenght())
			{
				bIsWon = true;
			}
		}
	}
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
