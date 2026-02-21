// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldTime.h"

FWorldTime::FWorldTime()
{
}

FWorldTime::~FWorldTime()
{
}

float FWorldTime::GetTime() const
{
	return CurrentTime;
}

void FWorldTime::SetTime(float NewTime)
{
	CurrentTime = NewTime;
}

void FWorldTime::AddTime(float Delta)
{
	CurrentTime += Delta;
}

void FWorldTime::Tick(float Delta)
{
    //if (!bPaused)
    CurrentTime += Delta * TimeScale;
}
