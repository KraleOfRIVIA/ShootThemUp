// Shoot Them Up Game, All Rights Reserved.


#include "Pickups/STUHealthPickup.h"
#include "Component/STUWeaponComponent.h"
#include "Component/STUHealthComponent.h"
#include "STUUtils.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthPickup, All, All);

bool ASTUHealthPickup::GivPickupTo(APawn *PlayerPawn)
{
	const auto HealthComponent = STUUtils::GetSTUPlayerComponent<USTUHealthComponent>(PlayerPawn);
	if (!HealthComponent) return false;
	return HealthComponent->TryToHeal(HealthAmount);
}
