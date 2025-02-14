#include "JPawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/ArrowComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "JPlayerController.h"

AJPawn::AJPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	RootComponent = CapsuleComp;
	CapsuleComp->SetSimulatePhysics(false);

	ArrowComp = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	ArrowComp->SetupAttachment(RootComponent);

	SkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMeshComp->SetupAttachment(RootComponent);
	SkeletalMeshComp->SetSimulatePhysics(false);

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 300.0f;
	SpringArmComp->bUsePawnControlRotation = false;

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComp->SetupAttachment(SpringArmComp);
	CameraComp->bUsePawnControlRotation = false;

	LookInput = FVector2D::ZeroVector;

	MaxHealth = 100.0f;
	Health = MaxHealth;

}

void AJPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FRotator CameraRotation = CameraComp->GetComponentRotation();
	const FRotator YawOnlyRotation(0.f, CameraRotation.Yaw, 0.f);

	if (!FMath::IsNearlyZero(LookInput.X))
	{
		const float YawRotation = LookInput.X * TurnRate * DeltaTime;
		AddActorLocalRotation(FRotator(0.f, YawRotation, 0.f));
	}

	if (!FMath::IsNearlyZero(LookInput.Y))
	{
		FRotator CurrentArmRotation = SpringArmComp->GetRelativeRotation();
		float NewPitch = CurrentArmRotation.Pitch - (LookInput.Y * LookUpRate * DeltaTime);
		NewPitch = FMath::Clamp(NewPitch, MinPitch, MaxPitch);
		CurrentArmRotation.Pitch = NewPitch;
		SpringArmComp->SetRelativeRotation(CurrentArmRotation);
	}
}

void AJPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (AJPlayerController* PlayerController = Cast<AJPlayerController>(GetController()))
		{
			if (PlayerController->MoveAction)
			{
				EnhancedInput->BindAction(
					PlayerController->MoveAction,
					ETriggerEvent::Triggered,
					this,
					&AJPawn::Move
				);
			}

			if (PlayerController->LookAction)
			{
				EnhancedInput->BindAction(
					PlayerController->LookAction,
					ETriggerEvent::Triggered,
					this,
					&AJPawn::Look
				);

				EnhancedInput->BindAction(
					PlayerController->LookAction,
					ETriggerEvent::Completed,
					this,
					&AJPawn::StopLook
				);
			}
		}
	}
}

void AJPawn::Move(const FInputActionValue& value)
{
	FVector2D MovementVector = value.Get<FVector2D>();

	if (MovementVector.IsNearlyZero()) return;

	// ��Ʈ�ѷ��� ȸ�� �� ��������
	FRotator ControlRotation = GetControlRotation();

	//ī�޶� ������ �̵� ���� ��� (Z�� ȸ������ ���)
	FVector Forward = FRotationMatrix(ControlRotation).GetScaledAxis(EAxis::X);
	FVector Right = FRotationMatrix(ControlRotation).GetScaledAxis(EAxis::Y);

	// �̵� ������ ī�޶� �������� ��ȯ
	FVector Movement = (Forward * MovementVector.X) + (Right * MovementVector.Y);
	Movement.Normalize();

	// ���� �̵� ���� ���
	FVector FinalMovement = Movement * MoveSpeed * GetWorld()->GetDeltaSeconds();

	// �̵� ���� (�浹 ���� Ȱ��ȭ)
	AddActorLocalOffset(FinalMovement, true);

}

void AJPawn::Look(const FInputActionValue& value)
{
	LookInput = value.Get<FVector2D>();
}

void AJPawn::StopLook(const FInputActionValue& value)
{
	LookInput = FVector2D::ZeroVector;
}

void AJPawn::AddHealth(float Amount)
{
	Health = FMath::Clamp(Health + Amount, 0.0f, MaxHealth);
	UE_LOG(LogTemp, Log, TEXT("Health increased to: %.2f"), Health);
}

float AJPawn::GetHealth() const
{
	return Health;
}

float AJPawn::TakeDamage(
	float DamageAmount,
	FDamageEvent const& DamageEvent,
	AController* EventInstigator,
	AActor* DamageCauser)
{
	float ActualDamage = Super::TakeDamage(
		DamageAmount,
		DamageEvent,
		EventInstigator,
		DamageCauser);

	Health = FMath::Clamp(Health - DamageAmount, 0.0f, MaxHealth);
	UE_LOG(LogTemp, Warning, TEXT("Health decreased to: %.2f"), Health);

	if (Health <= 0.0f)
	{
		OnDeath();
	}
	
	return ActualDamage;
}

void AJPawn::OnDeath()
{
	UE_LOG(LogTemp, Error, TEXT("J is Dead!"));
}