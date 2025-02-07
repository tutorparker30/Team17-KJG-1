//SMW

#include "MyActor.h"

AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Log, TEXT("Written by JGK!!!"));
	UE_LOG(LogTemp, Log, TEXT("Written by SMW!!!!!"));
}
