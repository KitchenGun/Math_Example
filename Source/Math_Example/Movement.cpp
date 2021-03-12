// Fill out your copyright notice in the Description page of Project Settings.


#include "Movement.h"

// Sets default values
AMovement::AMovement()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//� ĳ�������� Ȯ�ο�
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
	FVector NewLocation; 
	if (inputHorizontalDir&&inputVerticalDir)//�����Է�
	{
		//�밢�� �ӵ��� �Ϲ� �ӵ��� ������ ���Ͽ� ���� �Է½� �ӵ��� �������� �ʵ�����
		{
			double numerator = sqrt(pow(abs(MovementDirection.X), 2) + pow(abs(MovementDirection.Y), 2));
			double denominator = (abs(MovementDirection.X) + abs(MovementDirection.Y));
			double velocityRatio = (numerator / denominator);
			//Ȯ�ο� �ӵ� ���� ���
			UE_LOG(LogTemp, Log, TEXT("x:%f"), velocityRatio);
			NewLocation = (MovementDirection * velocityRatio) * DeltaTime;
			//������ �⺻��ġ
			NewLocation += GetActorLocation();
		}
	}
	else//�Ѱ��� �� �Է�
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

//������ ���� �̵�
void AMovement::HorizontalMove(float value)
{
	if (value != 0.0f)//�Է��� ���ð��
	{
		inputHorizontalDir = true;
		MovementDirection.Y = value*HVelocity;
	}
	else//�Է��� ���� ���
	{
		inputHorizontalDir = false;
	}
	
}
//���� ���� �̵�
void AMovement::VerticalMove(float value)
{
	if (value != 0.0f)//�Է��� ���ð��
	{
		inputVerticalDir = true;
		MovementDirection.X = value * VVelocity;
	}
	else//�Է��� ���� ���
	{
		inputVerticalDir = false;
	}
}
