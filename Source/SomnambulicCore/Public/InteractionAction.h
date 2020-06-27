#pragma once
#include "UObject/Object.h"

#include "InteractionAction.generated.h"

class UInteractionComponent;

UCLASS(abstract)
class SOMNAMBULICCORE_API UInteractionAction : public UObject
{
	GENERATED_BODY()
public:
	virtual void PerformAction(UInteractionComponent * InComponent);
	virtual bool CanPerformAction(UInteractionComponent * InComponent);
protected:
	int32 InteractionCounter = 0;

	UPROPERTY(EditAnywhere, Category = "Settings")
		bool bInfinite;
};
