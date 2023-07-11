// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveAxis.h"

AMoveAxis::AMoveAxis()
{
	AxisX = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AxisX"));
	AxisX->SetupAttachment(RootComponent);
	AxisY = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AxisY"));
	AxisY->SetupAttachment(RootComponent);
	AxisZ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AxisZ"));
	AxisZ->SetupAttachment(RootComponent);

	AxisXY = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AxisXY"));
	AxisXY->SetupAttachment(RootComponent);
	AxisYZ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AxisYZ"));
	AxisYZ->SetupAttachment(RootComponent);
	AxisXZ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AxisXZ"));
	AxisXZ->SetupAttachment(RootComponent);

	AxisXYZ = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AxisXYZ"));
	AxisXYZ->SetupAttachment(RootComponent);
	
}
