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
	if (CurLocation - NewLocation!=FVector().ZeroVector)//���� �ٻ񰪿� �����ϸ� ������ ���� �ʴ´� �ذ� ��Ȼ����ʿ�
	{
		UE_LOG(LogTemp, Log, TEXT("x:%f"), CurLocation.X);
		UE_LOG(LogTemp, Log, TEXT("y:%f"), CurLocation.Y);
		UE_LOG(LogTemp, Log, TEXT("z:%f"), CurLocation.Z);

		UE_LOG(LogTemp, Log, TEXT("N:%f"), MoveDir.Normalize());
		CurLocation +=  FVector().OneVector* Velocity * MoveDir * DeltaTime;  //(���� ���� * �ӵ�) +���� ��ǥ
		SetActorLocation(CurLocation, false, 0, ETeleportType::None);
	}
}

