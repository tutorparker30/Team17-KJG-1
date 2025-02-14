#include "JGiftItem.h"

AJGiftItem::AJGiftItem()
{
	PointValue = 50;
	ItemType = "JGift";
}

void AJGiftItem::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);
}

void AJGiftItem::Explode()
{
	Super::Explode();

	for (AActor* Actor : OverlappingActors)
	{
		if (Actor && Actor->ActorHasTag("Player"))
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				2.0f,
				FColor::Blue,
				FString::Printf(TEXT("Player damaged %d by JGiftItem!"), PointValue));
		}
	}
}

