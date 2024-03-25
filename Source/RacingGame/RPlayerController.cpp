// Fill out your copyright notice in the Description page of Project Settings.

#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputTriggers.h"
#include "RPlayerController.h"

void ARPlayerController::BossterOn()
{
	UE_LOG(LogTemp, Error, TEXT("Booster"));
}

void ARPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	//EnhancedInputComponent->BindAction(BoosterOnAction, ETriggerEvent::Triggered, GetPawn(), GetPawn()->GetClass()::BossterOn);
	EnhancedInputComponent->BindAction(BoosterOnAction, ETriggerEvent::Triggered, this, &ARPlayerController::BossterOn);
}
