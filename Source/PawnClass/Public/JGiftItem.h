#pragma once

#include "CoreMinimal.h"
#include "JBombItem.h"
#include "JGiftItem.generated.h"

UCLASS()
class PAWNCLASS_API AJGiftItem : public AJBombItem
{
	GENERATED_BODY()

public:
	AJGiftItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JGift")
	int32 PointValue;

	virtual void ActivateItem(AActor* Activator) override;
	virtual void Explode() override;
	
};
