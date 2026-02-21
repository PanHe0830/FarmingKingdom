// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class WORLDSTATE_API FWorldTime
{
public:
	FWorldTime();
	~FWorldTime();

    // 获取当前时间
    float GetTime() const;

    // 设置时间（可以用在离线结算或跳跃时间）
    void SetTime(float NewTime);

    // 增加时间（可以用在时间流逝）
    void AddTime(float Delta);

    void Tick(float Delta);

private:
    float CurrentTime = 0.0f;

	//bool bPaused = false; // 是否暂停时间流逝
    float TimeScale = 1.0f; // 1.0 正常 2.0 双倍速
};
