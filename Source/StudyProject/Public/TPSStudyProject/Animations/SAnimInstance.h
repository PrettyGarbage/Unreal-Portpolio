// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "SAnimInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCheckHitDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCheckCanNextComboDelegate);

UCLASS()
class STUDYPROJECT_API USAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	friend class ASRPGCharacter;
	friend class ASNonPlayerCharacter;

public:
	USAnimInstance();

	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	void PlayAttackMontage();

	UFUNCTION()
	void AnimNotify_CheckHit() const;

	UFUNCTION()
	void AnimNotify_CheckCanNextCombo() const;

	UFUNCTION()
	void OnCharacterDeath();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "USAnimInstance")
	float CurrentSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "USAnimInstance")
	FVector Velocity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "USAnimInstance")
	uint8 bIsFalling : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "USAnimInstance")
	uint8 bIsCrouching : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "USAnimInstance")
	TObjectPtr<UAnimMontage> AttackAnimMontage;

	FOnCheckHitDelegate OnCheckHitDelegate;

	FOnCheckCanNextComboDelegate OnCheckCanNextComboDelegate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "USAnimInstance", Meta = (AllowPrivateAccess))
	uint8 bIsDead : 1;
};
