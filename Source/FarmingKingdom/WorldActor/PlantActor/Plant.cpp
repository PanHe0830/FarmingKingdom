// Fill out your copyright notice in the Description page of Project Settings.


#include "Plant.h"
#include "../PlantComponent/PlantComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APlant::APlant()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ActorMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ActorMesh"));
	RootComponent = ActorMeshComponent;
	PlantComponent = CreateDefaultSubobject<UPlantComponent>(TEXT("PlantComponent"));
}

// Called when the game starts or when spawned
void APlant::BeginPlay()
{
	Super::BeginPlay();

	if (PlantComponent)
	{
		PlantComponent->SetPlantActor(this);
	}
}

// Called every frame
void APlant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

