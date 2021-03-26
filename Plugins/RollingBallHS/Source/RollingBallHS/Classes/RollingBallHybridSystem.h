// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
extern "C" {
#include "../kieler-gen/RollingBall.h"
}

class ROLLINGBALLHS_API RollingBallHybridSystem {
public:
	RollingBallHybridSystem();
	~RollingBallHybridSystem();
	float Tick(float Velocity, float DeltaTime);
	void Reset();
	void Setup(float TargetSpeed = 50,float Kp = 1 ,float Ki = 1,float Kd = 1);
	TickData TickData;
};
