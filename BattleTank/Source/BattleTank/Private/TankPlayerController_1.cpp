// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController_1.h"

ATank* ATankPlayerController_1::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}




