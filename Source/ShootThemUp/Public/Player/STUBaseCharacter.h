// Shoot Them Up Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "STUBaseCharacter.generated.h"


class USTUHealthComponent;
class USTUWeaponComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
  ASTUBaseCharacter(const FObjectInitializer &ObjInit);

protected:	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USTUHealthComponent *HealthComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USTUWeaponComponent *WeaponComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	UAnimMontage *DeathAnimMontage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Damage")
	float LifeSpanOnDeath = 5.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	FVector2D LandedDamageVelocity = FVector2D(900.0f, 1200.0f);

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	FVector2D LandedDamage = FVector2D(10.0f, 100.0f);

	virtual void BeginPlay() override;
	virtual void OnDeath();

	UPROPERTY(EditDefaultsOnly, Category = "Material")
	FName MaterialColorName = "Paint Color";


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	UFUNCTION(BlueprintCallable, Category = "Movment")
	virtual bool IsRunning() const;
	UFUNCTION(BlueprintCallable, Category = "Movment")
	float GetMovementDirection() const;

	void SetPlayerColor(const FLinearColor &Color);

 private:
	
	void OnHealthChanged(float Health,float HealthDelta);
	
	UFUNCTION()
	void OnGroundLanded(const FHitResult &Hit);
};