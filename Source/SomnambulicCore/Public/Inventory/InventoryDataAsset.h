#pragma once
#include "Engine/DataAsset.h"
#include "Engine/Texture2D.h"

#include "InventoryDataAsset.generated.h"

UCLASS()
class SOMNAMBULICCORE_API UInventoryDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = Data)
	FName ObjectName;

	UPROPERTY(EditAnywhere, Category = Data)
	FText ObjectDisplayName;
	UPROPERTY(EditAnywhere, Category = Data)
	FText ObjectDescription;

	UPROPERTY(EditAnywhere, Category=Data)
	UTexture2D * ObjectTexture = nullptr;
};
