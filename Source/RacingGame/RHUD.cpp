// Fill out your copyright notice in the Description page of Project Settings.

#include "RHUD.h"
#include "Components/ProgressBar.h"

URHUD::URHUD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
}

void URHUD::NativeConstruct()
{
	WidgetObj = GetWidgetFromName(TEXT("BoosterGauge"));
	GaugeProgressBar = Cast<UProgressBar>(WidgetObj);
}

void URHUD::SetGaugeProgress(float MaxValue, float CurValue)
{
	if (GaugeProgressBar != nullptr)
	{
		GaugeProgressBar->SetPercent(CurValue / MaxValue);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ItsNull"));
	}
}
