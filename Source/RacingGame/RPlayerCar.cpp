// Fill out your copyright notice in the Description page of Project Settings.

#include "ChaosVehicles/Public/ChaosWheeledVehicleMovementComponent.h"
#include "RHUD.h"
#include "RPlayerCar.h"
#include "InputActionValue.h"
#include "RPlayerController.h"


void ARPlayerCar::BeginPlay()
{
	Super::BeginPlay();
	WheeledComponent = Cast<UChaosWheeledVehicleMovementComponent>(GetVehicleMovement());
}

void ARPlayerCar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RHUDObj = Cast<ARPlayerController>(GetWorld()->GetFirstPlayerController())->URHUDObject;
	RHUDObj->SetGaugeProgress(MaxBoosterGauge, CurrentBoosterGauge);

	UE_LOG(LogTemp, Warning, TEXT("Finded"));
	//UE_LOG(LogTemp, Error, TEXT(wheeledComponent->GetEngineRotationSpeed()));
	UE_LOG(LogTemp, Error, TEXT("Engine Rotation Speed: %f"), WheeledComponent->GetEngineRotationSpeed());

	if (WheeledComponent->GetWheelState(1).bIsSkidding)
	{
		AddBosster(1);
	}
	if (WheeledComponent->GetWheelState(2).bIsSkidding)
	{
		AddBosster(1);
	}
}

void ARPlayerCar::AddBosster(int value)
{
	if (CurrentBoosterGauge + value < MaxBoosterGauge)
	{
		CurrentBoosterGauge += value;
	}
	else 
	{
		CurrentBoosterGauge = MaxBoosterGauge;
	}

	//해드업 디스플레이에 현재 값 반영
}

void ARPlayerCar::BossterOn(const FInputActionValue& value)
{
	if (CurrentBoosterGauge == MaxBoosterGauge)
	{
		UE_LOG(LogTemp, Error, TEXT("BoosterOn"));
		CurrentBoosterGauge = 0;
		WheeledComponent->IncreaseThrottleInput(1);
	}
}
