#include "JPotionItem.h"

AJPotionItem::AJPotionItem()
{
	HealAmount = 0;
	ItemType = "DefaultPotion";
}

void AJPotionItem::ActivateItem(AActor* Activator)
{
	if (Activator && Activator->ActorHasTag("Player"))
	{
		DestroyItem();
	}
}

