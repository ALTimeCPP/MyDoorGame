// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorSwitch.h"
#include "Engine/TriggerBox.h" 
#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "MyDoorGameCharacter.h"


// Sets default values
AFloorSwitch::AFloorSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggeBox"));
	//TriggerBox->SetupAttachment(RootComponent); 
	//TriggerBox->SetupAttachment(RootComponent); 
	//RootComponent = TriggerBox; 
	//TriggerBox->SetRootComponent(RootComponent);
	SetRootComponent(TriggerBox);
	TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	TriggerBox->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic); 

	TriggerBox-> SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);

	TriggerBox-> SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn,ECollisionResponse::ECR_Overlap);
	

	TriggerBox->SetBoxExtent(FVector(62.f,62.f,32.f)); 

	FloorSwitch= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorSwitch"));
	FloorSwitch->SetupAttachment(GetRootComponent());
	Door= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door-> SetupAttachment(GetRootComponent());


}

// Called when the game starts or when spawned
void AFloorSwitch::BeginPlay()
{
	Super::BeginPlay();
	InitialDoorLocation = Door->GetComponentLocation();
	InitialsSwitchLocation = FloorSwitch->GetComponentLocation(); 

	TriggerBox->OnComponentBeginOverlap.AddDynamic(this,&AFloorSwitch::OnOverlapBegin);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this,&AFloorSwitch::OnOverlapEnd);
}

// Called every frame
void AFloorSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);



}
void AFloorSwitch::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
	 AActor* OtherActor, UPrimitiveComponent* OtherComp,
	 int32 otherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AMyDoorGameCharacter* Character = Cast< AMyDoorGameCharacter>(OtherActor);
	 

	if(Character)
	{
		 ActivateFloorSwitch(); 

	}


}
void AFloorSwitch::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent,
	 AActor* OtherActor, UPrimitiveComponent* OtherComp,
	 int32 otherBodyIndex)
{
	AMyDoorGameCharacter* Character = Cast< AMyDoorGameCharacter>(OtherActor);
	 

	if(Character)
	{
		DeactivateFloorSwitch(); 

	}


}
void AFloorSwitch::UpdateFloorSwitchLocations(float DoorLocation,float SwitchLocation)
{
	FVector NewDoorLocation = InitialDoorLocation;
	NewDoorLocation.Z += DoorLocation;
	Door->SetWorldLocation(NewDoorLocation);

	FVector NewSwitchLocation = InitialsSwitchLocation;
	NewSwitchLocation.Z += SwitchLocation; 
	FloorSwitch->SetWorldLocation(NewSwitchLocation);

}
