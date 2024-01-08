// Fill out your copyright notice in the Description page of Project Settings.

#include "TriggerComponent.h"
#include "MovingDoor.h"

bool bTriggered = false; // Dodaj globaln¹ flagê

UTriggerComponent::UTriggerComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UTriggerComponent::SetDoor(AMovingDoor* NewMovingDoor)
{
    MovingDoor = NewMovingDoor;
}


void UTriggerComponent::BeginPlay()
{
    Super::BeginPlay();

}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

     if (MovingDoor == nullptr)
    {
         UE_LOG(LogTemp, Display, TEXT("nullptr"));

        return;
    }


    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);

    if (Actors.Num() > 0 && !bTriggered)
    {
        UE_LOG(LogTemp, Display, TEXT("JD"));
        MovingDoor->MoveDoor(DeltaTime);

        bTriggered = true;
    }
}


