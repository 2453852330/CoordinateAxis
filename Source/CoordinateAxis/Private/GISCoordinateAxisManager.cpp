// Fill out your copyright notice in the Description page of Project Settings.


#include "GISCoordinateAxisManager.h"

void UGISCoordinateAxisManager::BP_SetCurrentMoveMode(EAxisMoveMode InMode)
{
	AxisMoveMode = InMode;
}

EAxisMoveMode UGISCoordinateAxisManager::BP_GetCurrentMoveMode()
{
	return AxisMoveMode;
}
