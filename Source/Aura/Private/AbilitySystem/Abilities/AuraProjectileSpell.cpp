


#include "AbilitySystem/Abilities/AuraProjectileSpell.h"

#include "Actor/AuraProjectile.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "Interface/CombatInterface.h"

void UAuraProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
	
	const bool bIsServer = HasAuthority(&ActivationInfo);
	if (!bIsServer)
	{
		return;
	}
	
	ICombatInterface* CombatInterface = Cast<ICombatInterface>(GetAvatarActorFromActorInfo());
	if (CombatInterface)
	{
		const FVector SocketLocation = CombatInterface->GetCombatSockettLocation();
		FTransform SpawnTransform(SocketLocation);
		AActor* OwningActor = GetOwningActorFromActorInfo();
		AAuraProjectile* Projectile = GetWorld()->SpawnActorDeferred<AAuraProjectile>(ProjectileClass, SpawnTransform, OwningActor, Cast<APawn>(OwningActor), ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
		Projectile->FinishSpawning(SpawnTransform);
	}
}
