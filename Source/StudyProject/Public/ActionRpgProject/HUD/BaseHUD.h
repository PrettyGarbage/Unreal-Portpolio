﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BaseHUD.generated.h"

/**
 * 
 */
UCLASS()
class STUDYPROJECT_API ABaseHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category="Widget")
	TSubclassOf<class UUIOverlay> OverlayWidgetClass;

	TObjectPtr<class UUIOverlay> OverlayWidget;
};
