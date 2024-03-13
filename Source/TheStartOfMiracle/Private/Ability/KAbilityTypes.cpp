// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/KAbilityTypes.h"

#include "Ability/KAbilityComponent.h"
#include "Character/KCharacterBase.h"
#include "GameFramework/MovementComponent.h"
#include "Player/KPlayerController.h"


void FKAbilityActorInfo::InitFromActor(AActor* InOwnerActor, UKAbilityComponent* InAbilityComponent)
{
	OwnerActor = InOwnerActor;
	AbilityComponent = InAbilityComponent;

	AKPlayerController* OldPC = PlayerController.Get();

	AActor* TestActor = InOwnerActor;
	while (TestActor)
	{
		if (AKPlayerController* CastPC = Cast<AKPlayerController>(TestActor))
		{
			PlayerController = CastPC;
			break;
		}

		if (AKCharacterBase* Character = Cast<AKCharacterBase>(TestActor))
		{
			PlayerController = Cast<AKPlayerController>(Character->GetController());
			break;
		}

		TestActor = TestActor->GetOwner();
	}

	SkeletalMeshComponent = InOwnerActor->FindComponentByClass<USkeletalMeshComponent>();
	MovementComponent = InOwnerActor->FindComponentByClass<UMovementComponent>();
}

void FKAbilityActorInfo::ClearActorInfo()
{
	OwnerActor = nullptr;
	PlayerController = nullptr;
	SkeletalMeshComponent = nullptr;
	MovementComponent = nullptr;
}

UAnimInstance* FKAbilityActorInfo::GetAnimInstance() const
{
	const USkeletalMeshComponent* SKMC = SkeletalMeshComponent.Get();

	if (SKMC)
	{
		return SKMC->GetAnimInstance();
	}

	return nullptr;
}

