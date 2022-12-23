// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "CharacterAttributeSet.generated.h"

UCLASS()
class CODE_UNMADE_API UCharacterAttributeSet : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UCharacterAttributeSet();

	// AttributeSet Overrides
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
		
	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Strength)
	FGameplayAttributeData Strength = 5.0;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, Strength)    
	
	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Intelligence)
	FGameplayAttributeData Intelligence = 5.0;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, Intelligence)    
	
	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Constitution)
	FGameplayAttributeData Constitution = 5.0;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, Constitution)    
	
	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Dexterity)
	FGameplayAttributeData Dexterity = 5.0;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, Dexterity)    
	
	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Spirit)
	FGameplayAttributeData Spirit = 5.0;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, Spirit)    
	
	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Speed)
	FGameplayAttributeData Speed = -4.0;
	ATTRIBUTE_ACCESSORS(UCharacterAttributeSet, Speed)    

protected:
	
	UFUNCTION()
	virtual void OnRep_Strength(const FGameplayAttributeData& OldStrength);

	UFUNCTION()
	virtual void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence);

	UFUNCTION()
	virtual void OnRep_Constitution(const FGameplayAttributeData& OldConstitution);

	UFUNCTION()
	virtual void OnRep_Dexterity(const FGameplayAttributeData& OldDexterity);

	UFUNCTION()
	virtual void OnRep_Spirit(const FGameplayAttributeData& OldSpirit);

	UFUNCTION()
	virtual void OnRep_Speed(const FGameplayAttributeData& OldSpeed);
	
	
};
