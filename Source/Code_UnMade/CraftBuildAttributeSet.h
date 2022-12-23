// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "CraftBuildAttributeSet.generated.h"

UCLASS()
class CODE_UNMADE_API UCraftBuildAttributeSet : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UCraftBuildAttributeSet();

	// AttributeSet Overrides
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
		
	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Essence)
	FGameplayAttributeData Essence = 100.0;
	ATTRIBUTE_ACCESSORS(UCraftBuildAttributeSet, Essence)    
	
	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Lifeforce)
	FGameplayAttributeData Lifeforce = 100.0;
	ATTRIBUTE_ACCESSORS(UCraftBuildAttributeSet, Lifeforce)
	
   

		UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_MaxEssence)
		FGameplayAttributeData MaxEssence = 100.0;
	ATTRIBUTE_ACCESSORS(UCraftBuildAttributeSet, MaxEssence)

		UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_MaxLifeforce)
		FGameplayAttributeData MaxLifeforce = 100.0;
	ATTRIBUTE_ACCESSORS(UCraftBuildAttributeSet, MaxLifeforce)


protected:
	
	UFUNCTION()
	virtual void OnRep_Essence(const FGameplayAttributeData& OldEssence);

	UFUNCTION()
	virtual void OnRep_Lifeforce(const FGameplayAttributeData& OldLifeforce);

	
	UFUNCTION()
		virtual void OnRep_MaxEssence(const FGameplayAttributeData& OldMaxEssence);

	UFUNCTION()
		virtual void OnRep_MaxLifeforce(const FGameplayAttributeData& OldMaxLifeforce);

};
