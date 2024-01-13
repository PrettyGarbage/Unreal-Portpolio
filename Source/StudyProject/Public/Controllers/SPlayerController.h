// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class STUDYPROJECT_API ASPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ASPlayerController();

protected:
	virtual void  SetupInputComponent() override;
	virtual void BeginPlay() override;

private:
	void LeftRight(float InAxisValue);
	void UpDown(float InAxisValue);
};