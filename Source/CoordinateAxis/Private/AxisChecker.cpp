// Fill out your copyright notice in the Description page of Project Settings.


#include "AxisChecker.h"

// Sets default values
AAxisChecker::AAxisChecker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AAxisChecker::BeginPlay()
{
	Super::BeginPlay();
	PC = GetWorld()->GetFirstPlayerController();
	EnableInput(PC);
}


