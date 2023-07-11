// Fill out your copyright notice in the Description page of Project Settings.


#include "GISCoordinateAxisManager.h"

#include "AxisBase.h"

void UGISCoordinateAxisManager::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	// Blueprint'/CoordinateAxis/BP_MoveAxis.BP_MoveAxis'
	MoveAxisClass = LoadObject<UClass>(nullptr,TEXT("Blueprint'/CoordinateAxis/BP_MoveAxis.BP_MoveAxis_C'"));
	RotateAxisClass = LoadObject<UClass>(nullptr,TEXT("Blueprint'/CoordinateAxis/BP_RotateAxis.BP_RotateAxis_C'"));
	ScaleAxisClass = LoadObject<UClass>(nullptr,TEXT("Blueprint'/CoordinateAxis/BP_ScaleAxis.BP_ScaleAxis_C'"));
	UE_LOG(LogTemp,Warning,TEXT("[GISCoordinateAxisManager.cpp:%d]:Init Class : %s | %s | %s"),__LINE__,
		MoveAxisClass?TEXT("Success"):TEXT("Failed"),RotateAxisClass?TEXT("Success"):TEXT("Failed"),ScaleAxisClass?TEXT("Success"):TEXT("Failed"));
}

void UGISCoordinateAxisManager::BP_SetCurrentMoveMode(EAxisMoveMode InMode)
{
	if (AxisMoveMode != InMode)
	{
		// set to new mode
		AxisMoveMode = InMode;
		// delete old axis actor
		if (AxisActor)
		{
			AxisActor->Destroy();
		}
		CF_SpawnAxisActorWithMoveMode(WorkMeshActor);
		if (AxisActor)
		{
			AxisActor->BindActor = WorkMeshActor;
		}
	}
}

EAxisMoveMode UGISCoordinateAxisManager::BP_GetCurrentMoveMode()
{
	return AxisMoveMode;
}


void UGISCoordinateAxisManager::BP_SetWorkMeshActor(AActor* InActor)
{
	UE_LOG(LogTemp,Warning,TEXT("[GISCoordinateAxisManager.cpp:%d]:In Mesh Actor :%s"),__LINE__,InActor?TEXT("Success"):TEXT("Failed"));
	// the InActor is the hit mesh actor which is controlled by AxisActor
	if (InActor)
	{
		/** if the new actor is same with old actor will do anything */

		/** the new actor is not same with old actor */
		if (InActor!=WorkMeshActor) 
		{
			UE_LOG(LogTemp,Warning,TEXT("[GISCoordinateAxisManager.cpp:%d]:InActor != WorkMeshActor"),__LINE__);
			if (AxisActor)
			{
				UE_LOG(LogTemp,Warning,TEXT("[GISCoordinateAxisManager.cpp:%d]:Axis Actor Valid,Change Transform"),__LINE__);
				FTransform TmpTransform = CF_GetTransformNoScale(InActor);
				AxisActor->SetActorTransform(TmpTransform);
			}
			else
			{
				UE_LOG(LogTemp,Warning,TEXT("[GISCoordinateAxisManager.cpp:%d]:Spawn New Axis Actor"),__LINE__);
				CF_SpawnAxisActorWithMoveMode(InActor);
			}
			if (AxisActor)
			{
				AxisActor->BindActor = InActor;
				WorkMeshActor = InActor;
			}
		}
	}
	else /** in actor is not valid , need to hidden/destory axis actor */
	{
		UE_LOG(LogTemp,Warning,TEXT("[GISCoordinateAxisManager.cpp:%d]:InActor Is Null, Will To Destory Axis Actor"),__LINE__);
		if (AxisActor)
		{
			AxisActor->Destroy();
			AxisActor = nullptr;
		}
		WorkMeshActor = nullptr;
	}
}

FTransform UGISCoordinateAxisManager::CF_GetTransformNoScale(AActor* InActor)
{
	FTransform TmpTransform = InActor->GetActorTransform();
	TmpTransform.SetScale3D(FVector(1.f,1.f,1.f));
	return TmpTransform;
}

void UGISCoordinateAxisManager::CF_SpawnAxisActorWithMoveMode(AActor * InActor)
{
	if (!InActor)
	{
		return;
	}
	FTransform TmpTransform = CF_GetTransformNoScale(InActor);
	FActorSpawnParameters Parameters;
	Parameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	switch (AxisMoveMode)
	{
	case EAxisMoveMode::EMove:
		{
			AxisActor = GetWorld()->SpawnActor<AAxisBase>(MoveAxisClass,TmpTransform,Parameters);
			break;
		}
	case EAxisMoveMode::ERotator:
		{
			AxisActor = GetWorld()->SpawnActor<AAxisBase>(RotateAxisClass,TmpTransform,Parameters);
			break;
		}
	case EAxisMoveMode::EScale:
		{
			AxisActor = GetWorld()->SpawnActor<AAxisBase>(ScaleAxisClass,TmpTransform,Parameters);
			break;
		}
	}
}


