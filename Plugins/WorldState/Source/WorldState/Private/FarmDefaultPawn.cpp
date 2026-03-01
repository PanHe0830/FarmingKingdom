// Fill out your copyright notice in the Description page of Project Settings.


#include "FarmDefaultPawn.h"

// Sets default values
AFarmDefaultPawn::AFarmDefaultPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFarmDefaultPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFarmDefaultPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFarmDefaultPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

