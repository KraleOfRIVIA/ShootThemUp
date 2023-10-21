// Shoot Them Up Game, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/STUBaseCharacter.h"
#include "STUPlayerCharacter.generated.h"


class UCameraComponent;
class USpringArmComponent;
class USphereComponent;
UCLASS()
class SHOOTTHEMUP_API ASTUPlayerCharacter : public ASTUBaseCharacter
{
	GENERATED_BODY()
  public:
	// Sets default values for this character's properties
	ASTUPlayerCharacter(const FObjectInitializer &ObjInit);

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent *CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent *SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USphereComponent *CameraCollisionComponent;

	virtual void OnDeath() override;
	virtual void BeginPlay() override;

  public:
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;
	
	virtual bool IsRunning() const override;

  private:
	  void MoveForward(float Amount);
	void MoveRight(float Amount);

	void OnStartRun();
	void OnStopRun();


	bool WantsToRun = false;
	bool IsForward = false;
	UFUNCTION()
	void CameraCollisionBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex,bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION()
	void CameraCollisionEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	void CheckCameraOverlap();
};
