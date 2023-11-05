// Shoot Them Up Game, All Rights Reserved.


#include "AI/STUAICharacter.h"
#include "AI/STUAIController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Component/STUAIWeaponComponent.h"
#include "BrainComponent.h"
#include "STUHealthBarWidget.h"
#include "Components/WidgetComponent.h"
#include "Component/STUHealthComponent.h"
ASTUAICharacter::ASTUAICharacter(const FObjectInitializer &ObjInit)
	: Super(ObjInit.SetDefaultSubobjectClass<USTUAIWeaponComponent>("WeaponComponent"))
{
	AutoPossessAI = EAutoPossessAI::Disabled;
	AIControllerClass = ASTUAIController::StaticClass();

	bUseControllerRotationYaw = false;

	if (GetCharacterMovement())
	{
		GetCharacterMovement()->bUseControllerDesiredRotation = true;
		GetCharacterMovement()->RotationRate = FRotator(0.0f, 200.0f, 0.0f);
	}
	HealthBarWidgetComponent = CreateDefaultSubobject<UWidgetComponent>("HealthBarWidgetComponent");
	HealthBarWidgetComponent->SetupAttachment(RootComponent);
	HealthBarWidgetComponent->SetWidgetSpace(EWidgetSpace::Screen);
	HealthBarWidgetComponent->SetDrawAtDesiredSize(true);
}

void ASTUAICharacter::OnDeath()
{
	Super::OnDeath();

	const auto STUController = Cast<AAIController>(Controller);
	if (STUController && STUController->BrainComponent)
	{
		STUController->BrainComponent->Cleanup();
	}
}

void ASTUAICharacter::BeginPlay()
{
	Super::BeginPlay();
	check(HealthBarWidgetComponent);
}

void ASTUAICharacter::OnHealthChanged(float Health, float HealthDelta)
{
	Super::OnHealthChanged(Health, HealthDelta);

	const auto HealthBarWidget = Cast<USTUHealthBarWidget>(HealthBarWidgetComponent->GetUserWidgetObject());
	if (!HealthBarWidget) return;
	HealthBarWidget->SetHealthPercent(HealthComponent->GetHealthPercent());
}

void ASTUAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateHealthWidgetVisibility();
}

void ASTUAICharacter::UpdateHealthWidgetVisibility()
{
	if(!GetWorld() || !GetWorld()->GetFirstPlayerController() || !GetWorld()->GetFirstPlayerController()->GetPawnOrSpectator()) return;
	
	const auto PlayerLocation = GetWorld()->GetFirstPlayerController()->GetPawnOrSpectator()->GetActorLocation();
	const auto Distance = FVector::Distance(PlayerLocation, GetActorLocation());
	
	HealthBarWidgetComponent->SetVisibility(Distance<HealthBarVisibilityDistance, true);
}
