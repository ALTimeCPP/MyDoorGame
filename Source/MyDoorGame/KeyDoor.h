// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DoorActor.h"
#include "KeyDoor.generated.h"

/**
 * 
 */
UCLASS()
class MYDOORGAME_API AKeyDoor : public ADoorActor
{
	GENERATED_BODY()

	virtual void OnInteract(AMyDoorGameCharacter* User) override;
	
};
