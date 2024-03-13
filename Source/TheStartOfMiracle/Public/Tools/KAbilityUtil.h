// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "KAbilityUtil.generated.h"

class UKAbilityComponent;
/**
 * 
 */
UCLASS()
class THESTARTOFMIRACLE_API UKAbilityUtil : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	static UKAbilityComponent* GetAbilityComponentFromActor(const AActor* Actor, bool LookForComponent = true);
	
};
