// Fill out your copyright notice in the Description page of Project Settings.


#include "RotateAxis.h"

ARotateAxis::ARotateAxis()
{
	AxisX = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AxisX"));
	AxisX->SetupAttachment(RootComponent);
	AxisY = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AxisY"));
	AxisY->SetupAttachment(RootComponent);
	AxisZ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AxisZ"));
	AxisZ->SetupAttachment(RootComponent);
}
