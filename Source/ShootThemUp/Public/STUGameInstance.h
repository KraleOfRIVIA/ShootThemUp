// Shoot Them Up Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "STUCoreTypes.h"
#include "STUGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTTHEMUP_API USTUGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	FLevelData GetStartUpLevelName() const { return StartUpLevel; }
	void SetStartUpLevelName(const FLevelData& Data) { StartUpLevel = Data; }

	TArray<FLevelData> GetLevelsData() const { return LevelsData; }
	FName GetMenuLevelName() const {return MenuLevelName;}
protected:
	UPROPERTY(EditDefaultsOnly, Category = "Game")
	TArray<FLevelData> LevelsData ;

	
	UPROPERTY(EditDefaultsOnly, Category = "Menu")
	FName MenuLevelName = NAME_None;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Game")
	FLevelData StartUpLevel;
	
};
