// Fill out your copyright notice in the Description page of Project Settings.

#include "ChaosVehicles/Public/ChaosWheeledVehicleMovementComponent.h"
#include "RHUD.h"
#include "RPlayerCar.h"
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

void ARPlayerCar::AddBosster(float value)
{
	if (CurrentBoosterGauge + value < MaxBoosterGauge)
	{
		CurrentBoosterGauge += value;
	}
	else 
	{
		CurrentBoosterGauge = 0;
		BossterOn();
	}

	//해드업 디스플레이에 현재 값 반영
}

void ARPlayerCar::BossterOn()
{
}
