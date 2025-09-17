// Aura, Copyright 2025 – 2025, Juicy, Inc.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "AuraPlayerState.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;

DECLARE_MULTICAST_DELEGATE_OneParam(FOnPlayerStatChanged, int32 /*StatValue*/)


UCLASS()
class AURA_API AAuraPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAuraPlayerState();
	UAttributeSet* GetAttributeSet() const;
	int32 GetPlayerLevel() const;
	int32 GetXP() const;
	
	void AddToXP(int32 InXP);
	void AddToLevel(int32 InLevel);
	
	void SetXP(int32 InXP);
	void SetLevel(int32 InLevel);
	
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

public:
	FOnPlayerStatChanged OnXPChangedDelegate;
	FOnPlayerStatChanged OnLevelChangedDelegate;

private:
	UFUNCTION()
	void OnRep_Level(int32 OldLevel);

	UFUNCTION()
	void OnRep_XP(int32 OldXP);

protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

private:
	UPROPERTY(VisibleAnywhere, Replicated=OnRep_Level)
	int32 Level = 1;
	
	UPROPERTY(VisibleAnywhere, ReplicatedUsing=OnRep_XP)
	int32 XP = 1;
};
