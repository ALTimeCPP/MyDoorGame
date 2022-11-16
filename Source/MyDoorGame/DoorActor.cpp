// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorActor.h"
#include "Components/TimelineComponent.h"// Add in here
#include "MyDoorGameCharacter.h" // add this 



// Sets default values
ADoorActor::ADoorActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DoorFrame = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorFrame"));
	DoorFrame->SetupAttachment(RootComponent); 

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door -> SetupAttachment(DoorFrame);


}

// Called when the game starts or when spawned
void ADoorActor::BeginPlay()
{
	Super::BeginPlay();
	// Binding the Door 
	if(CurveFloat)
	{
		FOnTimelineFloat TimelineProgress; // Got it From the chat 
		TimelineProgress.BindDynamic(this,&ADoorActor::OpenDoor);
		Timeline.AddInterpFloat(CurveFloat, TimelineProgress);

	}
	
}

// Called every frame
void ADoorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//to Keep the time line ticking add in tick Function 

	Timeline.TickTimeline(DeltaTime); 

}
void ADoorActor:: OnInteract(AMyDoorGameCharacter* User)
{
	UE_LOG(LogTemp, Warning, TEXT("Press E"));

	if(bIsDoorClosed)
	{
		bDoorOnSameSide = IsDoorOnSameSide(User);
		Timeline.Play(); // Open the Door

	}
	else{
		Timeline.Reverse(); // Close the door 

	}
	bIsDoorClosed = !bIsDoorClosed; // Flip The Boolean 


}
void ADoorActor::OpenDoor(float Value)
{		// set the door on the same side and when isnt 
	float Angle = bDoorOnSameSide ?-DoorRotateAngle : DoorRotateAngle;
	FRotator Rot = FRotator(0.f,Angle * Value,0.f);

	Door->SetRelativeRotation(Rot);


}

bool ADoorActor::IsDoorOnSameSide(AActor* User) const
{
	if(User)
	{
		FVector CharacterFV = User->GetActorForwardVector();
		FVector DoorFV = GetActorForwardVector(); 
		return (FVector::DotProduct(CharacterFV,DoorFV)>= 0);
	}
	return false;
}

