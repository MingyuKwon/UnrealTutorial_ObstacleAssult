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
	startPosition = GetActorLocation();
	UE_LOG(LogTemp, Display, TEXT("Distance Limit : %f"), moveLimit);
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}


void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector currentPosition = GetActorLocation();
	currentPosition += MovingVector * DeltaTime;
	float movedDistance = FVector::Distance(currentPosition, startPosition);
	SetActorLocation(currentPosition);

	if(movedDistance >= moveLimit)
	{
		UE_LOG(LogTemp, Display, TEXT("OverShoot : %f = %s"), (movedDistance - moveLimit), *GetName());
		startPosition = startPosition + MovingVector.GetSafeNormal() * moveLimit;
		SetActorLocation(startPosition);
		MovingVector = -MovingVector;
	}

}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(RotatingVelocity * DeltaTime);
}
