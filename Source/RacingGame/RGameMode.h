// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RGameMode.generated.h"

/**
 * 
 */
UCLASS()
class RACINGGAME_API ARGameMode : public AGameModeBase
{
	GENERATED_BODY()
	FTimerHandle CountdownTimerHandle;

protected:
	virtual void BeginPlay() override;
	void RecordScore();

private:
	FVector PlayerCarLastPos;
	int8 InitFinish = 0;

public:
	float Score;
	TObjectPtr<class ARPlayerController> Controller;
};
