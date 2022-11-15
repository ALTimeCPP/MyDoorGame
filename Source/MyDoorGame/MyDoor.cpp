// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDoor.h"
#include "MyDoorGameCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMyDoor::AMyDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));

}

// Called when the game starts or when spawned
void AMyDoor::BeginPlay()
{
	Super::BeginPlay();
	
	OpenDoor();

	
}

// Called every frame
void AMyDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AMyDoor::OpenDoor()
{	// tHE GREEN CODE FOR THE NORMAL ROTATION 
	FRotator CurrentRotation = GetActorRotation(); 
	FRotator NewRotation; 
	NewRotation.Yaw += Angle; 
	

	//Delay(); 
			
	SetActorRotation(NewRotation); 

	 
	


}


