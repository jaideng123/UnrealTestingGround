// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a Mesh Component
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	// Attach it to our root transform component
	VisualMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();

	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime);
	NewLocation.Z += (DeltaHeight * FloatSpeed);
	NewRotation.Yaw += (DeltaTime * FloatSpeed);

	SetActorLocationAndRotation(NewLocation, NewRotation);
}
