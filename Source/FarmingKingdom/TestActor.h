// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"

class UPlantComponent;
class UStaticMeshComponent;

UCLASS()
class FARMINGKINGDOM_API ATestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = "Mesh")
	UStaticMeshComponent* ActorMeshComponent;

	UPROPERTY(EditAnywhere, Category = "Component")
	UPlantComponent* PlantComponent;
};
