// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RCarStatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RACINGGAME_API URCarStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URCarStatComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	int Level = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	int MaxExp = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	int CurExp = 0;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	int BodyHardness = 1;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	int32 MaxBoosterGauge;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	int32 CurrentBoosterGauge;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
