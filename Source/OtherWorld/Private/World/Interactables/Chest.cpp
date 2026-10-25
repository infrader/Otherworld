// Fill out your copyright notice in the Description page of Project Settings.


#include "World/Interactables/Chest.h"

// Sets default values
AChest::AChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Intetract = CreateDefaultSubobject<UInteraction>(TEXT("Interact"));
	ChestMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("ChestMesh"));
	RootComponent = ChestMesh;
}

void AChest::OpenChest(ACharacter* Caller) {
	if (bIsOpen) return;
	bIsOpen = true;

	if (Intetract && ChestMesh)
	{
		Intetract->PlayVisuals(ChestMesh);
	}
};
