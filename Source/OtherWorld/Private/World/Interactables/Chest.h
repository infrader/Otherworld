// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "IInteractable.h"
#include "Animation/AnimMontage.h"
#include "Kismet/GameplayStatics.h"
#include "Chest.generated.h"

UCLASS()
class AChest : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	AChest();
	virtual void Interact_Implementation(const AActor* Caller) override;
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class TObjectPtr<UStaticMeshComponent> ChestMesh;
private:
	bool ChestisOpen = false;
};
