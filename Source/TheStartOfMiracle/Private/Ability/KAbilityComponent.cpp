// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/KAbilityComponent.h"


UKAbilityComponent::UKAbilityComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	
}


void UKAbilityComponent::SetNumericAttributeBase(const FKAttribute& Attribute, float NewBaseValue)
{
}

float UKAbilityComponent::GetNumericAttributeBase(const FKAttribute& Attribute) const
{
	return 0.f;
}


void UKAbilityComponent::SetOwnerActor(AActor* NewOwnerActor)
{
	OwnerActor = NewOwnerActor;
}
