// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "CombatAttributeSet.generated.h"

UCLASS()
class CODE_UNMADE_API UCombatAttributeSet : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UCombatAttributeSet();

    // AttributeSet Overrides
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
        
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Power)
    FGameplayAttributeData Power = 10.0;
    ATTRIBUTE_ACCESSORS(UCombatAttributeSet, Power)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Defense)
    FGameplayAttributeData Defense = 10.0;
    ATTRIBUTE_ACCESSORS(UCombatAttributeSet, Defense)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_CritChance)
    FGameplayAttributeData CritChance = 10.0;
    ATTRIBUTE_ACCESSORS(UCombatAttributeSet, CritChance)    
    
    UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_CritPower)
    FGameplayAttributeData CritPower = 10.0;
    ATTRIBUTE_ACCESSORS(UCombatAttributeSet, CritPower)    

protected:
    
    UFUNCTION()
    virtual void OnRep_Power(const FGameplayAttributeData& OldPower);

    UFUNCTION()
    virtual void OnRep_Defense(const FGameplayAttributeData& OldDefense);

    UFUNCTION()
    virtual void OnRep_CritChance(const FGameplayAttributeData& OldCritChance);

    UFUNCTION()
    virtual void OnRep_CritPower(const FGameplayAttributeData& OldCritPower);
	
	
};
