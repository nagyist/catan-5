// Fill out your copyright notice in the Description page of Project Settings.

#include "Catan.h"
#include "CatanPawn.h"


// Sets default values
ACatanPawn::ACatanPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ACatanPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACatanPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ACatanPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

