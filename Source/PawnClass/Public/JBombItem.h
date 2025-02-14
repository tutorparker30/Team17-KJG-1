#pragma once

#include "CoreMinimal.h"
#include "JBaseItem.h"
#include "JBombItem.generated.h"

UCLASS()
class PAWNCLASS_API AJBombItem : public AJBaseItem
{
	GENERATED_BODY()

public:
	AJBombItem();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
	USphereComponent* ExplosionCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bomb")
	float ExplosionDelay;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bomb")
	float ExplosionRadius;

	FTimerHandle ExplosionTimerHandle;

	TArray<AActor*> OverlappingActors;

	virtual void ActivateItem(AActor* Activator) override;

	virtual void Explode();
	
};
