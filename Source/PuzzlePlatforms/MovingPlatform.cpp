// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
    SetMobility(EComponentMobility::Movable);
    PrimaryActorTick.bCanEverTick = true;
}

void AMovingPlatform::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    if (HasAuthority())
    {
        FVector Location = GetActorLocation();
        const FVector TargetWorldLocation = GetTransform().TransformPosition(TargetLocation);
        const FVector MoveDirection = (TargetWorldLocation - Location).GetSafeNormal();
        Location += DeltaSeconds * Speed * MoveDirection;
        SetActorLocation(Location);
    }
}

void AMovingPlatform::BeginPlay()
{
    Super::BeginPlay();
    if (HasAuthority())
    {
        SetReplicates(true);
        SetReplicateMovement(true);
    }
}
