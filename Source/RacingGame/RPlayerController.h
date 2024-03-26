// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputActionValue.h"
#include "RPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class RACINGGAME_API ARPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	TObjectPtr<class URHUD> URHUDObject;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	TObjectPtr<class ARPlayerCar> PlayerActor;
	void BossterOn(const FInputActionValue& value);


public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> BoosterOnAction;
};


