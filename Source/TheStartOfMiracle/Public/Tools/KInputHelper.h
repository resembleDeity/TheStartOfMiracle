// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ID/KInputAboutID.h"
#include "EnhancedInputComponent.h"
#include "Input/KInputMappingContextBase.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "KInputHelper.generated.h"


class AKPlayerController;
/**
 * 
 */
UCLASS()
class THESTARTOFMIRACLE_API UKInputHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	typedef TMap<TEnumAsByte<EKInputMappingID>, UKInputMappingContextBase*> FInputMappings;
	
public:
	
	static TObjectPtr<UInputAction> GetInputAction
	(
		FInputMappings& InputMapping,
		EKInputMappingID InputMappingID, EKInputActionID InputActionID
	);
	
	template<typename UserClass, typename... VarTypes>
	static void BindTriggeredInput
	(
		TObjectPtr<UInputComponent> InputComponent,
		TObjectPtr<UInputAction> InputAction,
		UserClass* Object, void(UserClass::*Func)(VarTypes...)
	);

	template<typename UserClass, typename... VarTypes>
	static void BindTriggeredInput
	(
		TObjectPtr<UInputComponent> InputComponent,
		FInputMappings& InputMapping, EKInputMappingID InputMappingID, EKInputActionID InputActionID,
		UserClass* Object, void(UserClass::*Func)(VarTypes...)
	);
	
};



template <typename UserClass, typename... VarTypes>
void UKInputHelper::BindTriggeredInput(TObjectPtr<UInputComponent> InputComponent, TObjectPtr<UInputAction> InputAction,
	UserClass* Object, void(UserClass::*Func)(VarTypes...))
{
	if (InputAction && InputComponent)
	{
		UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
		EnhancedInputComponent->BindAction(InputAction, ETriggerEvent::Triggered, Object, Func);
	}
}

template <typename UserClass, typename ... VarTypes>
void UKInputHelper::BindTriggeredInput(TObjectPtr<UInputComponent> InputComponent, FInputMappings& InputMapping,
	EKInputMappingID InputMappingID, EKInputActionID InputActionID, UserClass* Object,
	void(UserClass::* Func)(VarTypes...))
{
	BindTriggeredInput(InputComponent, GetInputAction(InputMapping, InputMappingID, InputActionID), Object, Func);
}
