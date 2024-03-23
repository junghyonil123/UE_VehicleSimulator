// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RHUD.generated.h"

/**
 * 
 */
UCLASS()
class RACINGGAME_API URHUD : public UUserWidget
{
	GENERATED_BODY()

protected:
	URHUD(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	TObjectPtr<class UWidget> WidgetObj;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Hyonil)
	TObjectPtr<class UProgressBar> GaugeProgressBar;

	void SetGaugeProgress(float MaxValue, float CurValue);
};
