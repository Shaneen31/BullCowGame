#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame
{
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const ;
	int32 GetHiddenWordLenght() const;
	bool IsGameWon() const ;
	bool CheckGuessValidity(FString) const;

	void reset();
	FBullCowCount SubmitGuess(FString);

private:
	int32 CurrentTry ;
	int32 MaxTries;
	FString HiddenWord;
};