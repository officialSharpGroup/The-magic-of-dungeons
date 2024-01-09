// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

class AMagicBall;


UCLASS()
class THEMAGICOFDUNGEONS_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	void UseMagic(FRotator CharacterTransform, FVector ForceDirectionWorldSpace);

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AMagicBall> MagicBallClass;

	UPROPERTY()
	AMagicBall* MagicBall;

	UPROPERTY()
	FVector ForceDirection = FVector(1000.0f, 0.0f, 0.0f); // Kierunek si³y

	UPROPERTY()
	float ForceStrength = 100.0f; // Si³a si³y
	
	UStaticMeshComponent* MeshMagicBall;

	FVector PointLightLocation;
};
