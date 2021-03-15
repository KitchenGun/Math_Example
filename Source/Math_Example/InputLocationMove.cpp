// Fill out your copyright notice in the Description page of Project Settings.


#include "InputLocationMove.h"

// Sets default values
AInputLocationMove::AInputLocationMove()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInputLocationMove::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInputLocationMove::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CurLocation = GetActorLocation();
	
	MoveDir = NewLocation - CurLocation;
	if (CurLocation - NewLocation!=FVector().ZeroVector)//현재 근삿값에 도달하면 정지가 되지 않는다 해결 방안생각필요
	{
		UE_LOG(LogTemp, Log, TEXT("x:%f"), CurLocation.X);
		UE_LOG(LogTemp, Log, TEXT("y:%f"), CurLocation.Y);
		UE_LOG(LogTemp, Log, TEXT("z:%f"), CurLocation.Z);

		UE_LOG(LogTemp, Log, TEXT("N:%f"), MoveDir.Normalize());
		CurLocation +=  FVector().OneVector* Velocity * MoveDir * DeltaTime;  //(방향 벡터 * 속도) +현재 좌표
		SetActorLocation(CurLocation, false, 0, ETeleportType::None);
	}
}

