#include "Inventory.h"

void UInventory::AddToInventory(UInventoryObjectBase* InObject)
{
	OwnedObjects.AddUnique(InObject);
}

void UInventory::RemoveFromInventory(UInventoryObjectBase* InObject)
{
	OwnedObjects.Remove(InObject);
}

bool UInventory::CheckObjectOwned(UInventoryObjectBase* InObject) const
{
	return OwnedObjects.Contains(InObject);
}