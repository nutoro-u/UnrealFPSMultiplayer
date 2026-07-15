// Copyrights Mazen Issa - neckkeys


#include "Character/ShooterCharacter.h"

#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"
#include "Combat/CombatComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

AShooterCharacter::AShooterCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->MovementState.bCanCrouch = true;
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 0.f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 15.f;
	SpringArm->bUsePawnControlRotation = true;
	
	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>("FirstPersonCamera");
	FirstPersonCamera->SetupAttachment(SpringArm);
	FirstPersonCamera->bUsePawnControlRotation = false;
	
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh1P");
	Mesh1P->SetupAttachment(FirstPersonCamera);
	Mesh1P->bOnlyOwnerSee = true;
	Mesh1P->bOwnerNoSee = false;
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->bReceivesDecals = false;
	Mesh1P->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::OnlyTickPoseWhenRendered;
	Mesh1P->PrimaryComponentTick.TickGroup = TG_PrePhysics;
	
	GetMesh()->bOnlyOwnerSee = false;
	GetMesh()->bOwnerNoSee = true;
	GetMesh()->bReceivesDecals = false;
	
	Combat = CreateDefaultSubobject<UCombatComponent>("Combat");
	Combat->SetIsReplicated(true);
}

void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* ShooterInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	ShooterInputComponent->BindAction(CycleWeaponAction, ETriggerEvent::Started, this, &ThisClass::InputCycleWeapons);
	ShooterInputComponent->BindAction(FireWeaponAction, ETriggerEvent::Started, this, &ThisClass::InputFireWeaponPressed);
	ShooterInputComponent->BindAction(FireWeaponAction, ETriggerEvent::Completed, this, &ThisClass::InputFireWeaponReleased);
	ShooterInputComponent->BindAction(AimWeaponAction, ETriggerEvent::Started, this, &ThisClass::InputAimPressed);
	ShooterInputComponent->BindAction(AimWeaponAction, ETriggerEvent::Completed, this, &ThisClass::InputAimReleased);
	ShooterInputComponent->BindAction(ReloadWeaponAction, ETriggerEvent::Started, this, &ThisClass::InputReloadWeapon);
}

void AShooterCharacter::InputCycleWeapons()
{
	Combat->InitCycleWeapons();
}

void AShooterCharacter::InputFireWeaponPressed()
{
	Combat->InitFireWeaponPressed();
}

void AShooterCharacter::InputFireWeaponReleased()
{
	Combat->InitFireWeaponReleased();
}

void AShooterCharacter::InputReloadWeapon()
{
	Combat->InitReloadWeapon();
}

void AShooterCharacter::InputAimPressed()
{
	Combat->InitAimPressed();
}

void AShooterCharacter::InputAimReleased()
{
	Combat->InitAimReleased();
}
