// Copyrights Mazen Issa - neckkeys

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class UInputAction;
class UCombatComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class MULTIPLAYERFPS_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AShooterCharacter();
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:
	void InputCycleWeapons();
	void InputFireWeaponPressed();
	void InputFireWeaponReleased();
	void InputReloadWeapon();
	void InputAimPressed();
	void InputAimReleased();
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCombatComponent> Combat;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USkeletalMeshComponent> Mesh1P;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> SpringArm;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> FirstPersonCamera;
	
	UPROPERTY(EditAnywhere, Category="FPS|Input")
	TObjectPtr<UInputAction> AimWeaponAction;
	
	UPROPERTY(EditAnywhere, Category="FPS|Input")
	TObjectPtr<UInputAction> CycleWeaponAction;
	
	UPROPERTY(EditAnywhere, Category="FPS|Input")
	TObjectPtr<UInputAction> ReloadWeaponAction;
	
	UPROPERTY(EditAnywhere, Category="FPS|Input")
	TObjectPtr<UInputAction> FireWeaponAction;
};
