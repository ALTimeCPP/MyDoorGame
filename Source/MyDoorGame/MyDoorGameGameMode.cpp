// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyDoorGameGameMode.h"
#include "MyDoorGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMyDoorGameGameMode::AMyDoorGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
