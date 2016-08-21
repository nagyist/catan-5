// Fill out your copyright notice in the Description page of Project Settings.

#include "Catan.h"
#include "CatanGameMode.h"
#include <memory>
#include "Hex/HexagonTile.h"
#include "Hex/BoardManager.h"
#include "CatanPlayerController.h"


void ACatanGameMode::InitGameState()
{
    this->PlayerControllerClass = ACatanPlayerController::StaticClass();
    this->SpawnMap();
    //auto actor1 = GetWorld()->SpawnActor<AActor>(AHexagonTile::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator);
    //auto actor2 = GetWorld()->SpawnActor<AActor>(AHexagonTile::StaticClass(), FVector(200, 0, 0), FRotator::ZeroRotator);
}

void ACatanGameMode::SpawnMap() const
{
    std::unique_ptr<BoardManager> board(new BoardManager());
    board->BuildMap(GetWorld());
}
