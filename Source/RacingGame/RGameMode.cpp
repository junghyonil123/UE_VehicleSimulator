// Fill out your copyright notice in the Description page of Project Settings.


#include "RPlayerController.h"
#include "RPlayerCar.h"
#include "RHUD.h"
#include "RGameMode.h"

void ARGameMode::BeginPlay()
{
	Super::BeginPlay();
	//위치 초기화
	GetWorldTimerManager().SetTimer(CountdownTimerHandle, this, &ARGameMode::RecordScore, 0.1f, true, 1);
}

void ARGameMode::RecordScore()
{
	if (InitFinish == 0)
	{
		InitFinish = 1;

		UWorld* World = GetWorld();
		APlayerController* Con = World->GetFirstPlayerController();
		Controller = Cast<ARPlayerController>(Con);
		PlayerCarLastPos = Controller->PlayerActor->GetActorLocation();
		
		return;
	}

	Score += (Controller->PlayerActor->GetActorLocation() - PlayerCarLastPos).Size();
	PlayerCarLastPos = Controller->PlayerActor->GetActorLocation();
	Controller->URHUDObject->SetScoreValue(Score);


}
