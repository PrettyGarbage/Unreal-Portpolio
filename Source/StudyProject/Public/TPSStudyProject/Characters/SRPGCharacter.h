// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TPSStudyProject/Characters/SCharacter.h"
#include "InputActionValue.h"
#include "SRPGCharacter.generated.h"

/**
 * 
 */
UCLASS()
class STUDYPROJECT_API ASRPGCharacter : public ASCharacter
{
	GENERATED_BODY()

	friend class UAN_CheckHit;

public:
	ASRPGCharacter();

	virtual void BeginPlay() override;

	float GetForwardInputValue() const { return ForwardInputValue; }

	float GetRightInputValue() const { return RightInputValue; }

	UFUNCTION()
	void OnAttackMontageEnded(UAnimMontage* Montage, bool bInterrupted);

	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;
	
protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

private:
	void Move(const FInputActionValue& InValue);

	void Look(const FInputActionValue& InValue);

	void Attack(const FInputActionValue& InValue);

	UFUNCTION()
	void CheckHit();

	void BeginCombo();

	UFUNCTION()
	void CheckCanNextCombo();

	UFUNCTION()
	void EndCombo(class UAnimMontage* InAnimMontage, bool bInterrupted);

	UFUNCTION()
	void OnCurrentLevelChanged(int32 InPrevCurrentLevel, int32 InNewCurrentLevel);

	UFUNCTION()
	void OnAssetLoaded();

	void Menu(const FInputActionValue& InValue);
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ASRPGCharacter", Meta = (AllowPrivateAccess))
	TObjectPtr<class USInputConfigData> PlayerCharacterInputConfigData;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ASRPGCharacter", Meta = (AllowPrivateAccess))
	TObjectPtr<class UInputMappingContext> PlayerCharacterInputMappingContext;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ASRPGCharacter", Meta = (AllowPrivateAccess = true))
	float ForwardInputValue;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "ASRPGCharacter", Meta = (AllowPrivateAccess = true))
	float RightInputValue;

	uint8 bIsAttacking : 1;

	FString AttackAnimMontageSectionName = FString(TEXT("Attack"));

	int32 MaxComboCount = 3;

	int32 CurrentComboCount = 0;

	bool bIsAttackKeyPressed = false;

	float AttackRange =200.f;

	float AttackRadius = 50.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ASRPGCharacter", Meta = (AllowPrivateAccess))
	TObjectPtr<class UParticleSystemComponent> ParticleSystemComponent;

	FSoftObjectPath CurrentPlayerCharacterMeshPath = FSoftObjectPath();

	TSharedPtr<struct FStreamableHandle> AssetStreamableHandle = nullptr;

};
