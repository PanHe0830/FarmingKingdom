// Fill out your copyright notice in the Description page of Project Settings.


#include "UWorldStateSubsystem.h"
#include "WorldTime.h"
#include "TimerManager.h"
#include "EntityComponent.h"

void UUWorldStateSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);

    // 创建 FWorldTime 实例
    WorldTime = MakeUnique<FWorldTime>();

    // 设置一个定时器，每秒推进一次世界时间
    GetWorld()->GetTimerManager().SetTimer(
        TimeUpdateHandle,
        [this]()
        {
            // 假设每秒推进1秒
            WorldTime->Tick(1.f);

            // 广播给注册的 Component 更新状态
            for (auto& Component : RegisteredComponents)
            {
                if (Component.IsValid())
                {
                    Component->UpdateFromTime(WorldTime->GetTime());
                }
            }
        },
        1.0f, // 每1秒触发一次
        true  // 循环
    );
}

void UUWorldStateSubsystem::Deinitialize()
{
    // 释放实例
    if (WorldTime)
    {
        WorldTime.Reset();
    }

    Super::Deinitialize();
}

float UUWorldStateSubsystem::GetWorldTime() const
{
	return WorldTime.Get()->GetTime();
}

void UUWorldStateSubsystem::RegisterComponent(UEntityComponent* Component)
{
    if (Component && !RegisteredComponents.Contains(Component))
    {
        RegisteredComponents.Add(Component);
    }
}

void UUWorldStateSubsystem::UnregisterComponent(UEntityComponent* Component)
{
    if (Component)
    {
        RegisteredComponents.Remove(Component);
	}
}

