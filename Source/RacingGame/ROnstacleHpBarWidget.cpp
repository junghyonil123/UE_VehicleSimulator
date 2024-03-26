// Fill out your copyright notice in the Description page of Project Settings.


#include "ROnstacleHpBarWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

UROnstacleHpBarWidget::UROnstacleHpBarWidget(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{
	
}

void UROnstacleHpBarWidget::NativeConstruct()
{
	WidgetTemp = GetWidgetFromName(TEXT("HpBar"));
	HpProgressBar = Cast<UProgressBar>(WidgetTemp);
	ensure(HpProgressBar);
	UE_LOG(LogTemp, Warning, TEXT("Finded"));

}

void UROnstacleHpBarWidget::SetHpBarValue(float MaxHp, float CurHp)
{
	if (HpProgressBar != nullptr)
	{
		HpProgressBar->SetPercent(CurHp / MaxHp);
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("ItsNull"));
	}

	HpText->SetText(FText::FromString(FString::SanitizeFloat(CurHp)));
}

