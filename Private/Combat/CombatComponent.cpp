// Copyrights Mazen Issa - neckkeys


#include "Combat/CombatComponent.h"

#include "Engine/Engine.h"

UCombatComponent::UCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UCombatComponent::InitCycleWeapons()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("InitCycleWeapon"), false);
}

void UCombatComponent::InitFireWeaponPressed()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("InitFireWeaponPressed"), false);
}

void UCombatComponent::InitFireWeaponReleased()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("InitFireWeaponReleased"), false);
}

void UCombatComponent::InitReloadWeapon()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("InitReloadWeapon"), false);
}

void UCombatComponent::InitAimPressed()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("InitAimPressed"), false);
}

void UCombatComponent::InitAimReleased()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("InitAimReleased"), false);
}

