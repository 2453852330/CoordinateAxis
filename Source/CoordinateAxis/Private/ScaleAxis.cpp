// Fill out your copyright notice in the Description page of Project Settings.


#include "ScaleAxis.h"

AScaleAxis::AScaleAxis()
{
	AxisX = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AxisX"));
	AxisX->SetupAttachment(RootComponent);
	AxisY = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AxisY"));
	AxisY->SetupAttachment(RootComponent);
	AxisZ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AxisZ"));
	AxisZ->SetupAttachment(RootComponent);

	Center = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Center"));
	Center->SetupAttachment(RootComponent);
}
