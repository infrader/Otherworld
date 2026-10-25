// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Character/GameCharacter.h"

// Sets default values
AGameCharacter::AGameCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCamera->SetupAttachment(GetMesh(), FName("head"));
	FirstPersonCamera->bUsePawnControlRotation = true;
}
void AGameCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent); // EnhancedInput system
	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (InteractKey)
		{
			EnhancedInput->BindAction(InteractKey, ETriggerEvent::Started, this, &AGameCharacter::InteractPress);
		}
	}
};
void AGameCharacter::InteractPress() {
	if (!Controller) return;

	FVector StartLocation;
	FRotator CameraRotation;

	Controller->GetPlayerViewPoint(StartLocation, CameraRotation);
	FVector EndLocation = StartLocation + (CameraRotation.Vector() * InteractDistance);

	FHitResult HitResult;
	FCollisionQueryParams QueryParams;

	QueryParams.AddIgnoredActor(this);

	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, QueryParams);
	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, 2.0f, 0, 2.0f);
	if (bHit)
	{
		AActor* HitActor = HitResult.GetActor();

		if (AChest* HitChest = Cast<AChest>(HitActor))
		{
			HitChest->OpenChest(this);
		}
	}

};

// Called when the game starts or when spawned
void AGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
