// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "MyDoorGameCharacter.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CollisionVolume = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionVolume"));
	//CollisionVolume = RootComponent; 
	SetRootComponent(CollisionVolume);
	//RootComponent = CollisionVolume; 
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());


}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	CollisionVolume->OnComponentBeginOverlap.AddDynamic(this,&AItem::OnOverlapBegin);

	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// if  it is works we need  to see the
	if(bRotate)
	{
		FRotator Rotation = GetActorRotation();
		Rotation.Yaw += DeltaTime * RotationRate;
		SetActorRotation(Rotation); 
	}

	

}
void AItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
	 AActor* OtherActor, UPrimitiveComponent* OtherComp,
	 int32 otherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
 {

	UE_LOG(LogTemp, Warning, TEXT("On OverlapBegin"));

	AMyDoorGameCharacter* Character = Cast<AMyDoorGameCharacter>(OtherActor); 

	if(Character)
	{
 		Character -> KeyOne = true;
		Destroy();
	}
	//Destroy();




}
