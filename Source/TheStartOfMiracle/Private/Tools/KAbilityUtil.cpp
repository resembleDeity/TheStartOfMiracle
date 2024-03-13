// Fill out your copyright notice in the Description page of Project Settings.


#include "Tools/KAbilityUtil.h"

#include "Ability/KAbilityComponent.h"


UKAbilityComponent* UKAbilityUtil::GetAbilityComponentFromActor(const AActor* Actor, bool LookForComponent)
{
	if (Actor == nullptr)
	{
		return nullptr;
	}

	if (LookForComponent)
	{
		return Actor->FindComponentByClass<UKAbilityComponent>();
	}

	return nullptr;
}
