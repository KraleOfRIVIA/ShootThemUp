// Shoot Them Up Game, All Rights Reserved.


#include "Component/STUAIWeaponComponent.h"
#include "Weapon/STUBaseWeapon.h"
void USTUAIWeaponComponent::StartFire()
{
	if (!CanFire())
		return;
	if (CurrentWeapon->IsAmmoEmpty())
	{
		NextWeapon();
	}
	else
	{
		CurrentWeapon->StartFire();
	}
}

void USTUAIWeaponComponent::NextWeapon()
{
	if (!CanEquip()) return;
	int32 NextIndex = (CurrentWeapontIndex + 1) % Weapons.Num();
	while (NextIndex!=CurrentWeapontIndex)
	{
		if (!Weapons[NextIndex]->IsAmmoEmpty()) break;
		NextIndex = (NextIndex + 1) % Weapons.Num();
	}
	if (CurrentWeapontIndex != NextIndex)
	{
		CurrentWeapontIndex = NextIndex;
		EquipWeapon(CurrentWeapontIndex);
	}
}
