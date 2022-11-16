// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/TimelineComponent.h" // Because Timeline is struct you need to include it in the Header file 
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorActor.generated.h"

class AMyDoorGameCharacter;
 
UCLASS()
class MYDOORGAME_API ADoorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoorActor();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	virtual void OnInteract(AMyDoorGameCharacter* User);

	//UPROPERTY(Transient)
	//TObjectPtr<AMyDoorGameCharacter> Character;

private:
	UPROPERTY(EditAnywhere, Category = "Mesh")
	TObjectPtr<UStaticMeshComponent> DoorFrame;

	UPROPERTY(EditAnywhere, Category = "Mesh")
	TObjectPtr<UStaticMeshComponent> Door;
	
protected:
	
	FTimeline Timeline;
	UPROPERTY(EditAnywhere)
	TObjectPtr<UCurveFloat> CurveFloat;

	bool bIsDoorClosed = true; 
	UPROPERTY(EditAnywhere)
	float DoorRotateAngle = 90.f; 

	UFUNCTION()
	void OpenDoor(float Value); // Bind Function

	bool bDoorOnSameSide = false;
	bool IsDoorOnSameSide(AActor* User) const;

};
