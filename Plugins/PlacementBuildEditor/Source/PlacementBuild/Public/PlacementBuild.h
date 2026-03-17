// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

// 修正包含路径，确保包含正确的头文件
#include "Modules/ModuleManager.h"

class FPlacementBuildModule : public IModuleInterface
{
public:
    /** IModuleInterface implementation */
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};