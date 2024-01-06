// Fill out your copyright notice in the Description page of Project Settings.


#include "FPS_Character.h"
#include "Gun.h"




// Sets default values
AFPS_Character::AFPS_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFPS_Character::BeginPlay()
{
	Super::BeginPlay();
	
	Gun = GetWorld()->SpawnActor<AGun>(GunClass);
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("hand_r_wepon_Socket"));
	Gun->SetOwner(this);
}

// Called every frame
void AFPS_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPS_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AFPS_Character::MoveForawrd);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("MoveRigth"), this, &AFPS_Character::MoveRigth);
	PlayerInputComponent->BindAxis(TEXT("LookRigth"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed,this, &ACharacter::Jump);

}

void AFPS_Character::MoveForawrd(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AFPS_Character::MoveRigth(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}



