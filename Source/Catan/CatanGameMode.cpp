// Fill out your copyright notice in the Description page of Project Settings.

#include "Catan.h"
#include "CatanGameMode.h"
#include "HexagonTile.h"


void ACatanGameMode::InitGameState()
{
    GetWorld()->SpawnActor<AActor>(AHexagonTile::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator);
}
