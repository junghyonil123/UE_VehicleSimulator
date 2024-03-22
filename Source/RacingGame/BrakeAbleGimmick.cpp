// Fill out your copyright notice in the Description page of Project Settings.


#include "BrakeAbleGimmick.h"
#include "Components/BoxComponent.h"
#include "GeometryCollection/GeometryCollectionComponent.h"
#include "Components/WidgetComponent.h"
#include "ROnstacleHpBarWidget.h"




// Sets default values
ABrakeAbleGimmick::ABrakeAbleGimmick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//BoxComponent = GetOwner()->FindComponentByClass<UBoxComponent>();
	MaxHp = 100;
	/*Trigger = Cast<UBoxComponent>(GetOwner()->GetDefaultSubobjectByName(FName(TEXT("Box"))));*/
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	Trigger->SetBoxExtent(FVector(40.0f, 42.0f, 30.0f));
	RootComponent = Trigger;

	HPBarWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HOBARWIDGET"));
	HPBarWidget->SetupAttachment(Trigger);

	HPBarWidget->SetRelativeLocation(FVector(0.0f, 0.0f, 180.0f));
	HPBarWidget->SetWidgetSpace(EWidgetSpace::Screen);
	static ConstructorHelpers::FClassFinder<UUserWidget> UI_HUD(TEXT("/Game/UI_OnstacleHpBar.UI_OnstacleHpBar_C"));
	if (UI_HUD.Succeeded())
	{
		HPBarWidget->SetWidgetClass(UI_HUD.Class);
		HPBarWidget->SetDrawSize(FVector2D(150.0f, 50.0f));
	}


}

// Called when the game starts or when spawned 
void ABrakeAbleGimmick::BeginPlay()
{
	Super::BeginPlay();
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &ABrakeAbleGimmick::OnOverlapBegin);

	OnHpChanged.AddLambda([this]() -> void {
		UE_LOG(LogTemp, Warning, TEXT("Delegate"));
		
		auto HpBarWidgetTemp = Cast<UROnstacleHpBarWidget>(HPBarWidget->GetUserWidgetObject());

		if (HpBarWidgetTemp)
		{
			UE_LOG(LogTemp, Warning, TEXT("Set"));
			HpBarWidgetTemp->SetHpBarValue(MaxHp, CurrentHp);
		}
	});

	SetCurrentHP(MaxHp);
}

// Called every frame
void ABrakeAbleGimmick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABrakeAbleGimmick::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void ABrakeAbleGimmick::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepHitResult)
{
	SetCurrentHP(-10);
}

