// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class RUNTOTHESTRANGEDOOR_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, Category= "Variable", meta = (AllowPrivateAccess = "true"))
	int32 platformNum = 0;

	UPROPERTY(EditAnywhere, Category= "Variable", meta = (AllowPrivateAccess = "true"))
	FVector platformSpeed = FVector(0,0,0);

	UPROPERTY(EditAnywhere, Category= "Variable", meta = (AllowPrivateAccess = "true"))
	float distance = 200.f;

	UPROPERTY(editAnywhere, Category= "Variable", meta = (AllowPrivateAccess = "true"))
	FRotator rotationSpeed = FRotator(0,0,0);

	UPROPERTY(editAnywhere, Category= "Variable", meta = (AllowPrivateAccess = "true"))
	bool is_Move = false;

	UPROPERTY(editAnywhere, Category= "Variable", meta = (AllowPrivateAccess = "true"))
	bool is_Rotation = false;

	UPROPERTY(editAnywhere, Category= "Variable", meta = (AllowPrivateAccess = "true"))
	bool is_BlockRotation = false;

	UPROPERTY(editAnywhere, Category= "BlockDelay", meta = (AllowPrivateAccess = "true"))
	FRotator BlockRotationDirection = FRotator(0,0,0);

	UPROPERTY(editAnywhere, Category= "BlockDelay", meta = (AllowPrivateAccess = "true"))
	float BlockRoationTime = 1;
	

	
	FVector StartLocation = FVector(0,0,0);
	float Time = 0;
	float BlockDelayTime = 0;
	float BlockMovingTime = 0;
	float BlockRotationSpeed = 0;
	FRotator BlockStartRotation = FRotator(0,0,0);


	void MovingPlatform(float Deltatime);

	void RotationPlatform(float Deltatime);

	void BlockDelayRotation(float Deltatime);

};
