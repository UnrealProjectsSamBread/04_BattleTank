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

	ATank * GetControlledTank() const;

	virtual void BeginPlay() override;
	
	
	
	
};
