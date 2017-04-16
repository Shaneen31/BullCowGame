#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	reset();
}

int32 FBullCowGame::GetMaxTries() const { return MaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return CurrentTry; }

int32 FBullCowGame::GetHiddenWordLenght() const { return HiddenWord.length(); }

// TODO Check if the game is won
bool FBullCowGame::IsGameWon() const 
{
	return false;
}

// TODO Validate player's Guess
EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (Guess.length() != GetHiddenWordLenght())
	{
		return EGuessStatus::Wrong_Lenght;
	}
	else if (false) // TODO If Guess is not Lower Case
	{
		return EGuessStatus::Not_Lower_Case;
	}
	else if (false) // TODO If Guess is not Isogram
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
		}
	}
	return BullCowCount;
}
