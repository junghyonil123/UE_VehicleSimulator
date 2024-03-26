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

	ARPlayerCar();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Hyonil)
	TObjectPtr<class URCarStatComponent> Stat;

	void AddBosster(int value);
	void BossterOn(const FInputActionValue& value);

	float GetDamage();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	TObjectPtr<class UChaosWheeledVehicleMovementComponent> WheeledComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	TObjectPtr<class URHUD> RHUDObj;

};
