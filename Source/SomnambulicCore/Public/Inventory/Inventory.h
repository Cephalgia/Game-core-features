#pragma once
#include "ManagerBase.h"

#include "Inventory/InventoryObjectBase.h"
#include "Inventory/InventoryWidget.h"

#include "Inventory.generated.h"

UCLASS()
class SOMNAMBULICCORE_API UInventory : public UManagerBase
{
	GENERATED_BODY()
public:

	void AddToInventory(UInventoryObjectBase* InObject);
	void RemoveFromInventory(UInventoryObjectBase* InObject);

	bool CheckObjectOwned(UInventoryObjectBase* InObject) const;

	virtual void OnStartPlay() override;

	UPROPERTY()
	UInventoryWidget * UIWidget = nullptr;

protected:

	UPROPERTY()
	TArray<UInventoryObjectBase*> OwnedObjects;

	void OpenInventoryUI();
	
	friend class UInventoryWidget;
};
