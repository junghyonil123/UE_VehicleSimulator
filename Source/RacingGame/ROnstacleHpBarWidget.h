// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ROnstacleHpBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class RACINGGAME_API UROnstacleHpBarWidget : public UUserWidget
{
	GENERATED_BODY()
	
	protected:
	UROnstacleHpBarWidget(const FObjectInitializer& ObjectInitializer);

	UPROPERTY()
	TObjectPtr<class UProgressBar> HpProgressBar;

	virtual void NativeConstruct() override;

public:
	void SetHpBarValue(float MaxHp, float CurHp);

	//UPROPERTY()
	//TObjectPtr<class UTextBlock> HpStat;

	//UPROPERTY()
	//float CurrentHp;

	//UPROPERTY()
	//float MaxHp;
	
};
