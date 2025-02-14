#pragma once

#include "CoreMinimal.h"
#include "JCoinItem.h"
#include "JBigCoinItem.generated.h"

UCLASS()
class PAWNCLASS_API AJBigCoinItem : public AJCoinItem
{
	GENERATED_BODY()

public:
	AJBigCoinItem();

	virtual void ActivateItem(AActor* Activator) override;
	
};
