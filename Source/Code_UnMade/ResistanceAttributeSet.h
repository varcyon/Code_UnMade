// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/GSCAttributeSetBase.h"
#include "AbilitySystemComponent.h"
#include "ResistanceAttributeSet.generated.h"

UCLASS()
class CODE_UNMADE_API UResistanceAttributeSet : public UGSCAttributeSetBase
{
	GENERATED_BODY()

public:

	// Sets default values for this AttributeSet attributes
	UResistanceAttributeSet();

	// AttributeSet Overrides
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
		
	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Fire)
	FGameplayAttributeData Fire = 0.0;
	ATTRIBUTE_ACCESSORS(UResistanceAttributeSet, Fire)    
	
	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Ice)
	FGameplayAttributeData Ice = 0.0;
	ATTRIBUTE_ACCESSORS(UResistanceAttributeSet, Ice)    
	
	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Water)
	FGameplayAttributeData Water = 0.0;
	ATTRIBUTE_ACCESSORS(UResistanceAttributeSet, Water)    
	
	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Nature)
	FGameplayAttributeData Nature = 0.0;
	ATTRIBUTE_ACCESSORS(UResistanceAttributeSet, Nature)    

	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Electric)
	FGameplayAttributeData Electric = 0.0;
	ATTRIBUTE_ACCESSORS(UResistanceAttributeSet, Electric)
	
	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Shadow)
	FGameplayAttributeData Shadow = 0.0;
	ATTRIBUTE_ACCESSORS(UResistanceAttributeSet, Shadow)    
	
	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Light)
	FGameplayAttributeData Light = 0.0;
	ATTRIBUTE_ACCESSORS(UResistanceAttributeSet, Light)    
	
	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Slashing)
	FGameplayAttributeData Slashing = 0.0;
	ATTRIBUTE_ACCESSORS(UResistanceAttributeSet, Slashing)    
	
	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Piercing)
	FGameplayAttributeData Piercing = 0.0;
	ATTRIBUTE_ACCESSORS(UResistanceAttributeSet, Piercing)    
	
	UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Crushing)
	FGameplayAttributeData Crushing = 0.0;
	ATTRIBUTE_ACCESSORS(UResistanceAttributeSet, Crushing)    

		UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Physical)
		FGameplayAttributeData Physical = 0.0;
	ATTRIBUTE_ACCESSORS(UResistanceAttributeSet, Physical)

		UPROPERTY(BlueprintReadOnly, Category = "", ReplicatedUsing = OnRep_Magic)
		FGameplayAttributeData Magic = 0.0;
	ATTRIBUTE_ACCESSORS(UResistanceAttributeSet, Magic)

protected:
	
	UFUNCTION()
	virtual void OnRep_Fire(const FGameplayAttributeData& OldFire);

	UFUNCTION()
	virtual void OnRep_Ice(const FGameplayAttributeData& OldIce);

	UFUNCTION()
	virtual void OnRep_Water(const FGameplayAttributeData& OldWater);

	UFUNCTION()
	virtual void OnRep_Nature(const FGameplayAttributeData& OldNature);

	UFUNCTION()
		virtual void OnRep_Electric(const FGameplayAttributeData& OldElectric);

	UFUNCTION()
	virtual void OnRep_Shadow(const FGameplayAttributeData& OldShadow);

	UFUNCTION()
	virtual void OnRep_Light(const FGameplayAttributeData& OldLight);

	UFUNCTION()
	virtual void OnRep_Slashing(const FGameplayAttributeData& OldSlashing);

	UFUNCTION()
	virtual void OnRep_Piercing(const FGameplayAttributeData& OldPiercing);

	UFUNCTION()
	virtual void OnRep_Crushing(const FGameplayAttributeData& OldCrushing);
	
	UFUNCTION()
		virtual void OnRep_Physical(const FGameplayAttributeData& OldPhysical);

	UFUNCTION()
		virtual void OnRep_Magic(const FGameplayAttributeData& OldMagic);
};
