// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KAbilityTypes.generated.h"



class AKPlayerController;
class UMovementComponent;
class UKAbilityComponent;



USTRUCT( BlueprintType )
struct THESTARTOFMIRACLE_API FKAbilityActorInfo
{
	GENERATED_BODY()

	virtual ~FKAbilityActorInfo() { }

	UPROPERTY( BlueprintReadOnly, Category = "ActorInfo" )
	TWeakObjectPtr<AActor> OwnerActor;

	UPROPERTY( BlueprintReadOnly, Category = "ActorInfo" )
	TWeakObjectPtr<AKPlayerController> PlayerController;

	UPROPERTY( BlueprintReadOnly, Category = "ActorInfo" )
	TWeakObjectPtr<UKAbilityComponent> AbilityComponent;

	UPROPERTY( BlueprintReadOnly, Category = "ActorInfo" )
	TWeakObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;

	UPROPERTY( BlueprintReadOnly, Category = "ActorInfo" )
	TWeakObjectPtr<UAnimBlueprint> AnimBlueprint;

	UPROPERTY( BlueprintReadOnly, Category = "ActorInfo" )
	TWeakObjectPtr<UAnimInstance> AnimInstance;

	UPROPERTY( BlueprintReadOnly, Category = "ActorInfo" )
	TWeakObjectPtr<UMovementComponent> MovementComponent;

	UAnimInstance* GetAnimInstance() const;

	virtual void InitFromActor(AActor* InOwnerActor, UKAbilityComponent* InAbilityComponent);

	virtual void ClearActorInfo();
};