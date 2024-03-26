// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RObstacleStatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RACINGGAME_API URObstacleStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URObstacleStatComponent();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	int MaxHp = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	int CurrentHp = 10;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
		
};
