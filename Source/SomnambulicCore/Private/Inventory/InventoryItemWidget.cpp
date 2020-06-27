#include "Inventory/InventoryItemWidget.h"

#include "Inventory/InventoryWidget.h"

void UInventoryItemWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (ItemButton)
	{
		ItemButton->OnClicked.AddUniqueDynamic(this, &UInventoryItemWidget::OnButtonClicked);
	}
}

void UInventoryItemWidget::OnButtonClicked()
{
	if (UInventoryWidget * InventoryWidget = Cast<UInventoryWidget>(GetOuter()->GetOuter()))
	{
		InventoryWidget->OnItemButtonClicked(this);
	}
}