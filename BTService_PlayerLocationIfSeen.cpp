// Fill out your copyright notice in the Description page of Project Settings.



#include "BTService_PlayerLocationIfSeen.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Pawn.h"
#include "AIController.h"

UBTService_PlayerLocationIfSeen::UBTService_PlayerLocationIfSeen()
{
    NodeName = "Update Player Location If Seen";
}

void UBTService_PlayerLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
    for (int i = 0; i < 10; i++) {

        APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), i);


        if (PlayerPawn == nullptr)
        {
            return;
        }

        if (OwnerComp.GetAIOwner() == nullptr)
        {
            return;
        }

        if (OwnerComp.GetAIOwner()->LineOfSightTo(PlayerPawn))
        {
            OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn);
            break;
        }
        else
        {
            OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
           
        }

    }
}
