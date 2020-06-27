#include "DreamGameMode.h"

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
	}
	//LevelManager = NewObject<ULevelManager>(this);
	//LevelManager->Initialize();
}

void ADreamGameMode::StartPlay()
{
	//if (LevelManager)
	//	LevelManager->OnStartPlay();
	Super::StartPlay();;
}

void ADreamGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	//if (LevelManager)
	//	LevelManager->Tick(DeltaSeconds);
}

