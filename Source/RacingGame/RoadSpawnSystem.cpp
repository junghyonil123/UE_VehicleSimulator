// Fill out your copyright notice in the Description page of Project Settings.


#include "RaodObject.h"
#include "RoadSpawnSystem.h"

// Sets default values
ARoadSpawnSystem::ARoadSpawnSystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARoadSpawnSystem::BeginPlay()
{
	Super::BeginPlay();

	RoadManageArray.Add(SpwnRoad(FVector(0.0f, 0.0f, 0.0f)));

	for (size_t i = 1; i < 5; i++)
	{
		RoadManageArray.Add(SpwnRoad(RoadManageArray[i - 1]->location));
	}
}

RaodObject* ARoadSpawnSystem::SpwnRoad(FVector lastRoadPosition)
{
	RaodObject* NewRoad = GetWorld()->SpawnActorDeferred<RaodObject>(RaodObject::StaticClass(), lastRoadPosition);
	if (NewRoad)
	return NewRoad();
}




// Called every frame
void ARoadSpawnSystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

