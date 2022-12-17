// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "ExperienceAttributeSet.generated.h"

UCLASS()
class CODE_UNMADE_API UExperienceAttributeSet : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UExperienceAttributeSet();

	// AttributeSet Overrides
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
		
	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_CurrentExp)
	FGameplayAttributeData CurrentExp = 0.0;
	ATTRIBUTE_ACCESSORS(UExperienceAttributeSet, CurrentExp)    
	
	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_NeededExp)
	FGameplayAttributeData NeededExp = 100.0;
	ATTRIBUTE_ACCESSORS(UExperienceAttributeSet, NeededExp)    

	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Level)
	FGameplayAttributeData Level = 1;
	ATTRIBUTE_ACCESSORS(UExperienceAttributeSet, Level)

protected:
	
	UFUNCTION()
	virtual void OnRep_CurrentExp(const FGameplayAttributeData& OldCurrentExp);

	UFUNCTION()
	virtual void OnRep_NeededExp(const FGameplayAttributeData& OldNeededExp);
	
	UFUNCTION()
	virtual void OnRep_Level(const FGameplayAttributeData& OldLevel);

};
