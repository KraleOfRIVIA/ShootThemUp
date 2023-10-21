// Shoot Them Up Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "STUPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API ASTUPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	void SetTeamID(int32 ID){TeamID = ID;}
	int32 GetTeamID() const {return TeamID;}

	void SetFLinearColor(FLinearColor Color){TeamColor = Color;}
	FLinearColor GetFLinearColor() const {return TeamColor;}

	void AddDeath() {++DeathsNum;}
	int32 GetDeathsNum() const {return DeathsNum;}

	void AddKill() {++KillsNum;}
	int32 GetKillsNum() const {return KillsNum;}

	void LogInfo();

  private:
	int32 TeamID;
	FLinearColor TeamColor;

	int32 KillsNum = 0;
	int32 DeathsNum = 0;
};
