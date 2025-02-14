#include "JTNTItem.h"

AJTNTItem::AJTNTItem()
{
	ExplosionDamage = 30;
	ItemType = "JTNT";
}

void AJTNTItem::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);
}

void AJTNTItem::Explode()
{
	Super::Explode();

	for (AActor* Actor : OverlappingActors)
	{
		if (Actor && Actor->ActorHasTag("Player"))
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				2.0f,
				FColor::Red,
				FString::Printf(TEXT("Player damaged %d by JTNTItem!"), ExplosionDamage));
		}
	}
}

