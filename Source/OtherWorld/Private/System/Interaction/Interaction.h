// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"           
#include "Animation/AnimInstance.h" 
#include "Animation/AnimMontage.h"
#include "Sound/SoundBase.h"
#include "Interaction.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UInteraction : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInteraction();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TObjectPtr<UAnimMontage> Anim; 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
	TObjectPtr<USoundBase> OpenSound;
	UFUNCTION(BlueprintImplementableEvent, Category = "Visuals")
	void OnVisualsPlayed();
	
	void PlayVisuals(USkeletalMeshComponent*  TargetMesh);
};
