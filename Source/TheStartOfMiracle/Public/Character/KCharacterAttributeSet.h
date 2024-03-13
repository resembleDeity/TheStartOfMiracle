// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Ability/KAttributeSet.h"
#include "Ability/KAbilityComponent.h"
#include "KCharacterAttributeSet.generated.h"



class UKCharacterAttributeSet;
typedef UKCharacterAttributeSet UKTSOMAttributeSet;



/**
 * 
 */
UCLASS()
class THESTARTOFMIRACLE_API UKCharacterAttributeSet : public UKAttributeSet
{
	GENERATED_BODY()

public:

	virtual void PreAttributeChange(const FKAttribute& Attribute, float& NewValue) override;
	
	ADD_ATTRIBUTE_PROPERTY(UKTSOMAttributeSet, FKAttributeData, Hp)
	
	ADD_ATTRIBUTE_PROPERTY(UKTSOMAttributeSet, FKAttributeData, Atk)
	
	ADD_ATTRIBUTE_PROPERTY(UKTSOMAttributeSet, FKAttributeData, Def)
	
	ADD_ATTRIBUTE_PROPERTY(UKTSOMAttributeSet, FKAttributeData, Spd)
	
	ADD_ATTRIBUTE_PROPERTY(UKTSOMAttributeSet, FKAttributeData, CritChange)

	ADD_ATTRIBUTE_PROPERTY(UKTSOMAttributeSet, FKAttributeData, CritDamage)
	
};



using UKTSOMAttributeSet = UKCharacterAttributeSet ;
