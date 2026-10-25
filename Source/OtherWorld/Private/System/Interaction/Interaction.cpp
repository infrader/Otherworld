#include "Interaction.h"

UInteraction::UInteraction()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInteraction::PlayVisuals(USkeletalMeshComponent* TargetMesh) {

	if (OpenSound) { 
		UGameplayStatics::PlaySoundAtLocation(GetOwner(), OpenSound, GetOwner()->GetActorLocation());
	}

	if (Anim && TargetMesh && TargetMesh->GetAnimInstance()) {
		TargetMesh->GetAnimInstance()->Montage_Play(Anim);
	}

	OnVisualsPlayed();
}