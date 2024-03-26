// Fill out your copyright notice in the Description page of Project Settings.

#include "RHUD.h"
#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

URHUD::URHUD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

}

void URHUD::NativeConstruct()
{
	WidgetObj = GetWidgetFromName(TEXT("BoosterGauge"));
	GaugeProgressBar = Cast<UProgressBar>(WidgetObj);
	CarDamageValueText = Cast<UTextBlock>(GetWidgetFromName(TEXT("CarDamageValue")));
	ScoreValueText = Cast<UTextBlock>(GetWidgetFromName(TEXT("ScoreValue")));
}

void URHUD::SetBoosterGaugeProgress(float MaxValue, float CurValue)
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

void URHUD::SetDamageValue(int Damage)
{
	CarDamageValueText->SetText(FText::FromString(FString::FromInt(Damage)));
}

void URHUD::SetScoreValue(float Score)
{
	ScoreValueText->SetText(FText::FromString(FString::SanitizeFloat(round(Score))));
}



