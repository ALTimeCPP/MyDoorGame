// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

class USphereComponent;
class UStaticMeshComponent;

UCLASS()
class MYDOORGAME_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();
	UPROPERTY(VisibleAnywhere, Category = "Item |Collision")
	// this will be the spher etrigger the pick up Function when charater over lap with it
	TObjectPtr<USphereComponent> CollisionVolume;

	UPROPERTY(VisibleAnywhere, Category = "Item |Mesh")
	TObjectPtr<UStaticMeshComponent> Mesh;
	
	UPROPERTY(EditAnywhere, Category = "Item |ItemProperties")
	bool bRotate = false;

	UPROPERTY(EditAnywhere, Category = "Item |ItemProperties")
	// to make item Rotate in the Air
	float RotationRate = 0.f; 

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
	 AActor* OtherActor, UPrimitiveComponent* OtherComp,
	 int32 otherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) ; 



};
