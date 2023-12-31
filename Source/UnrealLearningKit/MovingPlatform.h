// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class UNREALLEARNINGKIT_API AMovingPlatform : public AActor
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

private : 
	UPROPERTY(EditAnyWhere, Category = "Moving")
	FVector MovingVector = FVector(200,0,0);
	UPROPERTY(EditAnyWhere, Category = "Moving")
	float moveLimit = 100;

	UPROPERTY(EditAnyWhere, Category = "Rotating")
	FRotator RotatingVelocity;



	FVector startPosition;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
};
