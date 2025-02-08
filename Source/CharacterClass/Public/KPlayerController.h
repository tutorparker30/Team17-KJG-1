#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "KPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class CHARACTERCLASS_API AKPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AKPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputMappingContext* InputMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* MoveAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* SprintAction;

	virtual void BeginPlay() override;
	
};
