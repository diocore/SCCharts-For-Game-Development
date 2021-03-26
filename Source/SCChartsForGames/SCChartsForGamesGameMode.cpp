// Copyright Epic Games, Inc. All Rights Reserved.

#include "SCChartsForGamesGameMode.h"
#include "SCChartsForGamesCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASCChartsForGamesGameMode::ASCChartsForGamesGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
