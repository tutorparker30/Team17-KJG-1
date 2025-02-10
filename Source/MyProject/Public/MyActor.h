#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MYPROJECT_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyActor();

protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
