// Fill out your copyright notice in the Description page of Project Settings.

#include "ChaosVehicles/Public/ChaosWheeledVehicleMovementComponent.h"
#include "RHUD.h"
#include "RPlayerCar.h"
#include "InputActionValue.h"
#include "RCarStatComponent.h"
#include "RPlayerController.h"


void ARPlayerCar::BeginPlay()
{
	Super::BeginPlay();
	WheeledComponent = Cast<UChaosWheeledVehicleMovementComponent>(GetVehicleMovement());
}

ARPlayerCar::ARPlayerCar()
{
	Stat = CreateDefaultSubobject<URCarStatComponent>(TEXT("Stat"));
}

void ARPlayerCar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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
	if (Stat->CurrentBoosterGauge + value < Stat->MaxBoosterGauge)
	{
		Stat->CurrentBoosterGauge += value;
	}
	else 
	{
		Stat->CurrentBoosterGauge = Stat->MaxBoosterGauge;
	}
	
	//해드업 디스플레이에 현재 값 반영
}

void ARPlayerCar::BossterOn(const FInputActionValue& value)
{
	if (Stat->CurrentBoosterGauge == Stat->MaxBoosterGauge)
	{
		UE_LOG(LogTemp, Error, TEXT("BoosterOn"));
		Stat->CurrentBoosterGauge = 0;
		WheeledComponent->IncreaseThrottleInput(1);
	}
}

float ARPlayerCar::GetDamage()
{
	int Damage = Stat->BodyHardness * WheeledComponent->GetForwardSpeed();
	Damage = Damage < 0 ? 0 : Damage;
	return Damage;
}
