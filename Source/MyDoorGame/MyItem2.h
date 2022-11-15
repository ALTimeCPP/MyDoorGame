// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "MyItem2.generated.h"

/**
 * 
 */
UCLASS()
class MYDOORGAME_API AMyItem2 : public AItem
{
	GENERATED_BODY()

	
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
	 AActor* OtherActor, UPrimitiveComponent* OtherComp,
	 int32 otherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) override;

	
};
