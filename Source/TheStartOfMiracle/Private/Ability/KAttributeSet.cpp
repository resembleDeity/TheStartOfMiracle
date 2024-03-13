// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/KAttributeSet.h"

#include "Ability/KAbilityComponent.h"
#include "Tools/KAbilityUtil.h"


float FKAttributeData::GetCurrentValue() const
{
	return CurrentValue;
}

void FKAttributeData::SetCurrentValue(float NewValue)
{
	CurrentValue = NewValue;
}

float FKAttributeData::GetBaseValue() const
{
	return BaseValue;
}

void FKAttributeData::SetBaseValue(float NewValue)
{
	BaseValue = NewValue;
}





FKAttribute::FKAttribute(FProperty* NewProperty)
{
	Attribute = CastField<FNumericProperty>(NewProperty);
	AttributeOwner = nullptr;

	if (Attribute.Get())
	{
		if (IsAttributeDataProperty(NewProperty))
		{
			Attribute = NewProperty;
		}
	}

	if (Attribute.Get())
	{
		AttributeOwner = Attribute->GetOwnerStruct();
		Attribute->GetName(AttributeName);
	}
}

bool FKAttribute::IsAttributeDataProperty(const FProperty* Property)
{
	const FStructProperty* StructProp = CastField<FStructProperty>(Property);
	if (StructProp)
	{
		const UStruct* Struct = StructProp->Struct;
		if (Struct && Struct->IsChildOf(FKAttributeData::StaticStruct()))
		{
			return true;
		}
	}

	return false;
}





AActor* UKAttributeSet::GetOwningActor() const
{
	return CastChecked<AActor>(GetOuter());
}

UKAbilityComponent* UKAttributeSet::GetOwningAbilityComponent() const
{
	return UKAbilityUtil::GetAbilityComponentFromActor(GetOwningActor());
}

FKAbilityActorInfo* UKAttributeSet::GetActorInfo() const
{
	UKAbilityComponent* AC = GetOwningAbilityComponent();
	if (AC)
	{
		return AC->AbilityActorInfo.Get();
	}

	return nullptr;
}





FKAttributeMetaData::FKAttributeMetaData()
	: BaseValue(0.0f)
	, MinValue(0.f)
	, MaxValue(1.f)
	, bCanStack(false)
{
}





bool FKAttribute::operator==(const FKAttribute& Other) const
{
	return Other.Attribute == Attribute;
}
bool FKAttribute::operator!=(const FKAttribute& Other) const
{
	return Other.Attribute != Attribute;
}