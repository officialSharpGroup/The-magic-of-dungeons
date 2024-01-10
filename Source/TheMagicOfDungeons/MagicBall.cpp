// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicBall.h"
#include "GameFramework/Actor.h"
#include "UObject/Object.h"

#include "HealthInterface.h"



// Sets default values
AMagicBall::AMagicBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;


	CollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionComponent"));



}

// Called when the game starts or when spawned
void AMagicBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMagicBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMagicBall::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
    Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

   
    Destroy();
}