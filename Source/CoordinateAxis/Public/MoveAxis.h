// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AxisBase.h"
#include "MoveAxis.generated.h"

/**
 * 
 */
UCLASS()
class COORDINATEAXIS_API AMoveAxis : public AAxisBase
{
	GENERATED_BODY()

public:
	AMoveAxis();
	
	UPROPERTY()
	USceneComponent * FakeRoot = nullptr;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	UStaticMeshComponent * AxisX = nullptr;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	UStaticMeshComponent * AxisY = nullptr;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	UStaticMeshComponent * AxisZ = nullptr;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	UStaticMeshComponent * AxisXY = nullptr;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	UStaticMeshComponent * AxisXZ = nullptr;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	UStaticMeshComponent * AxisYZ = nullptr;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	UStaticMeshComponent * AxisXYZ = nullptr;

};
