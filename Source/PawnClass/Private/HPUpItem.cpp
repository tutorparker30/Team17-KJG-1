#include "HPUpItem.h"
#include "JPawn.h"

AHPUpItem::AHPUpItem()
{
	HealAmount = 20.0f;
	ItemType = "UpItem";
}

void AHPUpItem::ActivateItem(AActor* Activator)
{
	if (Activator && Activator->ActorHasTag("Player"))
	{
		if (AJPawn* PlayerCharacter = Cast<AJPawn>(Activator))
		{
			PlayerCharacter->AddHealth(HealAmount);
		}

		Destroy();
	}
	GEngine->AddOnScreenDebugMessage(
		-1,
		2.0f,
		FColor::Green,
		FString::Printf(TEXT("Player gained %.2f HP!"), HealAmount));

}

