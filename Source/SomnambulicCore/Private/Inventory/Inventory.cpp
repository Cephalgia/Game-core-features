#include "Inventory/Inventory.h"

#include "Engine/World.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Kismet/GameplayStatics.h"

#include "DreamGameMode.h"

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

void UInventory::OnStartPlay()
{
	if (ADreamGameMode * GameMode = Cast<ADreamGameMode>(GetWorld()->GetAuthGameMode()))
	{
		if (UInputComponent * InputComponent = Cast<UInputComponent>(GameMode->GetComponentByClass(UInputComponent::StaticClass())))
		{
			InputComponent->BindAction("ShowUI", EInputEvent::IE_Pressed, this, &UInventory::OpenInventoryUI);
		}
	}
}

void UInventory::OpenInventoryUI()
{
	if (!UIWidget)
	{
		if (ADreamGameMode * GameMode = Cast<ADreamGameMode>(GetWorld()->GetAuthGameMode()))
		{
			UUserWidget * NewWidget = CreateWidget(GetWorld(), GameMode->UIWidgetClass);
			UIWidget = Cast<UInventoryWidget>(NewWidget);
			if (UIWidget)
			{
				UIWidget->AddToViewport();
				APlayerController * PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
				UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(PlayerController, UIWidget);
				UIWidget->SetFocus();
				PlayerController->bShowMouseCursor = true;
			}
		}
	}
	else if (UIWidget->IsInViewport())
	{
		UIWidget->RemoveFromViewport();
		APlayerController * PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
		PlayerController->bShowMouseCursor = false;
	}
	else
	{
		UIWidget->AddToViewport();
		APlayerController * PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(PlayerController, UIWidget);
		UIWidget->SetFocus();
		PlayerController->bShowMouseCursor = true;
	}
}