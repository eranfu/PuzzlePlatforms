// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformTrigger.generated.h"

UCLASS()
class PUZZLEPLATFORMS_API APlatformTrigger : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    APlatformTrigger();

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
    class UBoxComponent* TriggerVolume;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

private:
    UFUNCTION()
    void OnTriggerVolumeBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

    UFUNCTION()
    void OnTriggerVolumeEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
