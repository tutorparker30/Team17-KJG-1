#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "KCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class CHARACTERCLASS_API AKCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	AKCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArmComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* CameraComp;

protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
