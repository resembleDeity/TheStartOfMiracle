// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/KPlayerController.h"

#include "Tools/KInputHelper.h"

#include "InputMappingContext.h"

#include "EnhancedInputSubsystems.h"
#include "GameFramework/Character.h"


// Sets default values
AKPlayerController::AKPlayerController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AKPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
}

void AKPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (InputMappings.IsEmpty())
	{
		return;
	}
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		for (const auto InputMapping : InputMappings)
		{
			Subsystem->AddMappingContext(Cast<UInputMappingContext>(InputMapping.Value), InputMapping.Value->Priority);
		}
	}
	
	UKInputHelper::BindTriggeredInput(InputComponent, InputMappings, MoveInputMapping, MoveForwardAction, this, &AKPlayerController::MoveForward);
	UKInputHelper::BindTriggeredInput(InputComponent, InputMappings, MoveInputMapping, MoveRightAction, this, &AKPlayerController::MoveRight);
	UKInputHelper::BindTriggeredInput(InputComponent, InputMappings, MoveInputMapping, TurnRightAction, this, &AKPlayerController::TurnRight);
	UKInputHelper::BindTriggeredInput(InputComponent, InputMappings, MoveInputMapping, LookUpAction, this, &AKPlayerController::LookUp);
}

// Called every frame
void AKPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AKPlayerController::MoveForward(const FInputActionValue& InputValue)
{
	if (InputValue.GetMagnitude() != 0.0f)
	{
		const FRotator YawRotation(0, ControlRotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		GetCharacter()->AddMovementInput(Direction, InputValue.GetMagnitude());
	}
}

void AKPlayerController::MoveRight(const FInputActionValue& InputValue)
{
	if (InputValue.GetMagnitude() != 0.0f)
	{
		const FRotator YawRotation(0, ControlRotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		GetCharacter()->AddMovementInput(Direction, InputValue.GetMagnitude());
	}
}

void AKPlayerController::TurnRight(const FInputActionValue& InputValue)
{
	AddYawInput(InputValue.GetMagnitude());
}

void AKPlayerController::LookUp(const FInputActionValue& InputValue)
{
	AddPitchInput(InputValue.GetMagnitude());
}

