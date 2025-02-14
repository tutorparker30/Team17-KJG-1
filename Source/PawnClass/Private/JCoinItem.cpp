#include "JCoinItem.h"

AJCoinItem::AJCoinItem()
{
	PointValue = 0;
	ItemType = "DefaultCoin";
}

void AJCoinItem::ActivateItem(AActor* Activator)
{
	if (Activator && Activator->ActorHasTag("Player"))
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			2.0f,
			FColor::Green,
			FString::Printf(TEXT("Player gained %d points!"), PointValue));
		DestroyItem();
	}
}
