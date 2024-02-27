﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionRpgProject/Animations/AnimNotify/DisableCollisionNotify.h"

#include "ActionRpgProject/Characters/ActionCharacter.h"

void UDisableCollisionNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                                     const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if(IsValid(MeshComp))
	{
		AActionCharacter* BindCharacter = Cast<AActionCharacter>(MeshComp->GetOwner());
		if(IsValid(BindCharacter))
		{
			BindCharacter->SetWeaponCollisionEnabled(ECollisionEnabled::NoCollision);
		}
	}
}