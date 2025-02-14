#pragma once

#include "CoreMinimal.h"
#include "JPotionItem.h"
#include "HPDownItem.generated.h"

UCLASS()
class PAWNCLASS_API AHPDownItem : public AJPotionItem
{
	GENERATED_BODY()

public:
	AHPDownItem();

	virtual void ActivateItem(AActor* Activator) override;
	
};
