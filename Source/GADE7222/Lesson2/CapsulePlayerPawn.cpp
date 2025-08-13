// Fill out your copyright notice in the Description page of Project Settings.


#include "Lesson2/CapsulePlayerPawn.h"

// Sets default values
ACapsulePlayerPawn::ACapsulePlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//this is instantiation =)
	SphereMeshCharacter = CreateDefaultSubobject<USphereComponent>(TEXT("Player"));
	RootComponent = SphereMeshCharacter;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoon"));
	SpringArm->SetupAttachment(SphereMeshCharacter);

	SpringArm->TargetArmLength = 500.0f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
}

// Called when the game starts or when spawned
void ACapsulePlayerPawn::BeginPlay()
{
	//intialization
	Super::BeginPlay();


	//functionality
	
}

// Called every frame
void ACapsulePlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACapsulePlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

