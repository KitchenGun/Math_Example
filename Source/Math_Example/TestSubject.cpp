// Fill out your copyright notice in the Description page of Project Settings.


#include "TestSubject.h"

// Sets default values
ATestSubject::ATestSubject()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestSubject::BeginPlay()
{
	Super::BeginPlay();
	Velocity = 1;
	CurrentLocation = this->GetActorLocation();
}

// Called every frame
void ATestSubject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CurrentLocation.X += Velocity * DeltaTime;
	this->SetActorLocation(CurrentLocation);
}

// Called to bind functionality to input
void ATestSubject::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

