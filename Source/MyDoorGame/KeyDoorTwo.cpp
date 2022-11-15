// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyDoorTwo.h"

#include "MyDoorGameCharacter.h"

void AKeyDoorTwo::OnInteract()
{
    
    if(Character->KeyTwo)
    {

        Super:: OnInteract(); 
    
    }

}