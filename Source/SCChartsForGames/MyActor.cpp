// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// #include "../../Plugins/SCChartsFSM/Source/SCChartsFSM/Classes/MyClass.h"
//
// extern "C" {
// #include "../../Plugins/SCChartsFSM/Source/SCChartsFSM/kieler-gen/Elevator.h"
// }
// #include "../../Plugins/SCCharts/Source/SCCharts/Classes/FSM.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
// Wrapper to relay the press of the button up to the FSM
void AMyActor::PressBtn(int floor)
{
	Queue.Enqueue(floor);
	// Elevator.InputTargetFloor(floor);
}
// Wrapper to relay the press of the button down to the FSM
void AMyActor::PressBtnDown()
{
	// Elevator.InputDown();
}
// Updates the doorOpen value inside the SCCharts model to reflect the same value inside the game
void AMyActor::UpdateDoorStatus(bool isOpen)
{
	Elevator.InputDoorOpen(isOpen);
}
// Updates the currentFloor value inside the SCCharts model to reflect the same value inside the game
void AMyActor::UpdateFloorStatus(int currentFloore)
{
	CurrentFloor = currentFloore;
	Elevator.tickData.currentFloor = currentFloore;
}
// Calls the elevator to the given floor
void AMyActor::CallElevator(int Floor)
{
	// this Queue holds the requested number of floors in order of the requests given
	Queue.Enqueue(Floor);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	// The SCCharts FSM needs to be ressetted before it can recive the first tick
	Elevator.Reset();
}

// Called every frame
// The unreal Tick function is called every frame. We make use of this to let our SCCharts tick.
// Unfortunately, as the time of writing, it is no possible to call functions whe write here directly in the SCCharts FSM.
// That's why this function handles the c++ function calls for the game behaviour depending on the states and signals from SCCharts
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Elevator.Tick();
	DebugStateID = Elevator.tickData.stateID;
	int NextFloor = -1;
	// Check if the state changed. This is necessary to not open the doors repeatedly if they are already open
	// could also be handled inside the called function separately, but I decided to handle it this way
	if (Elevator.LastStateID != DebugStateID)
	{
		switch (DebugStateID)
		{
		case 1: // State: OpenDoors
			OpenOutsideDoors(Elevator.tickData.currentFloor); // Open the doors at the floor given by the SCCharts value currentFloor
			OpenElevatorRoomDoors(); // also opens the Elevator door so people can get in
			break;
		case 3: // State: Wait
			CloseOutsideDoors(Elevator.tickData.currentFloor); // Close the doors at the floor given by the SCCharts value currentFloor
			CloseElevatorRoomDoors(); // also closes the Elevator door so it i ready for movement
			break;
		case 4: // State: MovingUp;
			break;
		case 5: // State: MovingDown;
			break;
		default:
			break;
		}
	} else if (Elevator.LastStateID == 2) // this needs to be called every tick. Otherwise we would be stuck in the Waiting state
	{
		if ( Queue.Dequeue(NextFloor)) // the Queue that holds the requested floor destinations
		{
			// if Dequeue was successful at dequeuing and writing its value to nextFloor
			Elevator.tickData.targetFloor = NextFloor; // the value is written to the SCCharts targetFloor value
		}
	}
	
	// hanldes the output signals of the SCCharts
	if (Elevator.tickData.moveUp) // if moveUp is present
	{
		MoveElevator(true, Elevator.tickData.numFloorsToMove); // move the Elevator up by the given numbers of floors
	}
	if (Elevator.tickData.moveDown) // if moveDown is present
	{
		MoveElevator(false, Elevator.tickData.numFloorsToMove); // move the Elevator down by the given numbers of floors
	}
}

