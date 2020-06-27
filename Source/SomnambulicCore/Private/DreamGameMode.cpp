#include "DreamGameMode.h"

#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

ADreamGameMode::ADreamGameMode()
	: Super()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ADreamGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	for (auto ManagerClass : ManagerClasses)
	{
		UManagerBase * ManagerBase = NewObject<UManagerBase>(this, ManagerClass);
		ManagerBase->Initialize();
		Managers.Add(ManagerBase);
	}
}

void ADreamGameMode::StartPlay()
{
	Super::StartPlay();

	APlayerController * PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	EnableInput(PlayerController);

	for (auto Manager : Managers)
	{
		Manager->OnStartPlay();
	}
}

void ADreamGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	for (auto Manager : Managers)
	{
		Manager->Tick(DeltaSeconds);
	}
}

