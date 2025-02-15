#include "JGameState.h"
#include "JGameInstance.h"
#include "JPlayerController.h"
#include "SpawnVolume.h"
#include "JCoinItem.h"
#include "Kismet/GameplayStatics.h"

AJGameState::AJGameState()
	: Score(0)
	, SpawnedCoinCount(0)
	, CollectedCoinCount(0)
	, CurrentLevelIndex(0)
	, MaxLevels(3)
	, CurrentWaveIndex(1)
	, MaxWaves(4)
	, WaveDuration(5.0f)
	, CoinsToSpawnPerWave({20, 30, 40})
{
}

void AJGameState::BeginPlay()
{
	Super::BeginPlay();

	StartLevel();
}

int32 AJGameState::GetScore() const
{
	return Score;
}

void AJGameState::AddScore(int32 Amount)
{
	if (UJGameInstance* JGameInstance = GetJGameInstance())
	{
		JGameInstance->AddToScore(Amount);
	}
}

void AJGameState::StartLevel()
{
	if (UJGameInstance* JGameInstance = GetJGameInstance())
	{
		CurrentLevelIndex = JGameInstance->CurrentLevelIndex;
	}

	CurrentWaveIndex = 1;
	StartWave();
	
}

void AJGameState::StartWave()
{
	UE_LOG(LogTemp, Warning, TEXT("Level %d Wave %d Start!"), CurrentLevelIndex + 1, CurrentWaveIndex);
	SpawnedCoinCount = 0;
	CollectedCoinCount = 0;

	for (AActor* Item : CurrentWaveItems)
	{
		if (Item && Item->IsValidLowLevelFast())
		{
			Item->Destroy();
		}
	}
	CurrentWaveItems.Empty();

	int32 CoinsToSpawn = (CoinsToSpawnPerWave.IsValidIndex(CurrentWaveIndex)) ? CoinsToSpawnPerWave[CurrentWaveIndex] : 20;

	if (ASpawnVolume* SpawnVolume = GetSpawnVolume())
	{
		for (int32 i = 0; i < CoinsToSpawn; i++)
		{
			if (AActor* SpawnedActor = SpawnVolume->SpawnRandomItem())
			{
				if (SpawnedActor->IsA(AJCoinItem::StaticClass()))
				{
					SpawnedCoinCount++;
					CurrentWaveItems.Add(SpawnedActor);
				}
			}
		}
	}

	GetWorldTimerManager().SetTimer(
		WaveTimerHandle,
		this,
		&AJGameState::OnWaveTimeUp,
		WaveDuration,
		false
	);
}

void AJGameState::EndWave()
{
	GetWorldTimerManager().ClearTimer(WaveTimerHandle);

	++CurrentWaveIndex;
	if (CurrentWaveIndex >= MaxWaves)
	{
		EndLevel();
	}
	else
	{
		StartWave();
	}
}

void AJGameState::OnWaveTimeUp()
{
	EndWave();
}

void AJGameState::OnCoinCollected()
{
	CollectedCoinCount++;

	UE_LOG(LogTemp, Warning, TEXT("Coin Collected %d / %d"),
		CollectedCoinCount,
		SpawnedCoinCount);

		if (SpawnedCoinCount > 0 && CollectedCoinCount >= SpawnedCoinCount)
		{
			EndWave();
		}
}

void AJGameState::EndLevel()
{
	GetWorldTimerManager().ClearTimer(WaveTimerHandle);

	if (UJGameInstance* JGameInstance = GetJGameInstance())
	{
		AddScore(Score);
		CurrentLevelIndex++;
		JGameInstance->CurrentLevelIndex = CurrentLevelIndex;

		if (CurrentLevelIndex >= MaxLevels)
		{
			OnGameOver();
			return;
		}

		if (LevelMapNames.IsValidIndex(CurrentLevelIndex))
		{
			UGameplayStatics::OpenLevel(GetWorld(), LevelMapNames[CurrentLevelIndex]);
		}
		else
		{
			OnGameOver();
		}
	}
}

void AJGameState::OnGameOver()
{
	UE_LOG(LogTemp, Warning, TEXT("Game Over!!"));
}

ASpawnVolume* AJGameState::GetSpawnVolume() const
{
	TArray<AActor*> FoundVolumes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundVolumes);
	return (FoundVolumes.Num() > 0) ? Cast<ASpawnVolume>(FoundVolumes[0]) : nullptr;
}

AJPlayerController* AJGameState::GetJPlayerController() const
{
	return Cast<AJPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
}

UJGameInstance* AJGameState::GetJGameInstance() const
{
	return Cast<UJGameInstance>(GetGameInstance());
}