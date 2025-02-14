#include "HPDownItem.h"
#include "Kismet/GameplayStatics.h"

AHPDownItem::AHPDownItem()
{
	HealAmount = -20.0f;
	ItemType = "DownItem";
}

void AHPDownItem::ActivateItem(AActor* Activator)
{
	if (Activator && Activator->ActorHasTag("Player"))
	{
		UGameplayStatics::ApplyDamage(
			Activator,
			FMath::Abs(HealAmount),
			nullptr,
			this,
			UDamageType::StaticClass());
	}
	GEngine->AddOnScreenDebugMessage(
		-1,
		2.0f,
		FColor::Red,
		FString::Printf(TEXT("Player downed %.2f HP!"), HealAmount));

	Destroy();
}

