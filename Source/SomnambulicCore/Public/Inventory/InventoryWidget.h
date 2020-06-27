#pragma once
#include "Blueprint/UserWidget.h"

#include "Components/WrapBox.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

#include "Inventory/InventoryItemWidget.h"

#include "InventoryWidget.generated.h"

UCLASS()
class SOMNAMBULICCORE_API UInventoryWidget : public UUserWidget
{
	GENERATED_UCLASS_BODY()
public:

	UPROPERTY(EditAnywhere, Category = "Inventory Box")
	TSubclassOf<UInventoryItemWidget> ItemWidgetClass = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "Inventory Box", meta = (BindWidget))
	UWrapBox * ItemsBox = nullptr;
	UPROPERTY(BlueprintReadOnly, Category = "Inventory Box", meta = (BindWidget))
	UImage * DescriptionImage = nullptr;
	UPROPERTY(BlueprintReadOnly, Category = "Inventory Box", meta = (BindWidget))
	UTextBlock * DescriptionBlock = nullptr;

	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UFUNCTION()
	void OnItemButtonClicked(UInventoryItemWidget * InItemWidget);
};
