#pragma once

#include "CoreMinimal.h"
#include "JBaseItem.h"
#include "JPotionItem.generated.h"

UCLASS()
class PAWNCLASS_API AJPotionItem : public AJBaseItem
{
	GENERATED_BODY()

public:
	AJPotionItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	float HealAmount;
	
	virtual void ActivateItem(AActor* Activator) override;
};
