// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GeometryCollection/GeometryCollectionComponent.h"
#include "BrakeAbleGimmick.generated.h"

DECLARE_MULTICAST_DELEGATE(OnHPChangeDelegate);

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
	OnHPChangeDelegate OnHpChanged;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category = Hyonil)
	TObjectPtr<class UBoxComponent> BoxComponent;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category = Hyonil)
	float MaxHp;
	FORCEINLINE void SetCurrentHP(float value) { CurrentHp = FMath::Clamp(CurrentHp + value, CurrentHp + value, MaxHp); OnHpChanged.Broadcast(); }
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	TObjectPtr<class UWidgetComponent> HPBarWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	float CurrentHp;

protected:
	virtual void PostInitializeComponents() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite ,Category = Hyonil)
	TObjectPtr<UBoxComponent> Trigger;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepHitResult);
//protected:
//	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
//	TObjectPtr<class UGeometryCollectionComponent> GeometryComponent;

};
