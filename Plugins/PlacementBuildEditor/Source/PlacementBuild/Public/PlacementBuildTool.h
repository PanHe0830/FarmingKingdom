// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlacementResult.h"

/**
 * 
 */
class PLACEMENTBUILD_API PlacementBuildTool
{
public:
	PlacementBuildTool();
	~PlacementBuildTool();

public:
	FBuildRuntimeBuildResult GetRuntimeBuildResult(const FBuildRuntimeClickedContext& ClickedContext);
};
