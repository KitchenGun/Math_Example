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
	

	if (MoveDir!=FVector().ZeroVector)//���� �ٻ񰪿� �����ϸ� ������ ���� �ʴ´� �ذ� ��Ȼ����ʿ�
	{
		//�ٻ� ���޽� ����
		{
			if (CurLocation != NewLocation)
			{
				if (CurLocation.X <= NewLocation.X + 0.5f && CurLocation.X >= NewLocation.X - 0.5f)
				{
					UE_LOG(LogTemp, Log, TEXT("x pass"));
					if (CurLocation.Y <= NewLocation.Y + 0.5f && CurLocation.Y >= NewLocation.Y - 0.5f)
					{
						UE_LOG(LogTemp, Log, TEXT("y pass"));
						if (CurLocation.Z <= NewLocation.Z + 0.5f && CurLocation.Z >= NewLocation.Z - 0.5f)
						{
							UE_LOG(LogTemp, Log, TEXT("z pass"));
							SetActorLocation(NewLocation, false, 0, ETeleportType::None);
						}
					}
				}
			}
		}
		
		CurLocation +=  FVector().OneVector* Velocity * MoveDir * DeltaTime;  //(���� ���� * �ӵ�) +���� ��ǥ

		SetActorLocation(CurLocation, false, 0, ETeleportType::None);
	}
}

