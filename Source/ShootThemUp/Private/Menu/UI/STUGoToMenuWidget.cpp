// Shoot Them Up Game, All Rights Reserved.


#include "Menu/UI/STUGoToMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "STUGameInstance.h"

DEFINE_LOG_CATEGORY_STATIC(LogSTUGoToMenuWidget, All, All);

void USTUGoToMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	if(GoToMenuButton)
	{
		GoToMenuButton->OnClicked.AddDynamic(this, &USTUGoToMenuWidget::OnGoToMenuClicked);
		
	}
}

void USTUGoToMenuWidget::OnGoToMenuClicked()
{
	if(!GetWorld()) return;
	const auto STUGameInstance = GetWorld()->GetGameInstance<USTUGameInstance>();
	if(!STUGameInstance) return;
	if (STUGameInstance->GetMenuLevelName().IsNone())
	{
		UE_LOG(LogSTUGoToMenuWidget, Warning, TEXT("No start up level set"));
		return;
	}
	UGameplayStatics::OpenLevel(this, STUGameInstance->GetMenuLevelName());
}
