// Fill out your copyright notice in the Description page of Project Settings.

#include "Catan.h"
#include "CatanGameMode.h"
#include "Hex/HexagonTile.h"
#include <memory>
#include "Hex/BoardManager.h"


void ACatanGameMode::InitGameState()
{
    this->SpawnMap();
    //auto actor1 = GetWorld()->SpawnActor<AActor>(AHexagonTile::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator);
    //auto actor2 = GetWorld()->SpawnActor<AActor>(AHexagonTile::StaticClass(), FVector(200, 0, 0), FRotator::ZeroRotator);
}

void ACatanGameMode::SpawnMap() const
{
    std::unique_ptr<BoardManager> board(new BoardManager());
    board->SpawnMap(GetWorld());

    //const int horizDist = AHexagonTile::Width * 3 / 4;
    //const int vertDist = AHexagonTile::Height;

    //UWorld* world = GetWorld();

    //for (int i = 0; i < 5; ++i)
    //{
    //    for (int j = 0; j < 5; ++j)
    //    {
    //        world->SpawnActor<AActor>(AHexagonTile::StaticClass(), FVector(i * horizDist, j * vertDist, 0), FRotator::ZeroRotator);
    //    }
    //}
}
