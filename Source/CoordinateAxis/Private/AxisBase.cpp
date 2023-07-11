// Fill out your copyright notice in the Description page of Project Settings.


#include "AxisBase.h"

// Sets default values
AAxisBase::AAxisBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	FakeRoot = CreateDefaultSubobject<USceneComponent>(TEXT("FakeRoot"));
	RootComponent = FakeRoot;
}

void AAxisBase::BP_ChangeActorTag(FName InNewTag)
{
	if (Tags.Num())
	{
		Tags.Reset();
	}
	Tags.Emplace(InNewTag);
}
