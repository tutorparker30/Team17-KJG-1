#include "JTNTItem.h"
#include "Kismet/GameplayStatics.h"

AJTNTItem::AJTNTItem()
{
	ExplosionDamage = 30.0f;
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
				FString::Printf(TEXT("Player damaged %.2f by JTNTItem!"), ExplosionDamage));
			
			UGameplayStatics::ApplyDamage(
				Actor,
				ExplosionDamage,
				nullptr,
				this,
				UDamageType::StaticClass()
			);
		}
	}
}

