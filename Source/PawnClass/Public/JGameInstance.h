#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "JGameInstance.generated.h"

UCLASS()
class PAWNCLASS_API UJGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UJGameInstance();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GameData")
	int32 TotalScore;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GameData")
	int32 CurrentLevelIndex;

	UFUNCTION(BlueprintCallable, Category = "GameData")
	void AddToScore(int32 Amount);
	
};
