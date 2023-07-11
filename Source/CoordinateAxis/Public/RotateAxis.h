// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AxisBase.h"
#include "RotateAxis.generated.h"

/**
 * 
 */
UCLASS()
class COORDINATEAXIS_API ARotateAxis : public AAxisBase
{
	GENERATED_BODY()
public:
	ARotateAxis();
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	UStaticMeshComponent * AxisX = nullptr;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	UStaticMeshComponent * AxisY = nullptr;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	UStaticMeshComponent * AxisZ = nullptr;
};
