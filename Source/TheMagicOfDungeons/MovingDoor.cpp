// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingDoor.h"

// Sets default values
AMovingDoor::AMovingDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);
}

void AMovingDoor::MoveDoor(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector CurrentLocation = GetActorLocation();

	CurrentLocation = CurrentLocation + DoorVelocity * DeltaTime;

	SetActorLocation(CurrentLocation);

}

// Called when the game starts or when spawned
void AMovingDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

