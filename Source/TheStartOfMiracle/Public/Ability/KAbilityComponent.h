// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KAbilityTypes.h"
#include "Components/ActorComponent.h"
#include "KAbilityComponent.generated.h"



struct FKAttribute;



UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class THESTARTOFMIRACLE_API UKAbilityComponent : public UActorComponent
{
	GENERATED_UCLASS_BODY()
	
	void SetNumericAttributeBase(const FKAttribute& Attribute, float NewBaseValue);

	float GetNumericAttributeBase(const FKAttribute &Attribute) const;

private:

	UPROPERTY()
	TObjectPtr<AActor> OwnerActor;
	
public:
	
	void SetOwnerActor(AActor* NewOwnerActor);
	AActor* GetOwnerActor() const { return OwnerActor; }
	
public:

	TSharedPtr<FKAbilityActorInfo> AbilityActorInfo;
	
};
