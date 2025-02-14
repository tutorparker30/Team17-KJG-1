#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "JItemInterface.generated.h"

UINTERFACE(MinimalAPI)
class UJItemInterface : public UInterface
{
	GENERATED_BODY()
};

class PAWNCLASS_API IJItemInterface
{
	GENERATED_BODY()

public:

	UFUNCTION()
	virtual void OnItemOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) = 0;

	UFUNCTION()
	virtual void OnItemEndOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex) = 0;
	
	virtual void ActivateItem(AActor* Activator) = 0;
	
	virtual FName GetItemType() const = 0;

};
