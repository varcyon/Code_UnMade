// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "SurvivalAttributeSet.generated.h"

UCLASS()
class CODE_UNMADE_API USurvivalAttributeSet : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	USurvivalAttributeSet();

	// AttributeSet Overrides
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
		
	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Essence)
	FGameplayAttributeData Essence = 100.0;
	ATTRIBUTE_ACCESSORS(USurvivalAttributeSet, Essence)    
	
	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Hungry)
	FGameplayAttributeData Hungry = 100.0;
	ATTRIBUTE_ACCESSORS(USurvivalAttributeSet, Hungry)    
	
	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Thirst)
	FGameplayAttributeData Thirst = 100.0;
	ATTRIBUTE_ACCESSORS(USurvivalAttributeSet, Thirst)    
		UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Essence)
		FGameplayAttributeData MaxEssence = 100.0;
	ATTRIBUTE_ACCESSORS(USurvivalAttributeSet, MaxEssence)

		UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Hungry)
		FGameplayAttributeData MaxHungry = 100.0;
	ATTRIBUTE_ACCESSORS(USurvivalAttributeSet, MaxHungry)

		UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Thirst)
		FGameplayAttributeData MaxThirst = 100.0;
	ATTRIBUTE_ACCESSORS(USurvivalAttributeSet, MaxThirst)
protected:
	
	UFUNCTION()
	virtual void OnRep_Essence(const FGameplayAttributeData& OldEssence);

	UFUNCTION()
	virtual void OnRep_Hungry(const FGameplayAttributeData& OldHungry);

	UFUNCTION()
	virtual void OnRep_Thirst(const FGameplayAttributeData& OldThirst);
	
	UFUNCTION()
		virtual void OnRep_MaxEssence(const FGameplayAttributeData& OldMaxEssence);

	UFUNCTION()
		virtual void OnRep_MaxHungry(const FGameplayAttributeData& OldMaxHungry);

	UFUNCTION()
		virtual void OnRep_MaxThirst(const FGameplayAttributeData& OldMaxThirst);
};
