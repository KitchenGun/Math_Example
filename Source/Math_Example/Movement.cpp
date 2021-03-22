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

// 시작할때 호출
void AMovement::BeginPlay()
{
	Super::BeginPlay();
	//시작위치 지정
	FVector StartLocation = FVector(0.0f, 0.0f, 200.0f);
	SetActorLocation(StartLocation,false,0,ETeleportType::None);
	isGround = true;
}

// Called every frame
void AMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//중력 효과
	{
		if (!isGround)
		{//지면이 아닐경우
			if (GetActorLocation().Z <= GroundPos + 0.5f && GetActorLocation().Z >= GroundPos - 0.5f)
			{//근삿값 도달시 지면 좌표로 고정
				if (GetActorLocation().Z != GroundPos)//지면 좌표가 아닐 경우만
				{
					SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, GroundPos), false, 0, ETeleportType::None);
				}
			}
			else
			{//미도달시 계속 중력의 영향을 받도록함
				SetActorLocation(GetActorLocation() - FVector(0.0f, 0.0f, gravity), false, 0, ETeleportType::None);
			}
		}
		else
		{//지면일 경우
			if (GetActorLocation().Z > GroundPos)
			{//지면위로 올라갈 경우
				isGround = false;
			}
		}
	}


	FVector NewLocation; 
	if (inputHorizontalDir&&inputVerticalDir)//동시입력
	{
		//대각선 속도와 일반 속도의 비율을 구하여 동시 입력시 속도가 빨라지지 않도록함
		{
			double numerator = sqrt(pow(abs(MovementDirection.X), 2) + pow(abs(MovementDirection.Y), 2));
			double denominator = (abs(MovementDirection.X) + abs(MovementDirection.Y));
			double velocityRatio = (numerator / denominator);
			//확인용 속도 비율 출력
			UE_LOG(LogTemp, Log, TEXT("x:%f"), velocityRatio);
			NewLocation = (MovementDirection * velocityRatio) * DeltaTime;
			//액터의 기본위치
			NewLocation += GetActorLocation();
		}
	}
	else//한개의 축 입력
	{
		NewLocation = GetActorLocation() + (MovementDirection * DeltaTime);
	}
	SetActorLocation(NewLocation);
	MovementDirection = FVector().ZeroVector;
}

// Called to bind functionality to input
void AMovement::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("Horizontal", this, &AMovement::HorizontalMove);
	InputComponent->BindAxis("Vertical", this, &AMovement::VerticalMove);
}

//오른쪽 왼쪽 이동
void AMovement::HorizontalMove(float value)
{
	if (value != 0.0f)//입력이 들어올경우
	{
		inputHorizontalDir = true;
		MovementDirection.Y = value*HVelocity;
	}
	else//입력이 없을 경우
	{
		inputHorizontalDir = false;
	}
	
}
//앞쪽 뒤쪽 이동
void AMovement::VerticalMove(float value)
{
	if (value != 0.0f)//입력이 들어올경우
	{
		inputVerticalDir = true;
		MovementDirection.X = value * VVelocity;
	}
	else//입력이 없을 경우
	{
		inputVerticalDir = false;
	}
}
