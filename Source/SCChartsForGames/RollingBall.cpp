#include "RollingBall.h"

ARollingBall::ARollingBall() {
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ARollingBall::BeginPlay() {
	Super::BeginPlay();
	Init();
}

// function to initialize the Actor
void ARollingBall::Init() {
	RollingBallHS.Reset();
	RollingBallHS.Setup(100, 25,10,0.25);
}

void ARollingBall::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	// retrieve the current velocity as a vector
	const FVector V = GetVelocity();

	// the new acceleration for this tick returned from the SCCharts wrapper
	// the Tick function receives the current velocity vector V's magnitude to
	// so the total direction independent speed is used
	float Accel =  RollingBallHS.Tick(V.Size(), DeltaTime);
	// GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Accel %f"), Accel));
	// This limits the Acceleration to |Accel| <= 10000 to prevent to erratic behavior
	Accel = FMath::Sign(Accel) * FMath::Min<float>(FMath::Abs(Accel), 5000);
	if (IsValid(Component)) { // checks if the component is exists
		// sets the newly received acceleration as the new force for the ball in x direction
		Component->AddForce(FVector(Accel,0,0),NAME_None,true);
	}
}

// created by UE4
void ARollingBall::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

