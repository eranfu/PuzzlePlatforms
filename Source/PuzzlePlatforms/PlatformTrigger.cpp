// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformTrigger.h"
#include "Components/BoxComponent.h"

// Sets default values
APlatformTrigger::APlatformTrigger()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;
    TriggerVolume = CreateDefaultSubobject<UBoxComponent>(FName("TriggerVolume"));
    if (!ensure(TriggerVolume != nullptr))
    {
        return;
    }
    SetRootComponent(TriggerVolume);
    TriggerVolume->OnComponentBeginOverlap.AddDynamic(this, &APlatformTrigger::OnTriggerVolumeBeginOverlap);
    TriggerVolume->OnComponentEndOverlap.AddDynamic(this, &APlatformTrigger::OnTriggerVolumeEndOverlap);
}

// Called when the game starts or when spawned
void APlatformTrigger::BeginPlay()
{
    Super::BeginPlay();
}

void APlatformTrigger::OnTriggerVolumeBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    UE_LOG(LogTemp, Warning, TEXT("Activated"));
}

void APlatformTrigger::OnTriggerVolumeEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    UE_LOG(LogTemp, Warning, TEXT("Deactivated"));
}
