// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AxisChecker.generated.h"

class UGISCoordinateAxisManager;

UCLASS()
class COORDINATEAXIS_API AAxisChecker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAxisChecker();

	virtual void BeginPlay() override;
	
	UPROPERTY(BlueprintReadWrite)
	APlayerController * PC = nullptr;
};
