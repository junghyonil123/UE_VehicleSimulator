// Fill out your copyright notice in the Description page of Project Settings.


#include "BrakeAbleGimmick.h"
#include "GeometryCollection/GeometryCollectionComponent.h"

// Sets default values
ABrakeAbleGimmick::ABrakeAbleGimmick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GeometryComponent = FindComponentByClass<UGeometryCollectionComponent>();

}

// Called when the game starts or when spawned
void ABrakeAbleGimmick::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABrakeAbleGimmick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

