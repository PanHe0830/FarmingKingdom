// Fill out your copyright notice in the Description page of Project Settings.


#include "FarmPlayerController.h"
#include "Components/InputComponent.h"
#include "GameFramework/PlayerInput.h"
#include "WorldDefaultPawn.h"
#include "PlacementResult.h"

void SelfBindAction()
{
	static bool bIsBound = false;
	if (!bIsBound)
	{
		bIsBound = true;

		UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("Farm_Mouse_Click", EKeys::LeftMouseButton));
	}
}

void AFarmPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	SelfBindAction();

	InputComponent->BindAction("Farm_Mouse_Click", IE_Pressed, this, &AFarmPlayerController::MouseClick);
}

void AFarmPlayerController::BeginPlay()
{
	Super::BeginPlay();

}

void AFarmPlayerController::MouseClick()
{
	AWorldDefaultPawn* defaultPawn = Cast<AWorldDefaultPawn>(GetPawn());
	if (defaultPawn == nullptr) return;
	float mouseX, mouseY;
	FHitResult HitResult;
	if (!GetMousePosition(mouseX, mouseY)) return;
	FVector WorldLocation;
	FVector WorldDirection;
	
	DeprojectScreenPositionToWorld(mouseX, mouseY, WorldLocation, WorldDirection);
	
	FVector Start = WorldLocation;
	FVector End = WorldLocation + WorldDirection * hitDistance;
	
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(GetPawn()); // 忽略自己
	
	bool bHit = GetWorld()->LineTraceSingleByChannel(
		HitResult,
		Start,
		End,
		ECC_Visibility,
		Params
	);

	//FBRTIgnoreContext ignoreContext;
	//
	//FBRTActorContext actorContext;
	//actorContext.BuildBound = FBoxSphereBounds(HitResult.ImpactPoint, FVector(50, 50, 50), 50);
	//
	//FBRTHitResult hitContext;
	//hitContext.HitResult = HitResult;
	//hitContext.bHit = bHit;
	
	FBuildRuntimeClickedContext buildContext;
	buildContext.HitResult;
	buildContext.BuildBound;
	buildContext.IgnoreActors;
	buildContext.IgnoreStaticMeshComponent;
	buildContext.bHit = bHit;
	defaultPawn->MouseClick(buildContext);
}
