// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldDefaultPawn.h"
#include "PlacementBuildComponent.h"

AWorldDefaultPawn::AWorldDefaultPawn()
{
	BuildComponent = CreateDefaultSubobject<UPlacementBuildComponent>("BuildComponent");
}

void AWorldDefaultPawn::SetupPlayerInputComponent(UInputComponent* InInputComponent)
{
	Super::SetupPlayerInputComponent(InInputComponent);
}

void AWorldDefaultPawn::MouseClick()
{
	if (BuildComponent)
	{
		BuildComponent->MouseClick();
	}
}

void AWorldDefaultPawn::BeginPlay()
{
	Super::BeginPlay();
}
