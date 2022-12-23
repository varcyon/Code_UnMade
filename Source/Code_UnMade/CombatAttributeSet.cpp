// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatAttributeSet.h"

#include "Net/UnrealNetwork.h"

// Sets default values
UCombatAttributeSet::UCombatAttributeSet()
{
	// Default constructor
}

void UCombatAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
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

void UCombatAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
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

void UCombatAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
		
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, Power, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, Defense, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, CritChance, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UCombatAttributeSet, CritPower, COND_None, REPNOTIFY_Always);
}

void UCombatAttributeSet::OnRep_Power(const FGameplayAttributeData& OldPower)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCombatAttributeSet, Power, OldPower);
}

void UCombatAttributeSet::OnRep_Defense(const FGameplayAttributeData& OldDefense)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCombatAttributeSet, Defense, OldDefense);
}

void UCombatAttributeSet::OnRep_CritChance(const FGameplayAttributeData& OldCritChance)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCombatAttributeSet, CritChance, OldCritChance);
}

void UCombatAttributeSet::OnRep_CritPower(const FGameplayAttributeData& OldCritPower)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCombatAttributeSet, CritPower, OldCritPower);
}
