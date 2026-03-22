// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

//UENUM()
//enum class XXX : uint8
//{
//};

struct FBuildRuntimeClickedContext
{
	FHitResult HitResult;
	TArray<AActor*> IgnoreActors;
	TArray<UStaticMeshComponent*> IgnoreStaticMeshComponent;
	FBoxSphereBounds BuildBound;
	bool bHit;
};

struct FBuildRuntimeBuildResult
{
	FBuildRuntimeBuildResult()
	{
		isSuccess = false;
	}
	bool isSuccess;
	FTransform FinalTransform;
};