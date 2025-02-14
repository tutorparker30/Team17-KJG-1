#pragma once

#include "CoreMinimal.h"
#include "JCoinItem.h"
#include "JSmallCoinItem.generated.h"

UCLASS()
class PAWNCLASS_API AJSmallCoinItem : public AJCoinItem
{
	GENERATED_BODY()
	

public:
	AJSmallCoinItem();

	virtual void ActivateItem(AActor* Activator) override;
};
