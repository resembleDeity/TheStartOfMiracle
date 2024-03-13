// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KInputAboutID.generated.h"

/**
 * 
 */
UENUM( BlueprintType )
enum EKInputMappingID : uint8
{
	MappingNone = 0,
	MoveInputMapping = 1,
};



/**
 * 
 */
UENUM( BlueprintType )
enum EKInputActionID : uint8
{
	ActionNone,
	MoveForwardAction = MoveInputMapping,
	MoveRightAction,
	TurnRightAction,
	LookUpAction,
};
