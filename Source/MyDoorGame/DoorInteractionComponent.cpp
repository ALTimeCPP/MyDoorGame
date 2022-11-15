// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorInteractionComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/TriggerBox.h" 
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Sound\SoundCue.h"
#include "MyDoorGameCharacter.h"


// Sets default values for this component's properties
UDoorInteractionComponent::UDoorInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	StartRotation = GetOwner()->GetActorRotation(); // Desired rotation - Our Current Rotation assume our current location is zero same as our delta rotation.
	FinalRotation = GetOwner()->GetActorRotation() + DesiredRotation;// CURRENT ROTATION WHICH ASSUEM IS ZERO + 90 DEGREE (OUR CURRENT LOCATION) 
	CurrentRotationTime = 0.0f;
	ACharacter =Cast<AMyDoorGameCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
	
}


// Called every frame
void UDoorInteractionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	



	if (CurrentRotationTime < TimeToRotate) // First check  the Rotation then we dont need to do any of this 
	{	
		// Check if the Trigger Box is valid and Get world ( we set this up so that work only on Local player
		if (TriggerBox && GetWorld() && GetWorld()->GetFirstLocalPlayerFromController())
		{
			// We check the player Pawn 
			
			// And we check if the player pawn is indeed inside the box

			if ( ACharacter && TriggerBox->IsOverlappingActor(ACharacter))
			{ // Then we apply the logic which we have done it previous. 
				CurrentRotationTime += DeltaTime;
				// We will be useing Time ratio which we were useing as time Alpha
				const float TimeRatio = FMath::Clamp(CurrentRotationTime / TimeToRotate, 0.0f, 1.0f);
				// We will use this to get value from the curve
				const float RotationAlpha = OpenCurve.GetRichCurveConst()->Eval(TimeRatio);
				const FRotator CurrentRotation = FMath::Lerp(StartRotation, FinalRotation, RotationAlpha);

				GetOwner()->SetActorRotation(CurrentRotation);
				//UGameplayStatics::PlaySoundAtLocation(this, DoorSound, GetActorLocation());
				UE_LOG(LogTemp, Warning, TEXT("wARNING"));
			}
			else if(ACharacter && GetOwner()->GetActorRotation() != StartRotation )
			{
					CurrentRotationTime += DeltaTime;
				// We will be useing Time ratio which we were useing as time Alpha
				const float TimeRatio = FMath::Clamp(CurrentRotationTime / TimeToRotate, 0.0f, 1.0f);
				// We will use this to get value from the curve
				const float RotationAlpha = OpenCurve.GetRichCurveConst()->Eval(TimeRatio);
				const FRotator CurrentRotation = FMath::Lerp(StartRotation, FinalRotation, RotationAlpha);

				GetOwner()->SetActorRotation(CurrentRotation);


			}
		}
	}
}

