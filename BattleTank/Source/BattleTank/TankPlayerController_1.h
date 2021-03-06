// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController_1.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController_1 : public APlayerController
{
	GENERATED_BODY()


public:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;


private:
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.3333;

	ATank * GetControlledTank() const;

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitResult) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

};
