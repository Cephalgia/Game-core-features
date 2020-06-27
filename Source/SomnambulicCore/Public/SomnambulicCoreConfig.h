#pragma once
#include "UObject/Object.h"
#include "Engine/Font.h"
#include "SomnambulicCoreConfig.generated.h"

UCLASS(config = Game, defaultconfig)
class SOMNAMBULICCORE_API USomnambulicCoreConfig : public UObject
{
	GENERATED_BODY()

public:
	USomnambulicCoreConfig(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer) {};

	UPROPERTY(config, EditAnywhere, Category = UI)
	TSoftObjectPtr<UFont> DefaultFont;
};