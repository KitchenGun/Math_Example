// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/InputComponent.h"
#include "GameFramework/Pawn.h"
#include "Movement.generated.h"

UCLASS()
class MATH_EXAMPLE_API AMovement : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMovement();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	
	bool inputHorizontalDir = false;
	float HVelocity = 100.0f;//수평이동속도
	float VVelocity = 150.0f;//수직이동속도
	FVector MovementDirection;//방향

private:
	void HorizontalMove(float value);
	void VerticalMove(float value);

};
