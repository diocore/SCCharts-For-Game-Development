// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

extern "C" {
	#include "../kieler-gen/Elevator.h"
}

class SCCHARTSFSM_API ElevatorFSM {
public:
	ElevatorFSM();
	~ElevatorFSM();
	void Tick();
	void Reset();
	void InputTargetFloor(int targetFloor);
	void InputDoorOpen(bool isOpen);
	TickData tickData = TickData();
	int LastStateID;
};