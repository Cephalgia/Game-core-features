#pragma once

#include "Components/SceneComponent.h"
#include "Components/TextRenderComponent.h"

#include "InteractionAction.h"

#include "InteractionComponent.generated.h"

DECLARE_DELEGATE(FOnInteractionDelegate)

UCLASS(BlueprintType, meta = (BlueprintSpawnableComponent))
class SOMNAMBULICCORE_API UInteractionComponent : public USceneComponent
{
	GENERATED_BODY()
public:

	UInteractionComponent();
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	FOnInteractionDelegate OnInteractionDelegate;

protected:
	void Interact();

protected:
	UPROPERTY(EditAnywhere, Instanced, Category="Settings")
	TArray<UInteractionAction*> Actions;

	UTextRenderComponent * HintComponent = nullptr;
};
