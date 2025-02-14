#pragma once

#include "CoreMinimal.h"
#include "JBombItem.h"
#include "JTNTItem.generated.h"

UCLASS()
class PAWNCLASS_API AJTNTItem : public AJBombItem
{
	GENERATED_BODY()
	
public:
	AJTNTItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JTNT")
	float ExplosionDamage;

	virtual void ActivateItem(AActor* Activator) override;
	virtual void Explode() override;

};
