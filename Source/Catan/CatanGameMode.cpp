// Fill out your copyright notice in the Description page of Project Settings.

#include "Catan.h"
#include "CatanGameMode.h"
#include "HexagonTile.h"


void ACatanGameMode::InitGameState()
{
    auto actor1 = GetWorld()->SpawnActor<AActor>(AHexagonTile::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator);
    auto actor2 = GetWorld()->SpawnActor<AActor>(AHexagonTile::StaticClass(), FVector(100, 0, 0), FRotator::ZeroRotator);
}
