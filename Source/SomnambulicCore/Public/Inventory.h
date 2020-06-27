#pragma once
#include "UObject/Object.h"

#include "InventoryObjectBase.h"

#include "Inventory.generated.h"

UCLASS()
class SOMNAMBULICCORE_API UInventory : public UObject
{
	GENERATED_BODY()
public:

	void AddToInventory(UInventoryObjectBase* InObject);
	void RemoveFromInventory(UInventoryObjectBase* InObject);

	bool CheckObjectOwned(UInventoryObjectBase* InObject) const;

protected:

	UPROPERTY()
	TArray<UInventoryObjectBase*> OwnedObjects;
	
};
