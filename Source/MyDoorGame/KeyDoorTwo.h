// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DoorActor.h"
#include "KeyDoorTwo.generated.h"

/**
 * 
 */
UCLASS()
class MYDOORGAME_API AKeyDoorTwo : public ADoorActor
{
	GENERATED_BODY()

	virtual void OnInteract(AMyDoorGameCharacter* User) override;
	
};
