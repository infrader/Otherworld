// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"      
#include "World/Interactables/Chest.h"                        
#include "DrawDebugHelpers.h"
#include "InputAction.h"
#include "GameCharacter.generated.h"

UCLASS()
class AGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGameCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<class UCameraComponent> FirstPersonCamera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction")
	TObjectPtr<class UInputAction> InteractKey;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interaction")
	float InteractDistance = 300.0f;


	void InteractPress();
public:	

	virtual void Tick(float DeltaTime) override;
};
