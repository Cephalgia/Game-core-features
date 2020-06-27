#pragma once
#include "Blueprint/UserWidget.h"

#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

#include "InventoryItemWidget.generated.h"

UCLASS()
class SOMNAMBULICCORE_API UInventoryItemWidget : public UUserWidget
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadOnly, Category = "Inventory Box", meta = (BindWidget))
	UImage * ItemImage = nullptr;
	UPROPERTY(BlueprintReadOnly, Category = "Inventory Box", meta = (BindWidget))
	UTextBlock * ItemName = nullptr;
	UPROPERTY(BlueprintReadOnly, Category = "Inventory Box", meta = (BindWidget))
	UButton * ItemButton = nullptr;
	UPROPERTY()
	UInventoryObjectBase * InventoryItem = nullptr;

	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnButtonClicked();	
};
