// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyDoor.h"
#include "MyDoorGameCharacter.h"

void AKeyDoor::OnInteract()
{
    
    if(Character->KeyOne)
    {

        Super:: OnInteract(); 
    
    }

}