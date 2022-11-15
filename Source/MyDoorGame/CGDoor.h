// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "GameFramework/Actor.h"
#include "CGDoor.generated.h"
class UBoxComponent;
class UStaticMeshComponent;

UENUM()
enum class ECGDoorState : uint8
{
	Closed,
	Closing,
	Opened,
	Opening
};



UCLASS()
class MYDOORGAME_API ACGDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACGDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	//UFUNCTION(BlueprintCallable, Category = "Door")
	//void UpdateDoorState(float DeltaTime);

	//UFUNCTION(BlueprintCallable, Category = "Door")
		//void CloseDoor();
	//UFUNCTION()
		//virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other,
		// UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
		// bool bFromSweep, const FHitResult& SweepResult);
	/*Scene Component setting*/
	//UPROPERTY(BlueprintReadOnly,VisibleAnywhere,Category = "Door")
		//ECGDoorState DoorState = ECGDoorState::Closed;

	//UPROPERTY(BlueprintReadWrite,VisibleAnywhere,Category = "Door")
		//bool bIsLocked = false; 
	//UPROPERTY(BlueprintReadOnly,VisibleAnywhere,Category = "Door")
	//	TObjectPtr<USceneComponent> SceneComponent;
	//UPROPERTY(BlueprintReadOnly,VisibleAnywhere,Category = "Door")
		//TObjectPtr<UBoxComponent> TriggerComponent;

		/*Setting up the door */
	//UPROPERTY(EditAnywhere,Category = Door)
		//class UStaticMeshComponent = MeshComponent;
		//TobjectPtr<UStaticMeshComponent> MeshComponent; 





	
	

};
