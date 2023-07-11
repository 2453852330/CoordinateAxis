// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AxisBase.h"
#include "ScaleAxis.generated.h"

/**
 * 
 */
UCLASS()
class COORDINATEAXIS_API AScaleAxis : public AAxisBase
{
	GENERATED_BODY()
public:
	AScaleAxis();


	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	UStaticMeshComponent * AxisX = nullptr;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	UStaticMeshComponent * AxisY = nullptr;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	UStaticMeshComponent * AxisZ = nullptr;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	UStaticMeshComponent * Center = nullptr;
};
