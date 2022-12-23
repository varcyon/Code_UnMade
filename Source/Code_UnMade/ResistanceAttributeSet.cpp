// Fill out your copyright notice in the Description page of Project Settings.


#include "ResistanceAttributeSet.h"

#include "Net/UnrealNetwork.h"

// Sets default values
UResistanceAttributeSet::UResistanceAttributeSet()
{
	// Default constructor
}

void UResistanceAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
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

void UResistanceAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
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

void UResistanceAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
		
	DOREPLIFETIME_CONDITION_NOTIFY(UResistanceAttributeSet, Fire, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UResistanceAttributeSet, Ice, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UResistanceAttributeSet, Water, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UResistanceAttributeSet, Nature, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UResistanceAttributeSet, Shadow, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UResistanceAttributeSet, Light, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UResistanceAttributeSet, Slashing, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UResistanceAttributeSet, Piercing, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UResistanceAttributeSet, Crushing, COND_None, REPNOTIFY_Always);
}

void UResistanceAttributeSet::OnRep_Fire(const FGameplayAttributeData& OldFire)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UResistanceAttributeSet, Fire, OldFire);
}

void UResistanceAttributeSet::OnRep_Ice(const FGameplayAttributeData& OldIce)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UResistanceAttributeSet, Ice, OldIce);
}

void UResistanceAttributeSet::OnRep_Water(const FGameplayAttributeData& OldWater)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UResistanceAttributeSet, Water, OldWater);
}

void UResistanceAttributeSet::OnRep_Nature(const FGameplayAttributeData& OldNature)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UResistanceAttributeSet, Nature, OldNature);
}

void UResistanceAttributeSet::OnRep_Shadow(const FGameplayAttributeData& OldShadow)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UResistanceAttributeSet, Shadow, OldShadow);
}

void UResistanceAttributeSet::OnRep_Light(const FGameplayAttributeData& OldLight)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UResistanceAttributeSet, Light, OldLight);
}

void UResistanceAttributeSet::OnRep_Slashing(const FGameplayAttributeData& OldSlashing)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UResistanceAttributeSet, Slashing, OldSlashing);
}

void UResistanceAttributeSet::OnRep_Piercing(const FGameplayAttributeData& OldPiercing)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UResistanceAttributeSet, Piercing, OldPiercing);
}

void UResistanceAttributeSet::OnRep_Crushing(const FGameplayAttributeData& OldCrushing)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UResistanceAttributeSet, Crushing, OldCrushing);
}
