// Fill out your copyright notice in the Description page of Project Settings.


#include "FarmPlayerController.h"
#include "Components/InputComponent.h"
#include "GameFramework/PlayerInput.h"

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
	//FHitResult HitResult;
	//GetHitResultUnderCursor(ECC_Visibility, false, HitResult);
	//if (HitResult.bBlockingHit)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Hit Actor: %s"), *HitResult.GetActor()->GetName());
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("No Hit"));
	//}
}
