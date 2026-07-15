// Copyrights Mazen Issa - neckkeys

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "WeaponData.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERFPS_API UWeaponData : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, Category="FPS|WeaponData|Weapons")
	TMap<FGameplayTag, FName> GripPoints;
};
