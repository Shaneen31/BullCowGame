#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame
{
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const ;
	bool IsGameWon() const ;

	void reset();
	bool CheckGuessValidity(FString);

private:
	int32 CurrentTry ;
	int32 MaxTries;
};