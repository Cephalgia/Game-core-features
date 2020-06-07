#pragma once
#include "UObject/Object.h"

#include "InteractionAction.generated.h"


UCLASS(BlueprintType)
class SOMNAMBULICCORE_API UInteractionAction : public UObject
{
	GENERATED_BODY()
public:
	virtual void PerformAction() {};
	
};
