// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoordinateAxisType.h"

#include "Subsystems/GameInstanceSubsystem.h"
#include "GISCoordinateAxisManager.generated.h"

enum class EAxisMoveMode : uint8;
/**
 * 
 */
UCLASS()
class COORDINATEAXIS_API UGISCoordinateAxisManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void BP_SetCurrentMoveMode(EAxisMoveMode InMode);
	
	UFUNCTION(BlueprintCallable)
	EAxisMoveMode BP_GetCurrentMoveMode();
	
private:
	EAxisMoveMode AxisMoveMode = EAxisMoveMode::EMove;
};
