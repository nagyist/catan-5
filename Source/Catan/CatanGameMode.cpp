// Fill out your copyright notice in the Description page of Project Settings.

#include "Catan.h"
#include <memory>
#include <chrono>
#include "CatanGameMode.h"
#include "Hex/HexagonTile.h"
#include "Hex/BoardManager.h"
#include "CatanPlayerController.h"
#include "CatanPawn.h"


void ACatanGameMode::InitGameState()
{
    this->PlayerControllerClass = ACatanPlayerController::StaticClass();
    this->DefaultPawnClass = ACatanPawn::StaticClass();
    this->SpawnMap();
}

void ACatanGameMode::SpawnMap() const
{
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::unique_ptr<BoardManager> board(new BoardManager(seed));
    board->BuildMap(GetWorld());
}
