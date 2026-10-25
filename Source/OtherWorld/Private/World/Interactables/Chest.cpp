// Fill out your copyright notice in the Description page of Project Settings.


#include "World/Interactables/Chest.h"

// Sets default values
AChest::AChest()
{
	PrimaryActorTick.bCanEverTick = false;
	ChestMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ChestMesh"));
	RootComponent = ChestMesh;
}

void AChest::Interact_Implementation(const AActor* Caller) {
	if (ChestisOpen) return;
	ChestisOpen = true;
	if (OpenSound) {
		UGameplayStatics::PlaySoundAtLocation(this, OpenSound, GetActorLocation());
	}

	if(OpenAnim && ChestMesh.Get()->GetAnimInstance())
};
