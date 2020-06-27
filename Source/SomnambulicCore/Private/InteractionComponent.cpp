#include "InteractionComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"

UInteractionComponent::UInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();
	

	HintComponent = NewObject<UTextRenderComponent>(GetOwner());
	HintComponent->SetupAttachment(GetOwner()->GetRootComponent());
	HintComponent->RegisterComponent();
	HintComponent->SetVisibility(false);
	HintComponent->SetText("Interact");
	HintComponent->SetRelativeLocation(GetRelativeLocation());
}

void UInteractionComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	APlayerController * PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	GetOwner()->DisableInput(PlayerController);
}

void UInteractionComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	APlayerCameraManager * CameraManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
	FVector EyesLocation;
	FRotator EyesRotation;
	CameraManager->GetActorEyesViewPoint(EyesLocation, EyesRotation);
	if ((EyesLocation - GetOwner()->GetActorLocation()).SizeSquared2D() < FMath::Square(150.f))
	{
		if (HintComponent)
		{
			if (!HintComponent->IsVisible())
			{
				HintComponent->SetVisibility(true);
				APlayerController * PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
				GetOwner()->EnableInput(PlayerController);
				if (UInputComponent * InputComponent = Cast<UInputComponent>(GetOwner()->GetComponentByClass(UInputComponent::StaticClass())))
				{
					InputComponent->BindAction("Interact", EInputEvent::IE_Pressed, this, &UInteractionComponent::Interact);
				}
			}
			else
			{
				//rotate to camera
				FRotator NewRotation = UKismetMathLibrary::FindLookAtRotation(HintComponent->GetComponentLocation(), EyesLocation);
				HintComponent->SetComponentToWorld(FTransform(NewRotation, HintComponent->GetComponentTransform().GetLocation(), HintComponent->GetComponentTransform().GetScale3D()));
			}
		}
	}
	else
	{
		if (HintComponent && HintComponent->IsVisible())
		{
			HintComponent->SetVisibility(false);
			APlayerController * PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
			GetOwner()->DisableInput(PlayerController);
			
		}
	}
}

void UInteractionComponent::Interact()
{
	//trace check
	APlayerCameraManager * CameraManager = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
	FHitResult HitResult;	
	FVector EyesLocation;
	FRotator EyesRotation;
	CameraManager->GetActorEyesViewPoint(EyesLocation, EyesRotation);
	FVector EyeVector = CameraManager->GetActorForwardVector();
	//doesn't hit farther parts if they are not in range, might not be an issue for smaller objects
	GetWorld()->LineTraceSingleByChannel(HitResult, EyesLocation, EyesLocation + EyeVector*150.f, ECollisionChannel::ECC_Visibility);

	AActor * HitActor = HitResult.GetActor();
	AActor * OwnActor = GetOwner();

	if (HitActor == OwnActor)
	{
		OnInteractionDelegate.ExecuteIfBound();

		for (auto Action : Actions)
		{
			Action->PerformAction(this);
		}
	}
}