// Shoot Them Up Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/STUBaseCharacter.h"
#include "STUAICharacter.generated.h"

class UBehaviorTree;
class UWidgetComponent;
UCLASS()
class SHOOTTHEMUP_API ASTUAICharacter : public ASTUBaseCharacter
{
	GENERATED_BODY()
public:
	ASTUAICharacter(const FObjectInitializer &ObjInit);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
	UBehaviorTree *BehaviorTreeAsset;
	virtual void Tick(float DeltaTime) override;
  protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI")
	float HealthBarVisibilityDistance = 1000.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UWidgetComponent* HealthBarWidgetComponent;

	virtual void BeginPlay() override;
	virtual void OnDeath() override;
	virtual void OnHealthChanged(float Health,float HealthDelta) override;
private:
	void UpdateHealthWidgetVisibility();
};
