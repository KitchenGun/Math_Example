// Fill out your copyright notice in the Description page of Project Settings.


#include "SetActorLocationandRotation.h"

// Sets default values
ASetActorLocationandRotation::ASetActorLocationandRotation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASetActorLocationandRotation::BeginPlay()
{
	Super::BeginPlay();
	
	NewLocation = FVector(0.0f, 0.0f, 70.0f);
	SetActorLocationAndRotation(NewLocation, NewRotation, false, 0, ETeleportType::None);
}

// Called every frame
void ASetActorLocationandRotation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	NewLocation += FVector(Velocity, 0.0f, 0.0f)*DeltaTime;
	SetActorLocationAndRotation(NewLocation, NewRotation, false, 0, ETeleportType::None);
}

