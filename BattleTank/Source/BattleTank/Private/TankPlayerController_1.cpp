#include "..\TankPlayerController_1.h"
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
		// TODO: Tell controlled Tank to aim at this point
	}
}

bool ATankPlayerController_1::GetSightRayHitLocation(FVector& OutHitResult) const
{

	// Find Corsair position in Pixel Co-ordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	// "De-project" the corsair position on the screen to a World Direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *(LookDirection.ToString()));
	}
	
	return true;
}

bool ATankPlayerController_1::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector WorldLocation; // To be discarded
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		WorldLocation,
		LookDirection
	);
	
}



