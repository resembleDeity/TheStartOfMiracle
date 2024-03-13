// Fill out your copyright notice in the Description page of Project Settings.


#include "Tools/KInputHelper.h"
#include "Input/KInputMappingContextBase.h"
#include "EnhancedInputComponent.h"

TObjectPtr<UInputAction> UKInputHelper::GetInputAction(
	FInputMappings& InputMapping, EKInputMappingID InputMappingID, EKInputActionID InputActionID)
{
	return InputMapping[InputMappingID]->InputActions[InputActionID];
}
