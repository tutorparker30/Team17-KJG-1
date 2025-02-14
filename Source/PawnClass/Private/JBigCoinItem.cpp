#include "JBigCoinItem.h"

AJBigCoinItem::AJBigCoinItem()
{
	PointValue = 50;
	ItemType = "BigCoin";
}

void AJBigCoinItem::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);
}

