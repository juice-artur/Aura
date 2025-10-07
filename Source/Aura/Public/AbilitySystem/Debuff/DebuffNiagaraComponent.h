// Aura, Copyright 2025 – 2025, Juicy, Inc.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "NiagaraComponent.h"
#include "DebuffNiagaraComponent.generated.h"


UCLASS()
class AURA_API UDebuffNiagaraComponent : public UNiagaraComponent
{
	GENERATED_BODY()

public:
	UDebuffNiagaraComponent();
	
public:
	UPROPERTY(VisibleAnywhere)
	FGameplayTag DebuffTag;

protected:
	virtual void BeginPlay() override;
	void DebuffTagChanged(const FGameplayTag CallbackTag, int32 NewCount);
};
