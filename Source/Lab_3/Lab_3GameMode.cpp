// Copyright Epic Games, Inc. All Rights Reserved.

#include "Lab_3GameMode.h"
#include "Lab_3Character.h"
#include "UObject/ConstructorHelpers.h"

ALab_3GameMode::ALab_3GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
