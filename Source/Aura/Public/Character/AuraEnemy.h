

#pragma once

#include "CoreMinimal.h"
#include "Character/BaseCharacter.h"
#include "Interface/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public ABaseCharacter, public IEnemyInterface
{
	GENERATED_BODY()
	
public:
	AAuraEnemy();
	
	// <Enemy Interface>
	virtual void BeginPlay() override;
	virtual void SetActorHighlight(bool IsHighlight) override;
	// </Enemy Interface>
	
	// <Combat Interface>
	virtual int32 GetLevel() override;
	// </Combat Interface>
	
protected:
	virtual void InitAbilityActorInfo() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Character Class Defaults")
	int32 Level = 1;
};
