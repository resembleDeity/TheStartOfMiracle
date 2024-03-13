// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KCharacterAttributeSet.h"
#include "KCharacterAbilityComponent.h"
#include "GameFramework/Character.h"
#include "KCharacterBase.generated.h"



UCLASS()
class THESTARTOFMIRACLE_API AKCharacterBase : public ACharacter
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	AKCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	UPROPERTY( EditAnywhere )
	int32 CharacterLevel;
	
	UPROPERTY()
	UKCharacterAbilityComponent* AbilityComponent;

	UPROPERTY()
	UKCharacterAttributeSet* AttributeSet;
	
};
