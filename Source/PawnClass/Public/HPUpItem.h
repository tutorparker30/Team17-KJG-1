#pragma once

#include "CoreMinimal.h"
#include "JPotionItem.h"
#include "HPUpItem.generated.h"

UCLASS()
class PAWNCLASS_API AHPUpItem : public AJPotionItem
{
	GENERATED_BODY()

public:
	AHPUpItem();

	virtual void ActivateItem(AActor* Activator) override;

	
};
