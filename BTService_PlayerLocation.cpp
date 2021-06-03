// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_PlayerLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "AIController.h"

UBTService_PlayerLocation::UBTService_PlayerLocation()
{
    NodeName = "Update Player Location";
}

void UBTService_PlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    for (int i = 0; i < 10; i++) {
        APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), i);
        if (PlayerPawn == nullptr)
        {
            return;
        }
        if (OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn)) {
         
            OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPawn->GetActorLocation());
            break;
        }
       
      //  if (OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn))
      //  {
        //    OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPawn->GetActorLocation);
        //    break;
      //  }
       
    }
}

