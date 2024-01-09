// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FPS_Character.generated.h"

class AGun;

UCLASS()
class THEMAGICOFDUNGEONS_API AFPS_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPS_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintPure)
	float GetManaPercent();

	UFUNCTION(BlueprintPure)
	float GetHealthPercent();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mana")
	float MaxMana = 100;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mana")
	float Mana;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Health")
	float MaxHealth = 100;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Health")
	float Health;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mana")
	float ManaRegenerationRate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Mana")
	float ManaRegenerationDelay;

	

private:
	void MoveForawrd(float AxisValue);

	void MoveRigth(float AxisValue);

	UFUNCTION(BlueprintCallable, Category = "Stamina")
	void RegenerateMana();

	UFUNCTION(BlueprintCallable, Category = "Stamina")
	void Shoot();

	FTimerHandle StaminaRegenerationTimer;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGun> GunClass;

	UPROPERTY()
	AGun* Gun;


	
};
