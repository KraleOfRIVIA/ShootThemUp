// Shoot Them Up Game, All Rights Reserved.


#include "Pickups/STUAmmoPickup.h"
#include "Component/STUWeaponComponent.h"
#include "Component/STUHealthComponent.h"
#include "STUUtils.h"
DEFINE_LOG_CATEGORY_STATIC(LogAmmoPickup, All, All);

bool ASTUAmmoPickup::GivPickupTo(APawn *PlayerPawn)
{
	const auto HealthComponent = STUUtils::GetSTUPlayerComponent<USTUHealthComponent>(PlayerPawn);
	if (!HealthComponent || HealthComponent->IsDead()) return false;

	const auto WeaponComponent = STUUtils::GetSTUPlayerComponent<USTUWeaponComponent>(PlayerPawn);
	if (!WeaponComponent) return false;
	
	return WeaponComponent->TryToAddAmmo(WeaponType, ClipsAmount);
}
