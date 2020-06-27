#pragma once

#include "UObject/Object.h"

#include "ManagerBase.generated.h"


UCLASS(abstract, BlueprintType, config = AdvancedLevelStreaming, meta = (DisplayName = "LevelManager"))
class SOMNAMBULICCORE_API UManagerBase : public UObject
{
	GENERATED_BODY()

public:
	virtual void Initialize() {};

	virtual void OnStartPlay() {};
	virtual void Tick(float DeltaSeconds) {};

};
