#include "JCoinItem.h"
#include "JGameState.h"


AJCoinItem::AJCoinItem()
{
	PointValue = 0;
	ItemType = "DefaultCoin";
}

void AJCoinItem::ActivateItem(AActor* Activator)
{
	if (Activator && Activator->ActorHasTag("Player"))
	{
		if (Activator && Activator->ActorHasTag("Player"))
		{
			if (UWorld* World = GetWorld())
			{
				if (AJGameState* GameState = World->GetGameState<AJGameState>())
				{
					GameState->AddScore(PointValue);
					GameState->OnCoinCollected();
				}
			}
		}

		GEngine->AddOnScreenDebugMessage(
			-1,
			2.0f,
			FColor::Green,
			FString::Printf(TEXT("Player gained %d points!"), PointValue));

		DestroyItem();
	}
}
