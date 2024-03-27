// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RoadSpawnSystem.generated.h"

UCLASS()
class RACINGGAME_API ARoadSpawnSystem : public AActor
{
	GENERATED_BODY()
	
public:
	TArray<class ARaodObject*> RoadManageArray;
	
public:	
	// Sets default values for this actor's properties
	ARoadSpawnSystem();
	FTimerHandle CountdownTimerHandle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	class ARaodObject* SpwnRoad(FVector lastRoadPosition);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void StartSystem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	TSubclassOf<AActor> SpawnedRoadActor;
};
