#include "RifleActor.h"

ARifleActor::ARifleActor()
{
	PrimaryActorTick.bCanEverTick = flase;
}

void ARifleActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARifleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

