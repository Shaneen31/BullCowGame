#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	reset();
}

int32 FBullCowGame::GetMaxTries() const { return MaxTries; }

int32 FBullCowGame::GetCurrentTry() const { return CurrentTry; }

bool FBullCowGame::IsGameWon() const 
{
	return false;
}

void FBullCowGame::reset()
{
	MaxTries = 8;
	CurrentTry = 1;
	return;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}
