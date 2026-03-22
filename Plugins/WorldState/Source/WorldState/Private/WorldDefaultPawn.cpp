// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldDefaultPawn.h"
#include "PlacementBuildComponent.h"
#include "PlacementResult.h"

AWorldDefaultPawn::AWorldDefaultPawn()
{
	BuildComponent = CreateDefaultSubobject<UPlacementBuildComponent>("BuildComponent");
}

void AWorldDefaultPawn::SetupPlayerInputComponent(UInputComponent* InInputComponent)
{
	Super::SetupPlayerInputComponent(InInputComponent);
}

void AWorldDefaultPawn::MouseClick(FBuildRuntimeClickedContext& context)
{
	if (BuildComponent)
	{
		BuildComponent->MouseClick(context);
	}
}

void AWorldDefaultPawn::BeginPlay()
{
	Super::BeginPlay();
}
