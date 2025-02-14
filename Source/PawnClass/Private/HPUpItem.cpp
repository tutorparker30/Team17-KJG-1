#include "HPUpItem.h"

AHPUpItem::AHPUpItem()
{
	HealAmount = 20;
	ItemType = "UpItem";
}

void AHPUpItem::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);
	GEngine->AddOnScreenDebugMessage(
		-1,
		2.0f,
		FColor::Green,
		FString::Printf(TEXT("Player gained %d HP!"), HealAmount));
}

