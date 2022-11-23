// Fill out your copyright notice in the Description page of Project Settings.


#include "TheCharacter.h"

// Sets default values
ATheCharacter::ATheCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATheCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATheCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATheCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

