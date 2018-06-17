// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "../Public/TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller not possesing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possesing %s"), *(ControlledTank->GetName()));
	}

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller didn't find PlayerTank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller found player Tank: %s"), *(PlayerTank->GetName()));
	}


}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}




