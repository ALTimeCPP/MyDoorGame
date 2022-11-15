// Fill out your copyright notice in the Description page of Project Settings.


#include "MyItem2.h"
#include "MyDoorGameCharacter.h"

void AMyItem2::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
	 AActor* OtherActor, UPrimitiveComponent* OtherComp,
	 int32 otherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
 {

	UE_LOG(LogTemp, Warning, TEXT("On OverlapBegin"));

	AMyDoorGameCharacter* Character = Cast<AMyDoorGameCharacter>(OtherActor); 

	if(Character)
	{
 		Character -> KeyTwo = true;
		Destroy();
	}
	//Destroy();




}