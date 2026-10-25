// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "System/Interaction/Interaction.h"
#include "Chest.generated.h"

class USkeletalMeshComponent;

UCLASS()
class AChest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChest();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractComps")
	TObjectPtr<UInteraction> Intetract;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USkeletalMeshComponent> ChestMesh;
	UFUNCTION(BlueprintCallable, Category = "Interact")
	void OpenChest(ACharacter* Caller);
private:
	bool bIsOpen = false;
};
