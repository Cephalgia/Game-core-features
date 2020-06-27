#include "Inventory/InventoryObjectBase.h"

#include "Inventory/InventoryDataAsset.h"

void UInventoryObjectBase::Init(UInventoryDataAsset * ItemDataAsset)
{
	ObjectName = ItemDataAsset->ObjectName;

	ObjectDisplayName = ItemDataAsset->ObjectDisplayName;
	ObjectDescription = ItemDataAsset->ObjectDescription;

	ObjectTexture = ItemDataAsset->ObjectTexture;

}
