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
private://이동관련 변수
//입력확인용
	bool inputHorizontalDir = false;
	bool inputVerticalDir = false;
//속도
	float HVelocity = 125.0f;//수평이동속도
	float VVelocity = 150.0f;//수직이동속도
	FVector MovementDirection;//방향
//중력
	float gravity = 0.9f;
	float mass;
	float curHeightPos;
	float GroundPos = 70.0f;
	bool isGround = true;
private:
	void HorizontalMove(float value);
	void VerticalMove(float value);

};
