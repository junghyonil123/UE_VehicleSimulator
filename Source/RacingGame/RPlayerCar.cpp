// Fill out your copyright notice in the Description page of Project Settings.

#include "ChaosVehicles/Public/ChaosWheeledVehicleMovementComponent.h"
#include "RPlayerCar.h"

void ARPlayerCar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	wheeledComponent = Cast<UChaosWheeledVehicleMovementComponent>(GetVehicleMovement());

	UE_LOG(LogTemp, Warning, TEXT("Finded"));
	//UE_LOG(LogTemp, Error, TEXT(wheeledComponent->GetEngineRotationSpeed()));
	UE_LOG(LogTemp, Error, TEXT("Engine Rotation Speed: %f"), wheeledComponent->GetEngineRotationSpeed());

}