// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController_1.h"

void ATankPlayerController_1::BeginPlay() 
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	FString TankName = ControlledTank->GetName();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possesing %s"), *TankName);
	}


}

void ATankPlayerController_1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}


ATank* ATankPlayerController_1::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController_1::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	// Get World location if line trace through CrossHair
	// If if hits the land
		// Then we tell the Player Tank to aim at this point
}



