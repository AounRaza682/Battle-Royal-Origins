// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BROGameMode.generated.h"

UCLASS(minimalapi)
class ABROGameMode : public AGameModeBase
{
	GENERATED_BODY()


public:
	virtual void PawnKilled(APawn* PawnKilled);

};



