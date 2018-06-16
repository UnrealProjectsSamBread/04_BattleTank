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

ATank* ATankPlayerController_1::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}



