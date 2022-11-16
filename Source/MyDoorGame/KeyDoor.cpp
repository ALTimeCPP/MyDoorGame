// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyDoor.h"
#include "MyDoorGameCharacter.h"

void AKeyDoor::OnInteract(AMyDoorGameCharacter* User)
{
    // How will you rethink this so you don't have to make n class of door class for n keys?
    if(User != nullptr && User->KeyOne)
    {
        // Remember Super inhrit all the function from the parent classes
        Super:: OnInteract(User);
    
    }

}