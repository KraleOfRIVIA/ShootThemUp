// Shoot Them Up Game, All Rights Reserved.


#include "Menu/UI/STUMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "STUGameInstance.h"
#include "Menu/UI/STULevelItemWidget.h"
#include "Components/HorizontalBox.h"

void USTUMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	if(StartGameButton)
	{
		StartGameButton->OnClicked.AddDynamic(this, &USTUMenuWidget::OnStartGame);
	}
	if(ExitGameButton)
	{
		ExitGameButton->OnClicked.AddDynamic(this, &USTUMenuWidget::OnExitGame);
	}
	InitLevelItems();
}

void USTUMenuWidget::OnStartGame()
{
	const auto STUGameInstance = GetSTUGameInstance();
	UGameplayStatics::OpenLevel(this, STUGameInstance->GetStartUpLevelName().LevelName);
}

void USTUMenuWidget::OnExitGame()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}

void USTUMenuWidget::InitLevelItems()
{
	const auto STUGameInstance = GetSTUGameInstance();
	if(!STUGameInstance) return;
	
	checkf(STUGameInstance->GetLevelsData().Num() != 0, TEXT("No levels set"));
	
	if(!LevelItemsBox) return;
	LevelItemsBox->ClearChildren();
	for(auto LevelData : STUGameInstance->GetLevelsData())
	{
		const auto LevelItemWidget = CreateWidget<USTULevelItemWidget>(GetWorld(), LevelItemWidgetClass);
		if(!LevelItemWidget) continue;
		
		LevelItemWidget->SetLevelData(LevelData);
		LevelItemWidget->OnLevelSelected.AddUObject(this, &USTUMenuWidget::OnLevelSelected);
		
		LevelItemsBox->AddChild(LevelItemWidget);
		LevelItemsWidgets.Add(LevelItemWidget);
	}
	if(STUGameInstance->GetStartUpLevelName().LevelName.IsNone())
	{
		OnLevelSelected(STUGameInstance->GetLevelsData()[0]);
	}
	else
	{
		OnLevelSelected(STUGameInstance->GetStartUpLevelName());
	}
}

void USTUMenuWidget::OnLevelSelected(const FLevelData &Data)
{
	const auto STUGameInstance = GetSTUGameInstance();
	if(!STUGameInstance) return;
	
	STUGameInstance->SetStartUpLevelName(Data);
	for(auto LevelItemWidget : LevelItemsWidgets)
	{
		if(LevelItemWidget)
		{
			const auto IsSelected = Data.LevelName == LevelItemWidget->GetLevelData().LevelName;
			LevelItemWidget->SetSelected(IsSelected);
		}
	}
}

USTUGameInstance * USTUMenuWidget::GetSTUGameInstance() const
{
	if(!GetWorld()) return nullptr;
	return GetWorld()->GetGameInstance<USTUGameInstance>();
}
