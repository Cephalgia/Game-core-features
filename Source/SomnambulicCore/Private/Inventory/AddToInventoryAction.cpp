#include "Inventory/AddToInventoryAction.h"

#include "Engine/World.h"

#include "DreamGameMode.h"
#include "Inventory/Inventory.h"
#include "InteractionComponent.h"

void UAddToInventoryAction::PerformAction(UInteractionComponent * InComponent)
{
	Super::PerformAction(InComponent);

	if (!InventoryAsset)
	{
		return;
	}

	if (ADreamGameMode * GameMode = Cast<ADreamGameMode>(GetWorld()->GetAuthGameMode()))
	{
		if (UInventory * Inventory = GameMode->GetManager<UInventory>())
		{
			UInventoryObjectBase * ItemObject = NewObject<UInventoryObjectBase>(Inventory);
			ItemObject->Init(InventoryAsset);
			Inventory->AddToInventory(ItemObject);
		}
	}
}