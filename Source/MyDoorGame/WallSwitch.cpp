// Fill out your copyright notice in the Description page of Project Settings.


#include "WallSwitch.h"

// Sets default values
AWallSwitch::AWallSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWallSwitch::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AWallSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

