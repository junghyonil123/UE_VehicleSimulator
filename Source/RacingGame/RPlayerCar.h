// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "RPlayerCar.generated.h"

/**
 * 
 */
UCLASS()
class RACINGGAME_API ARPlayerCar : public AWheeledVehiclePawn
{
	GENERATED_BODY()
	
	public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	float MaxBoosterGauge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	float CurrentBoosterGauge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	TObjectPtr<class UChaosWheeledVehicleMovementComponent> wheeledComponent;
};
