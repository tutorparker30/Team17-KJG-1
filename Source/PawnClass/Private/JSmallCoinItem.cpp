#include "JSmallCoinItem.h"

AJSmallCoinItem::AJSmallCoinItem()
{
	PointValue = 10;
	ItemType = "SmallCoin";
}

void AJSmallCoinItem::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);
}

