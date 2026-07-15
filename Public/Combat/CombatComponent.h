// Copyrights Mazen Issa - neckkeys

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"


class AWeapon;
class UWeaponData;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MULTIPLAYERFPS_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCombatComponent();
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
							   FActorComponentTickFunction* ThisTickFunction) override;

	void InitCycleWeapons();
	void InitFireWeaponPressed();
	void InitFireWeaponReleased();
	void InitReloadWeapon();
	void InitAimPressed();
	void InitAimReleased();
	
	UPROPERTY(EditDefaultsOnly, Category="FPS|Weapon")
	TObjectPtr<UWeaponData> WeaponData;
	
	void SpawnInventory() const;
protected:

private:
	UPROPERTY(EditDefaultsOnly, Category="FPS|Weapon")
	TSubclassOf<AWeapon> DefaultWeaponClass;
	
	AWeapon* SpawnWeapon(TSubclassOf<AWeapon> WeaponClass) const;
};
