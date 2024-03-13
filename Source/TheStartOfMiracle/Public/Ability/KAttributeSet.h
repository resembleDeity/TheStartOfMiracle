// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "KAttributeSet.generated.h"


struct FKAbilityActorInfo;
class UKAbilityComponent;



/**
 *  玩家角色 或 角色 的属性的描述结构. 
 * 用于储存 玩家角色 或 角色 的属性的 基础数值 和受 效果 等影响的 当前数值. 
 *  用于在 AttributeSet 中创建可以被 Attribute(FProperty) 访问的属性
 */
USTRUCT( BlueprintType )
struct THESTARTOFMIRACLE_API FKAttributeData
{
	GENERATED_BODY()

	FKAttributeData()
		: BaseValue(0.f)
		, CurrentValue(0.f)
	{ }

	FKAttributeData(float DefaultValue)
		: BaseValue(DefaultValue)
		, CurrentValue(DefaultValue)
	{ }

	virtual ~FKAttributeData()
	{ }

	float GetCurrentValue() const;

	virtual void SetCurrentValue(float NewValue);

	float GetBaseValue() const;

	virtual void SetBaseValue(float NewValue);
	
protected:
	UPROPERTY( BlueprintReadOnly, Category = "Attribute" )
	float BaseValue;

	UPROPERTY( BlueprintReadOnly, Category = "Attribute" )
	float CurrentValue;
};



/**
 *  AttributeData 或 float 属性的 描述/封装. 
 *  通过 UE的反射(UStruct 和 FField) 拓展 AttributeSet 以自定义属性 并 检查需要获取的属性是否继承自 AttributeData. 
 *  通过 反射获取 AttributeSet 的类的结构信息 返回与 AttributeName 对应的 属性. 
 */
USTRUCT( BlueprintType )
struct THESTARTOFMIRACLE_API FKAttribute
{
	GENERATED_BODY()

	FKAttribute()
		: Attribute(nullptr)
		, AttributeOwner(nullptr)
	{ }

	FKAttribute(FProperty* NewProperty);

	bool IsValid() const
	{
		return Attribute != nullptr;
	}

	void SetProperty(FProperty* NewProperty)
	{
		Attribute = NewProperty;
		if (NewProperty)
		{
			AttributeOwner = Attribute->GetOwnerStruct();
			Attribute->GetName(AttributeName);
		}
		else
		{
			AttributeOwner = nullptr;
			AttributeName.Empty();
		}
	}

	FProperty* GetProperty() const
	{
		return Attribute.Get();
	}

	static bool IsAttributeDataProperty(const FProperty* Property);


	bool operator==(const FKAttribute& Other) const;
	bool operator!=(const FKAttribute& Other) const;
	
	
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Attribute )
	FString AttributeName;
	
private:
	
	UPROPERTY( EditAnywhere, Category = Attribute )
	TFieldPath<FProperty> Attribute;

	UPROPERTY( EditAnywhere, Category = Attribute )
	TObjectPtr<UStruct> AttributeOwner;
};



UCLASS( DefaultToInstanced, Blueprintable )
class THESTARTOFMIRACLE_API UKAttributeSet : public UObject
{
	GENERATED_BODY()

public:
	
	virtual void PreAttributeChange(const FKAttribute& Attribute, float& NewValue) { }

	virtual void PostAttributeChange(const FKAttribute& Attribute, float OldValue, float NewValue) { }

	virtual void PreAttributeBaseChange(const FKAttribute& Attribute, float& NewValue) { }

	virtual void PostAttributeBaseChange(const FKAttribute& Attribute, float OldValue, float NewValue) { }

	AActor* GetOwningActor() const;
	UKAbilityComponent* GetOwningAbilityComponent() const;
	FKAbilityActorInfo* GetActorInfo() const;
};



USTRUCT( BlueprintType )
struct THESTARTOFMIRACLE_API FKAttributeMetaData : public FTableRowBase
{
	GENERATED_BODY()

public:

	FKAttributeMetaData();

	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = "Attribute")
	float BaseValue;

	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = "Attribute")
	float MinValue;

	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = "Attribute")
	float MaxValue;

	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = "Attribute")
	bool bCanStack;

};





#define ADD_ATTRIBUTE_PROPERTY(ClassName, PropertyType, PropertyName, ...) \
	UPROPERTY( __VA_ARGS__ ) \
	PropertyType PropertyName; \
	\
	\
	static FKAttribute Get##PropertyName##Attribute() \
	{ \
		static FProperty* Prop = FindFieldChecked<FProperty>(ClassName::StaticClass(), GET_MEMBER_NAME_CHECKED(ClassName, PropertyName)); \
		return Prop; \
	} \
	\
	\
	FORCEINLINE float Get##PropertyName() const \
	{ \
		return PropertyName.GetCurrentValue(); \
	} \
	\
	\
	FORCEINLINE void Set##PropertyName(float NewValue) \
	{ \
		UKAbilityComponent* AbilityComp = GetOwningAbilityComponent(); \
		if (ensure(AbilityComp)) \
		{ \
			AbilityComp->SetNumericAttributeBase(Get##PropertyName##Attribute(), NewValue); \
		} \
	} \
	\
	\
	FORCEINLINE void Init##PropertyName(float NewValue) \
	{ \
		PropertyName.SetBaseValue(NewValue); \
		PropertyName.SetCurrentValue(NewValue); \
	}