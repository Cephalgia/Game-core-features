#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"

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
};
