// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyDoor.generated.h"

class AMyDoorGameCharacter;
//class ATriggerBox;
UCLASS()
class MYDOORGAME_API AMyDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyDoor();
private:
	

	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = "Components", meta = (AllowPrivateAccess="true"))
	UStaticMeshComponent* MyDoor;

	AMyDoorGameCharacter* ACharacter;
	//ATriggerBox* TriggerBox;
	void OpenDoor();
	
UPROPERTY(EditAnywhere)
	FRotator StartRotation = FRotator::ZeroRotator;
	FRotator FinalRotation = FRotator::ZeroRotator;
	FRotator DesiredRotation = FRotator::ZeroRotator; 

	//Angle 
	UPROPERTY(EditAnywhere,Category = "Components" )
	float Angle = 90.f;
	float CurrentAngle =0.0f; 

	UPROPERTY(EditAnywhere,Category = "Components" )
	float TimeToRotate = 1.0f;
	float CurrentRotationTime =0.0f;  

	UPROPERTY(EditAnywhere,Category = "Curve")
		FRuntimeFloatCurve OpenCurve;
	
	UPROPERTY(EditAnywhere, Category = "Door Sound")
		class USoundBase* DoorSound; 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
