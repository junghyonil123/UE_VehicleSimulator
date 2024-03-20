// Fill out your copyright notice in the Description page of Project Settings.


#include "BrakeAbleGimmick.h"
#include "Components/BoxComponent.h"
#include "GeometryCollection/GeometryCollectionComponent.h"

// Sets default values
ABrakeAbleGimmick::ABrakeAbleGimmick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//BoxComponent = GetOwner()->FindComponentByClass<UBoxComponent>();
	MaxHp = 100;
	CurrentHp = MaxHp;
	/*Trigger = Cast<UBoxComponent>(GetOwner()->GetDefaultSubobjectByName(FName(TEXT("Box"))));*/
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	Trigger->SetBoxExtent(FVector(40.0f, 42.0f, 30.0f));
	RootComponent = Trigger;
}

// Called when the game starts or when spawned 
void ABrakeAbleGimmick::BeginPlay()
{
	Super::BeginPlay();
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &ABrakeAbleGimmick::OnOverlapBegin);
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
	CurrentHp -= 10;
}

