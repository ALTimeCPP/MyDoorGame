// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyDoorTwo.h"

#include "MyDoorGameCharacter.h"

void AKeyDoorTwo::OnInteract(AMyDoorGameCharacter* User)
{
    
    if(User != nullptr && User->KeyTwo)
    {
        // Super inhrit all the function from the parent classes
        Super:: OnInteract(User);
    
    }

}