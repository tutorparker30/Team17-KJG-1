#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemSpawnRow.h"
#include "SpawnVolume.generated.h"

class UBoxComponent;

UCLASS()
class PAWNCLASS_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawnVolume();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	USceneComponent* Scene;
	// ���� ������ ����� �ڽ� ������Ʈ
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	UBoxComponent* SpawningBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
	UDataTable* ItemDataTable;
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	AActor* SpawnRandomItem();
	
	// ���� ���� ���ο��� ������ ��ǥ�� ������ �Լ�.
	FItemSpawnRow* GetRandomItem() const;
	// Ư�� ������ Ŭ������ �����ϴ� �Լ�.
	AActor* SpawnItem(TSubclassOf<AActor> ItemClass);
	FVector GetRandomPointInVolume() const;

};
