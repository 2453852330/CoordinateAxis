// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AxisBase.generated.h"

UCLASS()
class COORDINATEAXIS_API AAxisBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAxisBase();

	/** fake root component */
	UPROPERTY()
	USceneComponent * FakeRoot = nullptr;
	
	/** the actor which is control by axis */
	UPROPERTY(BlueprintReadWrite,meta=(ExposeOnSpawn=true))
	AActor * BindActor = nullptr;

	/** change the actor's tag */
	UFUNCTION(BlueprintCallable)
	void BP_ChangeActorTag(FName InNewTag);
};
