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
        const float JourneyLengthSquared = (TargetWorldLocation - StartWorldLocation).SizeSquared();
        const float JourneyTraveledSquared = (Location - StartWorldLocation).SizeSquared();

        if (JourneyTraveledSquared >= JourneyLengthSquared)
        {
            const FVector SwapTemp = StartWorldLocation;
            StartWorldLocation = TargetWorldLocation;
            TargetWorldLocation = SwapTemp;
        }

        const FVector MoveDirection = (TargetWorldLocation - StartWorldLocation).GetSafeNormal();
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

    TargetWorldLocation = GetTransform().TransformPosition(TargetLocation);
    StartWorldLocation = GetActorLocation();
}
