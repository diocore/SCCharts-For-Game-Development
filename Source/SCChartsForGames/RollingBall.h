// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "RollingBallHybridSystem.h"
#include "RollingBall.generated.h"


UCLASS()
class SCCHARTSFORGAMES_API ARollingBall : public APawn {
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARollingBall();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
	void Init();
	UPROPERTY(BlueprintReadWrite)
	// the 3D Ball object in the world which is alos the root of this Actor
	UPrimitiveComponent* Component;
	// The SCChart wrapper class
	RollingBallHybridSystem RollingBallHS;
};
