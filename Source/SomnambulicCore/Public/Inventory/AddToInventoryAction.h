#pragma once
#include "InteractionAction.h"
#include "InventoryDataAsset.h"

#include "AddToInventoryAction.generated.h"

UCLASS(BlueprintType, EditInlineNew, meta = (DisplayName = "AddToInventoryAction"))
class SOMNAMBULICCORE_API UAddToInventoryAction : public UInteractionAction
{
	GENERATED_BODY()
public:
	virtual void PerformAction(UInteractionComponent * InComponent) override;
	
protected:
	UPROPERTY(EditAnywhere, Category="Settings")
	UInventoryDataAsset * InventoryAsset = nullptr;
};
