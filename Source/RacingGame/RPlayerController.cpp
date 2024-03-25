// Fill out your copyright notice in the Description page of Project Settings.

#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputTriggers.h"
#include "RPlayerCar.h"
#include "RPlayerController.h"

void ARPlayerController::BossterOn(const FInputActionValue& value)
{
	UE_LOG(LogTemp, Error, TEXT("Booster"));

    FString StringValue;
    StringValue = *value.ToString();
    UE_LOG(LogTemp, Error, TEXT("String Value: %s"), *StringValue);
    Cast<ARPlayerCar>(GetPawn())->BossterOn(value);
	//Cast<ARPlayerCar>(GetPawn()->GetClass())->CurrentBoosterGauge = 0;
}

void ARPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(BoosterOnAction, ETriggerEvent::Triggered, this, &ARPlayerController::BossterOn);
}
