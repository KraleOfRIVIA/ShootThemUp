// Shoot Them Up Game, All Rights Reserved.
#include "UI/STUSpectatorWidget.h"
#include "STUUtils.h"
#include "Component/STURespawnComponent.h"
bool USTUSpectatorWidget::GetRespawnTimer(int32 &CountDown) const
{
	const auto RespawnComponent = STUUtils::GetSTUPlayerComponent<USTURespawnComponent>(GetOwningPlayer());
	if (!RespawnComponent || !RespawnComponent->IsRespawning())
		return false;
	CountDown = RespawnComponent->GetRespawnCountDown();
	return true;
}
