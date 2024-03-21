// Fill out your copyright notice in the Description page of Project Settings.


#include "ROnstacleHpBarWidget.h"
#include "Components/ProgressBar.h"

UROnstacleHpBarWidget::UROnstacleHpBarWidget(const FObjectInitializer& ObjectInitializer): Super(ObjectInitializer)
{
}

void UROnstacleHpBarWidget::NativeConstruct()
{
	HpProgressBar = Cast<UProgressBar>(GetWidgetFromName(TEXT("HpBar")));
	ensure(HpProgressBar);
}

void UROnstacleHpBarWidget::SetHpBarValue(float MaxHp, float CurHp)
{
	if (HpProgressBar != nullptr)
	{
		HpProgressBar->SetPercent(CurHp / MaxHp);
	}
}
