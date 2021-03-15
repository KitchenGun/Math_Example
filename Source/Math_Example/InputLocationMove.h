// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputLocationMove.generated.h"

UCLASS()
class MATH_EXAMPLE_API AInputLocationMove : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInputLocationMove();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	FVector CurLocation;
	FVector MoveDir;
	UPROPERTY(EditAnywhere, Category = "Location")
		FVector NewLocation;
	UPROPERTY(EditAnywhere, Category = "Location")
	float Velocity = 100.0f;
};
