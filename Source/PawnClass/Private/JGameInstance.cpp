#include "JGameInstance.h"

UJGameInstance::UJGameInstance()
{
	TotalScore = 0;
	CurrentLevelIndex = 0;
}

void UJGameInstance::AddToScore(int32 Amount)
{
	TotalScore += Amount;
	UE_LOG(LogTemp, Warning, TEXT("Total Score Updated: %d"), TotalScore);
}

