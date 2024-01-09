// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "MagicBall.h"


// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

	MeshMagicBall = nullptr; // Inicjalizuj MeshMagicBall na nullptr, aby unikn¹æ b³êdów

	
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGun::UseMagic(FRotator CharacterTransform, FVector ForceDirectionWorldSpace)
{

	UE_LOG(LogTemp, Warning, TEXT("You've been shoot!"));
	MagicBall = GetWorld()->SpawnActor<AMagicBall>(MagicBallClass, GetActorLocation() , CharacterTransform);
	if (MagicBall)
	{

		MeshMagicBall = MagicBall->Mesh;
		MeshMagicBall->AddForce(ForceDirectionWorldSpace * ForceStrength);
	}
	
	
}
