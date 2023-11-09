// Shoot Them Up Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/STUBaseWeapon.h"
#include "STURifleWeapon.generated.h"

class USTUWeaponFXComponent;
class UNiagaraComponent;
class UNiagaraSystem;
class UAudioComponent;
UCLASS()
class SHOOTTHEMUP_API ASTURifleWeapon : public ASTUBaseWeapon
{
	GENERATED_BODY()
  public:
	ASTURifleWeapon();

	virtual void StartFire() override;
	virtual void StopFire() override;

  protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	float TimerBetweenShots = 0.1f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float BulletSpread = 1.5f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon")
	float DamageAmount = 20.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
	UNiagaraSystem *TraceFX;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
	FString TraceTargetName = "TraceTarget";


	UPROPERTY(VisibleAnywhere, Category = "VFX")
	USTUWeaponFXComponent *WeaponFXComponent;


	virtual void BeginPlay() override;
	virtual void MakeShot() override;
	virtual bool GetTraceData(FVector &TraceStart, FVector &TraceEnd) const override;

  private:
	FTimerHandle ShotTimerHandle;

	UPROPERTY()
	UNiagaraComponent *MuzzleFXComponent;

	void MakeDamage(FHitResult &HitResult);

	void InitFX();
	UPROPERTY()
	UAudioComponent* FireAudioComponent;

	void SetFXActive(bool isActive);
	void SpawnTraceFX(const FVector &TraceStart, const FVector &TraceEnd);
	AController *GetController() const;
};
