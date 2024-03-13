// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "ID/KInputAboutID.h"
#include "GameFramework/PlayerController.h"
#include "KPlayerController.generated.h"

struct FInputActionValue;
class UKInputMappingContextBase;

UCLASS()
class THESTARTOFMIRACLE_API AKPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AKPlayerController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	
	void MoveForward(const FInputActionValue& InputValue);

	void MoveRight(const FInputActionValue& InputValue);

	void TurnRight(const FInputActionValue& InputValue);

	void LookUp(const FInputActionValue& InputValue);
	
protected:

	UPROPERTY( EditDefaultsOnly, BlueprintReadWrite )
	TMap<TEnumAsByte<EKInputMappingID>, UKInputMappingContextBase*> InputMappings;
	
};
