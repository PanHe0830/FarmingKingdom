// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

//UENUM()
//enum class XXX : uint8
//{
//};

struct FBuildRuntimeClickedContext
{

};

struct FBuildRuntimeBuildResult
{
	FBuildRuntimeBuildResult()
	{
		isSuccess = false;
	}
	bool isSuccess;
};