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

	ATank * GetControlledTank() const;

	void AimTowardsCrosshair();

	
	
	
	
};
