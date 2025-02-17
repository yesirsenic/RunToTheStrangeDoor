// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	BlockStartRotation = GetActorRotation();
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (is_Move)
	{
		MovingPlatform(DeltaTime);
	}

	if (is_Rotation)
	{
		RotationPlatform(DeltaTime);
	}

	if (is_BlockRotation)
	{
		BlockDelayRotation(DeltaTime);
	}
		
	

}

void AMovingPlatform::MovingPlatform(float Deltatime)
{
	FVector CurrentLocation = GetActorLocation();
	FVector NextLocation = CurrentLocation + platformSpeed * Deltatime;
	Time += Deltatime;

	SetActorLocation(NextLocation);

	if (FVector::Dist(StartLocation, NextLocation) > distance)
	{
		StartLocation += platformSpeed * Time;
		platformSpeed *= -1;
		Time = 0;
	}

}

void AMovingPlatform::RotationPlatform(float Deltatime)
{
	AddActorLocalRotation(rotationSpeed * Deltatime);
}

void AMovingPlatform::BlockDelayRotation(float Deltatime)
{
	BlockDelayTime +=Deltatime;
	

	if (BlockDelayTime >= 1.f)
	{
		BlockRotationSpeed = 90 / BlockRoationTime;

		AddActorLocalRotation(BlockRotationDirection * BlockRotationSpeed * Deltatime);

		BlockMovingTime +=Deltatime;

		if (BlockMovingTime >= BlockRoationTime)
		{
			SetActorRotation(BlockStartRotation + BlockRotationDirection * 90);
			BlockStartRotation = GetActorRotation();
			BlockDelayTime = 0;
			BlockMovingTime = 0;
		}
		
		
	}
}




