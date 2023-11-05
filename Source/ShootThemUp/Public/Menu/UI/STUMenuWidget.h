// Shoot Them Up Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STUCoreTypes.h"
#include "STUMenuWidget.generated.h"

class UButton;
class UHorizontalBox;
class USTUGameInstance;
class USTULevelItemWidget;
UCLASS()
class SHOOTTHEMUP_API USTUMenuWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(meta=(BindWidget))
	UButton* StartGameButton;
	UPROPERTY(meta=(BindWidget))
	UButton* ExitGameButton;

	UPROPERTY(meta=(BindWidget))
	UHorizontalBox* LevelItemsBox;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
	TSubclassOf<USTULevelItemWidget> LevelItemWidgetClass;
	virtual void NativeOnInitialized() override;
private:
	UPROPERTY()
	TArray<USTULevelItemWidget*> LevelItemsWidgets;
	UFUNCTION()
	void OnStartGame();
	UFUNCTION()
	void OnExitGame();

	void InitLevelItems();
	void OnLevelSelected(const FLevelData& Data);
	USTUGameInstance* GetSTUGameInstance()const;
};
