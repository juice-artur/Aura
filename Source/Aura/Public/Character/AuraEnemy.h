// Aura, Copyright 2025 – 2025, Juicy, Inc.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"


UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
	
public:
	AAuraEnemy();

	//~ Begin Enemy Interface
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	//~ End Enemy Interface end

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
};
