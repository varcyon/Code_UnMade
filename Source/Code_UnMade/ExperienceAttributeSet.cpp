// Fill out your copyright notice in the Description page of Project Settings.


#include "ExperienceAttributeSet.h"

#include "Net/UnrealNetwork.h"

// Sets default values
UExperienceAttributeSet::UExperienceAttributeSet()
{
	// Default constructor
}

void UExperienceAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	// This is called whenever attributes change, so for max attributes we want to scale the current totals to match
	Super::PreAttributeChange(Attribute, NewValue);

	// Set adjust code here
	//
	// Example:
	//
	// If a Max value changes, adjust current to keep Current % of Current to Max
	//
	// if (Attribute == GetMaxHealthAttribute())
	// {
	//     AdjustAttributeForMaxChange(Health, MaxHealth, NewValue, GetHealthAttribute());
	// }
}

void UExperienceAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FGSCAttributeSetExecutionData ExecutionData;
	GetExecutionDataFromMod(Data, ExecutionData);

	// Set clamping or handling or "meta" attributes here (like damages)

	// Example 1: Using helpers to handle each attribute in their own methods (See GSCAttributeSet.cpp)

	// if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	// {
	//     HandleHealthAttribute(ExecutionData);
	// }

	// Example 2: Basic example to clamp the value of an Health Attribute between 0 and another MaxHealth Attribute

	// if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	// {
	//     SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
	// }
}

void UExperienceAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
		
	DOREPLIFETIME_CONDITION_NOTIFY(UExperienceAttributeSet, CurrentExp, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UExperienceAttributeSet, NeededExp, COND_None, REPNOTIFY_Always);
}

void UExperienceAttributeSet::OnRep_CurrentExp(const FGameplayAttributeData& OldCurrentExp)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UExperienceAttributeSet, CurrentExp, OldCurrentExp);
}

void UExperienceAttributeSet::OnRep_NeededExp(const FGameplayAttributeData& OldNeededExp)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UExperienceAttributeSet, NeededExp, OldNeededExp);
}
