// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/TimelineComponent.h"
#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloorSwitch.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class MYDOORGAME_API AFloorSwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloorSwitch();
	/** bOX tRIGGER oVERLAP eVENT*/
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "Floor Switch")
	TObjectPtr<UBoxComponent> TriggerBox;
	/* Block for Character to step on */
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "Floor Switch")
	TObjectPtr<UStaticMeshComponent> FloorSwitch;

	/*Door raise when when the floor switch is stepped on */
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite, Category = "Floor Switch")
	TObjectPtr<UStaticMeshComponent> Door; 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
	 AActor* OtherActor, UPrimitiveComponent* OtherComp,
	 int32 otherBodyIndex, bool bFromSweep, const FHitResult & SweepResult); 
	UFUNCTION()
	 void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent,
	 AActor* OtherActor, UPrimitiveComponent* OtherComp,
	 int32 otherBodyIndex);
	 /*Called when Box Component is overlapped, Used in Blueprints to start the timeline*/
	 UFUNCTION(BlueprintImplementableEvent,Category = "Floor Switch")

	 void ActivateFloorSwitch();
	 /*When no longer overlapping, and in Blueprints to reverse the timeline*/
	UFUNCTION(BlueprintImplementableEvent,Category = "Floor Switch")
	void DeactivateFloorSwitch(); 
	

	UFUNCTION(BlueprintCallable,Category = "Floor Switch")
	void UpdateFloorSwitchLocations(float DoorLocation,float SwitchLocation);
	
	UPROPERTY(BlueprintReadWrite,Category = "Floor Switch")
	FVector InitialDoorLocation; 
	UPROPERTY(BlueprintReadWrite,Category = "Floor Switch")
	FVector InitialsSwitchLocation; 


	
	

};
