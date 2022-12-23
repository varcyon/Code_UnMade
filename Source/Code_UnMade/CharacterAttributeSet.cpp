// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAttributeSet.h"

#include "Net/UnrealNetwork.h"

// Sets default values
UCharacterAttributeSet::UCharacterAttributeSet()
{
	// Default constructor
}

void UCharacterAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
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

void UCharacterAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
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

void UCharacterAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
		
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, Strength, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, Intelligence, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, Constitution, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, Dexterity, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, Spirit, COND_None, REPNOTIFY_Always);
	
	DOREPLIFETIME_CONDITION_NOTIFY(UCharacterAttributeSet, Speed, COND_None, REPNOTIFY_Always);
}

void UCharacterAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldStrength)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, Strength, OldStrength);
}

void UCharacterAttributeSet::OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, Intelligence, OldIntelligence);
}

void UCharacterAttributeSet::OnRep_Constitution(const FGameplayAttributeData& OldConstitution)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, Constitution, OldConstitution);
}

void UCharacterAttributeSet::OnRep_Dexterity(const FGameplayAttributeData& OldDexterity)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, Dexterity, OldDexterity);
}

void UCharacterAttributeSet::OnRep_Spirit(const FGameplayAttributeData& OldSpirit)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, Spirit, OldSpirit);
}

void UCharacterAttributeSet::OnRep_Speed(const FGameplayAttributeData& OldSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UCharacterAttributeSet, Speed, OldSpeed);
}
