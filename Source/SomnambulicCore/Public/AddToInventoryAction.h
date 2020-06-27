#pragma once
#include "InteractionAction.h"
#include "InventoryDataAsset.h"

#include "AddToInventoryAction.generated.h"

UCLASS(abstract)
class SOMNAMBULICCORE_API UAddToInventoryAction : public UInteractionAction
{
	GENERATED_BODY()
public:
	virtual void PerformAction(UInteractionComponent * InComponent) override;
	
protected:
	UPROPERTY()
	UInventoryDataAsset * InventoryAsset = nullptr;
};
