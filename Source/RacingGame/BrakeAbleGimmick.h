// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BrakeAbleGimmick.generated.h"

UCLASS()
class RACINGGAME_API ABrakeAbleGimmick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrakeAbleGimmick();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

//public:
//	UPROPERTY(EditAnywhere, Category = Hyonil)
//	TObjectPtr<class UBoxComponent> UBoxComponent;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UGeometryCollectionComponent> GeometryComponent;

};
