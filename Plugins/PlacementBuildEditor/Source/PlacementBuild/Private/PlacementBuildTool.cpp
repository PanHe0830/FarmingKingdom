// Fill out your copyright notice in the Description page of Project Settings.


#include "PlacementBuildTool.h"

PlacementBuildTool::PlacementBuildTool()
{
}

PlacementBuildTool::~PlacementBuildTool()
{
    World = nullptr;
}

void PlacementBuildTool::Initialize(UWorld* InWorld)
{
    World = InWorld;
}

FBuildRuntimeBuildResult PlacementBuildTool::GetRuntimeBuildResult(const FBuildRuntimeClickedContext& ClickedContext)
{
    return FBuildRuntimeBuildResult();
}
