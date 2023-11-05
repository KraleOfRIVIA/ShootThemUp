// Shoot Them Up Game, All Rights Reserved.


#include "Menu/UI/STULevelItemWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
void USTULevelItemWidget::SetLevelData(const FLevelData &Data)
{
	LevelData = Data;
	if(LevelNameTextBlock)
	{
		LevelNameTextBlock->SetText(FText::FromName(Data.LevelDisplayName));
	}
	if(LevelImage)
	{
		LevelImage->SetBrushFromTexture(Data.LevelThumb);
	}
}

void USTULevelItemWidget::SetSelected(bool IsSelected)
{
	if(FrameImage)
	{
		FrameImage->SetVisibility(IsSelected ? ESlateVisibility::Visible : ESlateVisibility::Hidden);
	}
}

void USTULevelItemWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	if(LevelSelectionButton)
	{
		LevelSelectionButton->OnClicked.AddDynamic(this, &USTULevelItemWidget::OnLevelitemClicked);
	}
}

void USTULevelItemWidget::OnLevelitemClicked()
{
	OnLevelSelected.Broadcast(LevelData);
}
