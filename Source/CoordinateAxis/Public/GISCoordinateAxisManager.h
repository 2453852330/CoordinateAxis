// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoordinateAxisType.h"

#include "Subsystems/GameInstanceSubsystem.h"
#include "GISCoordinateAxisManager.generated.h"

class AAxisBase;
enum class EAxisMoveMode : uint8;
/**
 * 
 */
UCLASS()
class COORDINATEAXIS_API UGISCoordinateAxisManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable)
	void BP_SetCurrentMoveMode(EAxisMoveMode InMode);
	
	UFUNCTION(BlueprintCallable)
	EAxisMoveMode BP_GetCurrentMoveMode();

	

	UFUNCTION(BlueprintCallable)
	void BP_SetWorkMeshActor(AActor * InActor);

	FTransform CF_GetTransformNoScale(AActor * InActor);
	void CF_SpawnAxisActorWithMoveMode(AActor * InActor);

	UPROPERTY(BlueprintReadWrite)
	bool bIsHandleMove = false;
	
private:
	
	UPROPERTY()
	AActor * WorkMeshActor = nullptr;
	
	UPROPERTY()
	AAxisBase * AxisActor = nullptr;
	
	
	EAxisMoveMode AxisMoveMode = EAxisMoveMode::EMove;

	UPROPERTY()
	UClass * MoveAxisClass = nullptr;
	UPROPERTY()
	UClass * RotateAxisClass = nullptr;
	UPROPERTY()
	UClass * ScaleAxisClass = nullptr;
};
