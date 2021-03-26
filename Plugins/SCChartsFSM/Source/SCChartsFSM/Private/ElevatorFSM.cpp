// Fill out your copyright notice in the Description page of Project Settings.


#include "ElevatorFSM.h"
extern "C" {
#include "../kieler-gen/Elevator.h"
}


ElevatorFSM::ElevatorFSM() {
}

ElevatorFSM::~ElevatorFSM() {
}
// Wrapper for the SCCharts tick function. Also saves the last StateID as a workaround because we cann not call functions from here directly inside SCCharts
void ElevatorFSM::Tick() {
    LastStateID = tickData.stateID;
    tick(&tickData);
}


// this increments the target floor
void ElevatorFSM::InputTargetFloor(int targetFloor) {
    tickData.targetFloor = targetFloor;
}

// updates the doorOpen value in the FSM
void ElevatorFSM::InputDoorOpen(bool isOpen) {
    tickData.doorOpen = isOpen;
}
// wrapper to reset the FSM
void ElevatorFSM::Reset() {
    reset(&tickData);
}
