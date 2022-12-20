// Fill out your copyright notice in the Description page of Project Settings.


#include "SurvivalAttributeSet.h"

#include "Net/UnrealNetwork.h"

// Sets default values
USurvivalAttributeSet::USurvivalAttributeSet()
{
	// Default constructor
}

void USurvivalAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
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

void USurvivalAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
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

void USurvivalAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
		
	DOREPLIFETIME_CONDITION_NOTIFY(USurvivalAttributeSet, Essence, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(USurvivalAttributeSet, Hungry, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(USurvivalAttributeSet, Thirst, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(USurvivalAttributeSet, MaxEssence, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(USurvivalAttributeSet, MaxHungry, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(USurvivalAttributeSet, MaxThirst, COND_None, REPNOTIFY_Always);
}

void USurvivalAttributeSet::OnRep_Essence(const FGameplayAttributeData& OldEssence)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USurvivalAttributeSet, Essence, OldEssence);
}

void USurvivalAttributeSet::OnRep_Hungry(const FGameplayAttributeData& OldHungry)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USurvivalAttributeSet, Hungry, OldHungry);
}

void USurvivalAttributeSet::OnRep_Thirst(const FGameplayAttributeData& OldThirst)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USurvivalAttributeSet, Thirst, OldThirst);

}
void USurvivalAttributeSet::OnRep_MaxEssence(const FGameplayAttributeData& OldMaxEssence)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USurvivalAttributeSet, MaxEssence, OldMaxEssence);
}

void USurvivalAttributeSet::OnRep_MaxHungry(const FGameplayAttributeData& OldMaxHungry)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USurvivalAttributeSet, MaxHungry, OldMaxHungry);
}

void USurvivalAttributeSet::OnRep_MaxThirst(const FGameplayAttributeData& OldMaxThirst)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(USurvivalAttributeSet, MaxThirst, OldMaxThirst);
}
