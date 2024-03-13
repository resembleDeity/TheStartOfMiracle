// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "ID/KInputAboutID.h"
#include "KInputMappingContextBase.generated.h"

/**
 * 
 */
UCLASS()
class THESTARTOFMIRACLE_API UKInputMappingContextBase : public UInputMappingContext
{
	GENERATED_BODY()

public:

	UPROPERTY( EditDefaultsOnly, BlueprintReadWrite )
	TMap<TEnumAsByte<EKInputActionID>, TObjectPtr<UInputAction>> InputActions;

	UPROPERTY( EditDefaultsOnly, BlueprintReadWrite )
	int32 Priority;
	
};
