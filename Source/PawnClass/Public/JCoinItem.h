#pragma once

#include "CoreMinimal.h"
#include "JBaseItem.h"
#include "JCoinItem.generated.h"

UCLASS()
class PAWNCLASS_API AJCoinItem : public AJBaseItem
{
	GENERATED_BODY()

public:
	AJCoinItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 PointValue;

	virtual void ActivateItem(AActor* Activator) override;
	
};
