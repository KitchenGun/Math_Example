// Fill out your copyright notice in the Description page of Project Settings.


#include "Movement.h"

// Sets default values
AMovement::AMovement()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//어떤 캐릭터인지 확인용
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AMovement::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	const FVector NewLocation = GetActorLocation() + (MovementDirection * DeltaTime);
	SetActorLocation(NewLocation);
	
}

// Called to bind functionality to input
void AMovement::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("Horizontal", this, &AMovement::HorizontalMove);
	InputComponent->BindAxis("Vertical", this, &AMovement::VerticalMove);
}

void AMovement::HorizontalMove(float value)
{
	if (value != 0.0f)
	{
		UE_LOG(LogTemp, Log, TEXT("h%f"), value);
		MovementDirection.Y = value*HVelocity;
	}
	else
	{
		MovementDirection = FVector().ZeroVector;
	}
}

void AMovement::VerticalMove(float value)
{
	if (value != 0.0f)
	{
		UE_LOG(LogTemp, Log, TEXT("v%f"), value);
		MovementDirection.X = value * VVelocity;
	}
	else
	{
		MovementDirection = FVector().ZeroVector;
	}
}
