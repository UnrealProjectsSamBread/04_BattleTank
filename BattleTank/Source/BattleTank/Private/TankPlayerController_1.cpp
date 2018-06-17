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

	FVector OutHitResult;
	if (GetSightRayHitLocation(OutHitResult))
	{
		UE_LOG(LogTemp, Warning, TEXT("OutHitResult: %s"), *(OutHitResult.ToString()));
		// TODO: Tell controlled Tank to aim at this point
	}
}

bool ATankPlayerController_1::GetSightRayHitLocation(FVector& OutHitResult) const
{
	OutHitResult = FVector(1.0);
	return true;
}



