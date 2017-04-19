#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid,
	OK,
	Not_Isogram,
	Wrong_Lenght,
	Not_Lower_Case,
};

class FBullCowGame
{
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const ;
	int32 GetHiddenWordLenght() const;
	bool IsGameWon() const ;
	EGuessStatus CheckGuessValidity(FString) const;

	void reset();
	FBullCowCount SubmitGuess(FString);

private:
	int32 CurrentTry ;
	int32 MaxTries;
	FString HiddenWord;
	bool bIsWon;
};