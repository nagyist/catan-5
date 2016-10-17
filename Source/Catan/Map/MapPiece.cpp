// Fill out your copyright notice in the Description page of Project Settings.

#include "Catan.h"
#include "MapPiece.h"


// Sets default values
AMapPiece::AMapPiece()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;
    this->cubeCoordinates_ = FVector::ZeroVector;
}

// Called when the game starts or when spawned
void AMapPiece::BeginPlay()
{
	Super::BeginPlay();
}

void AMapPiece::SetCoordinates(const FVector& cubecoordinates)
{
    cubeCoordinates_ = cubecoordinates;
}

FVector AMapPiece::GetCoordinates() const
{
    return this->cubeCoordinates_;
}