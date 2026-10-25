// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cube.generated.h"

UCLASS()
class OTHERWORLD_API ACube : public AActor
{
	GENERATED_BODY()
	
public:	
	ACube();

protected:
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* PropMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance")
	class UMaterialInterface* DefaultMaterial;
};
