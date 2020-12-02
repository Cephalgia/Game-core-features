#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

#include "ManagerBase.h"

#include "DreamGameMode.generated.h"

UCLASS(BlueprintType, config = AdvancedLevelStreaming, meta = (DisplayName = "DreamGameMode"))
class SOMNAMBULICCORE_API ADreamGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ADreamGameMode();
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage);
	virtual void StartPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY()
	TArray<UManagerBase*> Managers;

	UPROPERTY(EditAnywhere, Category=Settings)
	TArray<TSubclassOf<UManagerBase>> ManagerClasses;
	UPROPERTY(EditAnywhere, Category = Settings)
	TSubclassOf<UUserWidget> UIWidgetClass;


	template<typename T>
	T* GetManager () const
	{
		for (auto Manager : Managers)
		{
			if (Manager->IsA(T::StaticClass()))
			{
				return Cast<T>(Manager);
			}
		}
		return nullptr;
	}

	static bool IsLocationInViewport(const UObject * WorldContextObject, FVector Location)
	{
		if (APlayerController * PlayerController = UGameplayStatics::GetPlayerController(WorldContextObject->GetWorld(), 0))
		{
			int32 SizeX, SizeY;
			PlayerController->GetViewportSize(SizeX, SizeY);
			FVector2D ScreenPosition;
			UGameplayStatics::ProjectWorldToScreen(PlayerController, Location, ScreenPosition);

			return (ScreenPosition.X < 0.f || ScreenPosition.X > SizeX) && (ScreenPosition.Y < 0.f || ScreenPosition.Y > SizeY);
		}
		return false;
	}

	static bool IsLocationVisible(const UObject * WorldContextObject, FVector Location)
	{
		if (APlayerCameraManager * CameraManager = UGameplayStatics::GetPlayerCameraManager(WorldContextObject->GetWorld(), 0))
		{
			FHitResult HitResult;
			return !WorldContextObject->GetWorld()->LineTraceSingleByChannel(HitResult, CameraManager->GetCameraLocation(), Location, ECollisionChannel::ECC_Visibility);
		}
		return false;
	}

	static bool IsLocationArrayVisible(const UObject * WorldContextObject, TArray<FVector> Locations)
	{
		for (FVector Location : Locations)
		{
			if (ADreamGameMode::IsLocationInViewport(WorldContextObject, Location))
			{
				if (ADreamGameMode::IsLocationVisible(WorldContextObject, Location))
				{
					return false;
				}
			}
		}
		return false;
	}
};
