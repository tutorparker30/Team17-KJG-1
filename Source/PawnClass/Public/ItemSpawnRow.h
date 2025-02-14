#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemSpawnRow.generated.h"

USTRUCT(BlueprintType)
struct FItemSpawnRow : public FTableRowBase
{

	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItemName; // �ƾ��� �̸�.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ItemClass; // � ������ Ŭ������ ������ ��.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SpawnChance; // �� �������� ���� Ȯ��.

};
