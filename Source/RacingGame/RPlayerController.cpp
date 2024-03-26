// Fill out your copyright notice in the Description page of Project Settings.

#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputTriggers.h"
#include "RPlayerCar.h"
#include "RHUD.h"
#include "RCarStatComponent.h"
#include "RPlayerController.h"

void ARPlayerController::BossterOn(const FInputActionValue& value)
{
	PlayerActor->BossterOn(value);
}

void ARPlayerController::BeginPlay()
{
	Super::BeginPlay();
	PlayerActor = Cast<ARPlayerCar>(GetPawn());
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(BoosterOnAction, ETriggerEvent::Triggered, this, &ARPlayerController::BossterOn);
}

void ARPlayerController::Tick(float DeltaTime)
{
	URHUDObject->SetBoosterGaugeProgress(PlayerActor->Stat->MaxBoosterGauge, PlayerActor->Stat->CurrentBoosterGauge);
	URHUDObject->SetDamageValue(PlayerActor->GetDamage());
}
