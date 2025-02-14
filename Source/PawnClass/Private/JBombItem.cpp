#include "JBombItem.h"
#include "Components/SphereComponent.h"

AJBombItem::AJBombItem()
{
	ExplosionDelay = 5.0f;
	ExplosionRadius = 0.0f;
	ItemType = "DefaultBomb";

	ExplosionCollision = CreateDefaultSubobject<USphereComponent>(TEXT("ExplosionCollision"));
	ExplosionCollision->InitSphereRadius(ExplosionRadius);
	ExplosionCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	ExplosionCollision->SetupAttachment(Scene);

}

void AJBombItem::ActivateItem(AActor* Activator)
{
	// 5초 후 폭발 실행.
	GetWorld()->GetTimerManager().SetTimer(ExplosionTimerHandle, this, &AJBombItem::Explode, ExplosionDelay);
}

void AJBombItem::Explode()
{
	OverlappingActors.Empty();
	ExplosionCollision->GetOverlappingActors(OverlappingActors);

	for (AActor* Actor : OverlappingActors)
	{

		if (Actor && Actor->ActorHasTag("Player"))
		{
			GEngine->AddOnScreenDebugMessage(
				-1,
				2.0f,
				FColor::Red,
				FString::Printf(TEXT("Player exploded %.2f seconds bombItem!"), ExplosionDelay));
		}
	}

	DestroyItem();
}
