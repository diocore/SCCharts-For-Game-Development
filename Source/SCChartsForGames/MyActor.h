// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

// extern "C" {
// #include "../../Plugins/SCChartsFSM/Source/SCChartsFSM/kieler-gen/Elevator.h"
// }
#include "ElevatorFSM.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"



UCLASS()
class SCCHARTSFORGAMES_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	UFUNCTION(BlueprintCallable)
	void PressBtn(int floor);
	UFUNCTION(BlueprintCallable)
	void PressBtnDown();
	UFUNCTION(BlueprintCallable)
	void UpdateDoorStatus(bool isOpen);
	UFUNCTION(BlueprintCallable)
	void UpdateFloorStatus(int currentFloore);

	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
	void OpenOutsideDoors(int floor);


	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
    void CloseOutsideDoors(int floor);
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
	void OpenElevatorRoomDoors();
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
	void CloseElevatorRoomDoors();
	UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
	void MoveElevator(bool up, int numOfFloors);
	UFUNCTION(BlueprintCallable)
	void CallElevator(int Floor);

	TQueue<int> Queue;
	
	//SCCharts data
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	ElevatorFSM Elevator = ElevatorFSM();
	bool bDoorOpen;
	UPROPERTY(BlueprintReadWrite)
	bool bMoving;
	UPROPERTY(BlueprintReadWrite)
	int CurrentFloor;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(BlueprintReadOnly)
	int DebugStateID = 0;

};
