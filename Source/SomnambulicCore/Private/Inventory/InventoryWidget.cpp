#include "Inventory/InventoryWidget.h"

#include "Inventory/Inventory.h"
#include "DreamGameMode.h"

UInventoryWidget::UInventoryWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bIsFocusable = true;
}

void UInventoryWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (ADreamGameMode * GameMode = Cast<ADreamGameMode>(GetWorld()->GetAuthGameMode()))
	{
		if (UInventory * Inventory = GameMode->GetManager<UInventory>())
		{
			ItemsBox->ClearChildren();
			for (auto Item : Inventory->OwnedObjects)
			{
				if (UInventoryItemWidget * ItemWidget = CreateWidget<UInventoryItemWidget>(this, ItemWidgetClass))
				{
					ItemWidget->ItemImage->SetBrushFromTexture(Item->ObjectTexture);
					ItemWidget->ItemName->SetText(Item->ObjectDisplayName);
					ItemWidget->InventoryItem = Item;

					ItemsBox->AddChildToWrapBox(ItemWidget);
				}
			}
		}
	}
}

void UInventoryWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
}

void UInventoryWidget::OnItemButtonClicked(UInventoryItemWidget * InItemWidget)
{
	DescriptionImage->SetBrushFromTexture(InItemWidget->InventoryItem->ObjectTexture);
	DescriptionBlock->SetText(InItemWidget->InventoryItem->ObjectDescription);
}