// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "MovingDoor.h"
#include "TriggerComponent.generated.h"

/**
 * 
 */


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class THEMAGICOFDUNGEONS_API UTriggerComponent : public UBoxComponent
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


public:
	UTriggerComponent();

	UFUNCTION(BlueprintCallable)
	void SetDoor(AMovingDoor* MovingDoor);


public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AMovingDoor> Door;

	UPROPERTY()
	AMovingDoor* MovingDoor;

	bool bTriggered;

};
