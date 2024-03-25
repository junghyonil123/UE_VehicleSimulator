// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "InputActionValue.h"
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
	virtual void BeginPlay() override;

	void AddBosster(int value);
	void BossterOn(const FInputActionValue& value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	int32 MaxBoosterGauge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	int32 CurrentBoosterGauge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	TObjectPtr<class UChaosWheeledVehicleMovementComponent> WheeledComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	TObjectPtr<class URHUD> RHUDObj;

};
