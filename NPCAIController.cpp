// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCAIController.h"

#include "Kismet/GameplayStatics.h"


void ANPCAIController::BeginPlay()
{
    Super::BeginPlay();

}
void ANPCAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
   
    if (LineOfSightTo(PlayerPawn))
    {
        SetFocus(PlayerPawn);
        MoveToActor(PlayerPawn, AcceptanceRadius);
    }
    else
    {
        ClearFocus(EAIFocusPriority::Gameplay);
        StopMovement();
    }

}

