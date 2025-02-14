#include "HPDownItem.h"

AHPDownItem::AHPDownItem()
{
	HealAmount = -20;
	ItemType = "DownItem";
}

void AHPDownItem::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);
	GEngine->AddOnScreenDebugMessage(
		-1,
		2.0f,
		FColor::Red,
		FString::Printf(TEXT("Player downed %d HP!"), HealAmount));
}

